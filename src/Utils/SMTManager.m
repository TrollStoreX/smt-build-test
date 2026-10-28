#import "SMTManager.h"
#import "../Views/SMTTouchView.h"
#import <SMTUserDefaults/SMTUserDefaults.h>
#import <Private/RPScreenRecorder.h>
#import <objc/runtime.h>
#import <dlfcn.h>

#define kTouchViewKey @selector(ShowMyTouches_TouchView)

@implementation SMTManager

#pragma mark - Screen recording state
// 改动说明：
// RPScreenRecorder 是 ReplayKit 的私有类，SpringBoard 里根本没加载 ReplayKit，
// 而 [RPScreenRecorder sharedRecorder] 在编译期是按类名直接发消息（引用
// OBJC_CLASS_$_RPScreenRecorder），绑成 nil 后 [nil isRecording] 恒为 NO，
// 于是「仅录屏显示」打开后触摸点永远不显示。
// 现在改为：先按名字查类 -> 查不到再 dlopen ReplayKit -> 再查一次；
// 同时在 iOS 17+ 用公开 API UIScreen.isCaptured 作为主判据。

+ (Class)smt_rpScreenRecorderClass {
    static Class recorderClass;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        recorderClass = objc_getClass("RPScreenRecorder");
        if (recorderClass) return;

        void *handle = dlopen("/System/Library/Frameworks/ReplayKit.framework/ReplayKit", RTLD_LAZY | RTLD_NOLOAD);
        if (!handle) handle = dlopen("@rpath/ReplayKit.framework/ReplayKit", RTLD_LAZY);
        if (!handle) handle = dlopen("/System/Library/Frameworks/ReplayKit.framework/ReplayKit", RTLD_LAZY);
        if (handle) recorderClass = objc_getClass("RPScreenRecorder");
    });
    return recorderClass;
}

+ (BOOL)smt_isReplayKitRecording {
    Class recorderClass = [self smt_rpScreenRecorderClass];
    if (!recorderClass) return NO;

    id recorder = [recorderClass performSelector:@selector(sharedRecorder)];
    if (!recorder) return NO;

    SEL isRecording = @selector(isRecording);
    if (![recorder respondsToSelector:isRecording]) return NO;

    BOOL (*fn)(id, SEL) = (BOOL (*)(id, SEL))objc_msgSend;
    return fn(recorder, isRecording);
}

+ (BOOL)isRecording {
    // iOS 17+ 有公开的 UIScreen.isCaptured（录制一开始就为 YES）。
    // 必须在主线程读，sendEvent: 本身就在主线程。
    if ([UIScreen instancesRespondToSelector:@selector(isCaptured)]) {
        if ([UIScreen mainScreen].isCaptured) return YES;
    }
    return [self smt_isReplayKitRecording];
}

#pragma mark - Touches

+ (BOOL)shouldShowTouches {
    SMTUserDefaults *defaults = [SMTUserDefaults standardUserDefaults];
    if (!defaults.enabled) return NO;

    return !defaults.onlyWhileRecording || [self isRecording];
}

+ (void)showTouch:(UITouch *)touch {
    SMTTouchView *touchView = [[SMTTouchView alloc] initWithCenter:[touch locationInView:nil]];
    [touch.window addSubview:touchView];

    objc_setAssociatedObject(touch, kTouchViewKey, touchView, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

+ (void)moveTouch:(UITouch *)touch withEvent:(UIEvent *)event {
    SMTTouchView *touchView = objc_getAssociatedObject(touch, kTouchViewKey);
    if (!touchView) return;

    NSArray<UITouch *> *samples = [event coalescedTouchesForTouch:touch] ?: [NSArray arrayWithObject:touch];
    for (UITouch *sample in samples) {
        [touchView moveToPoint:[sample locationInView:nil]];
    }
}

+ (void)removeTouch:(UITouch *)touch {
    SMTTouchView *touchView = objc_getAssociatedObject(touch, kTouchViewKey);
    objc_setAssociatedObject(touch, kTouchViewKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

    [touchView dismiss];
}

@end
