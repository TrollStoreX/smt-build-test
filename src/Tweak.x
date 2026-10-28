#import <UIKit/UIKit.h>
#import "Utils/SMTManager.h"

#if SIDELOADING
#import "Utils/SMTSettingsTrigger.h"
#endif

// 说明：这里用 %hook 生成一个 UIApplication 的子类，
// 再由 __smt_hook_register 把 sendEvent: 换成本类的实现。
// 这样就不再依赖 Logos 预处理器（本机没有 Theos，只有 clang）。

%hook(UIApplication)
- (void)sendEvent:(UIEvent *)event {
    %orig;

#if SIDELOADING
    [SMTSettingsTrigger handleEvent:event];
#endif

    if (event.type != UIEventTypeTouches || !SMTManager.shouldShowTouches) {
        return;
    }

    for (UITouch *touch in [event allTouches]) {
        switch (touch.phase) {
            case UITouchPhaseBegan:
                [SMTManager showTouch:touch];
                break;
            case UITouchPhaseMoved:
                [SMTManager moveTouch:touch withEvent:event];
                break;
            case UITouchPhaseEnded:
            case UITouchPhaseCancelled:
                [SMTManager removeTouch:touch];
                break;
            default:
                break;
        }
    }
}
%end

// %orig 在不需要转发原实现之外的场合下必须真的调用一次原实现；
// 上面 %orig 展开成 MSHookMessageEx 记录下来的原 IMP 调用。
