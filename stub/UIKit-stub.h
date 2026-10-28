#ifndef SMT_STUB_UIKIT_H
#define SMT_STUB_UIKIT_H
#import "Foundation.h"

@class UIWindow, UIView, UIViewController, UIEvent, UITouch, UIColor, UIImage, UIFont, UIScreen, UIWindowScene, UIScene, UIGestureRecognizer, UIResponder, UIAction, UIBarButtonItem, UINavigationController, UINavigationBar, UIVisualEffectView, UIBlurEffect, UIGraphicsImageRenderer, CAAnimation, CALayer, CAMediaTimingFunction;

typedef struct { CGFloat r, g, b, a; } SMTStubColorComponents;

typedef NS_ENUM(NSInteger, UIEventType) {
    UIEventTypeTouches = 0,
    UIEventTypeMotion = 1,
    UIEventTypeRemoteControl = 2,
    UIEventTypePresses = 3,
    UIEventTypeScroll = 10,
    UIEventTypeHover = 11,
    UIEventTypeTransform = 14,
};
typedef NS_ENUM(NSInteger, UIEventSubtype) {
    UIEventSubtypeNone = 0,
    UIEventSubtypeMotionShake = 1,
};
typedef NS_ENUM(NSInteger, UITouchPhase) {
    UITouchPhaseBegan = 0,
    UITouchPhaseMoved = 1,
    UITouchPhaseStationary = 2,
    UITouchPhaseEnded = 3,
    UITouchPhaseCancelled = 4,
    UITouchPhaseRegionEntered = 5,
    UITouchPhaseRegionMoved = 6,
    UITouchPhaseRegionExited = 7,
};
typedef NS_ENUM(NSInteger, UITouchType) {
    UITouchTypeDirect = 0,
    UITouchTypeIndirect = 1,
    UITouchTypePencil = 2,
    UITouchTypeStylus = 2,
    UITouchTypeIndirectPointer = 3,
};
typedef NS_ENUM(NSInteger, UIStatusBarStyle) { UIStatusBarStyleDefault = 0, UIStatusBarStyleLightContent = 1 };
typedef NS_ENUM(NSInteger, UIViewContentMode) {
    UIViewContentModeScaleToFill = 0,
    UIViewContentModeScaleAspectFit = 1,
    UIViewContentModeScaleAspectFill = 2,
    UIViewContentModeRedraw = 3,
    UIViewContentModeCenter = 4,
    UIViewContentModeTop = 5,
    UIViewContentModeBottom = 6,
    UIViewContentModeLeft = 7,
    UIViewContentModeRight = 8,
    UIViewContentModeTopLeft = 9,
    UIViewContentModeTopRight = 10,
    UIViewContentModeBottomLeft = 11,
    UIViewContentModeBottomRight = 12,
};
typedef NS_ENUM(NSInteger, UIViewAnimationCurve) { UIViewAnimationCurveEaseInOut = 0, UIViewAnimationCurveEaseIn = 1, UIViewAnimationCurveEaseOut = 2, UIViewAnimationCurveLinear = 3 };
typedef NS_ENUM(NSInteger, UIViewAnimationOptions) {
    UIViewAnimationOptionLayoutSubviews = 1 << 0,
    UIViewAnimationOptionAllowUserInteraction = 1 << 1,
    UIViewAnimationOptionBeginFromCurrentState = 1 << 2,
    UIViewAnimationOptionRepeat = 1 << 3,
    UIViewAnimationOptionAutoreverse = 1 << 4,
    UIViewAnimationOptionOverrideInheritedDuration = 1 << 5,
    UIViewAnimationOptionOverrideInheritedCurve = 1 << 6,
    UIViewAnimationOptionAllowAnimatedContent = 1 << 7,
    UIViewAnimationOptionShowHideTransitionViews = 1 << 8,
    UIViewAnimationOptionCurveEaseInOut = 0 << 16,
    UIViewAnimationOptionCurveEaseIn = 1 << 16,
    UIViewAnimationOptionCurveEaseOut = 2 << 16,
    UIViewAnimationOptionCurveLinear = 3 << 16,
};
typedef NS_OPTIONS(NSUInteger, UIViewAnimationTransition) { UIViewAnimationTransitionNone = 0 };
typedef NS_ENUM(NSInteger, UIImageOrientation) { UIImageOrientationUp = 0 };
typedef NS_ENUM(NSInteger, UIBarButtonSystemItem) {
    UIBarButtonSystemItemDone = 0, UIBarButtonSystemItemCancel = 1, UIBarButtonSystemItemEdit = 2,
    UIBarButtonSystemItemSave = 3, UIBarButtonSystemItemAdd = 4, UIBarButtonSystemItemFlexibleSpace = 5,
    UIBarButtonSystemItemFixedSpace = 6, UIBarButtonSystemItemCompose = 7, UIBarButtonSystemItemReply = 8,
    UIBarButtonSystemItemAction = 9, UIBarButtonSystemItemOrganize = 10, UIBarButtonSystemItemBookmarks = 11,
    UIBarButtonSystemItemSearch = 12, UIBarButtonSystemItemRefresh = 13, UIBarButtonSystemItemStop = 14,
    UIBarButtonSystemItemCamera = 15, UIBarButtonSystemItemTrash = 16, UIBarButtonSystemItemPlay = 17,
    UIBarButtonSystemItemPause = 18, UIBarButtonSystemItemRewind = 19, UIBarButtonSystemItemFastForward = 20,
    UIBarButtonSystemItemUndo = 21, UIBarButtonSystemItemRedo = 22, UIBarButtonSystemItemPageCurl = 23,
    UIBarButtonSystemItemClose = 24,
};
typedef NS_ENUM(NSInteger, UIModalPresentationStyle) {
    UIModalPresentationFullScreen = 0, UIModalPresentationPageSheet = 1, UIModalPresentationFormSheet = 2,
    UIModalPresentationCurrentContext = 3, UIModalPresentationCustom = 4, UIModalPresentationOverFullScreen = 5,
    UIModalPresentationOverCurrentContext = 6, UIModalPresentationPopover = 7, UIModalPresentationNone = -1,
    UIModalPresentationAutomatic = -2,
};
typedef NS_ENUM(NSInteger, UIModalTransitionStyle) { UIModalTransitionStyleCoverVertical = 0 };
typedef NS_ENUM(NSInteger, UIAccessibilityTraits) { UIAccessibilityTraitNone = 0 };
typedef NS_ENUM(NSInteger, UILayoutConstraintAxis) { UILayoutConstraintAxisHorizontal = 0, UILayoutConstraintAxisVertical = 1 };
typedef NS_ENUM(NSInteger, UIUserInterfaceStyle) { UIUserInterfaceStyleUnspecified = 0, UIUserInterfaceStyleLight = 1, UIUserInterfaceStyleDark = 2 };
typedef NS_ENUM(NSInteger, UIStackViewAlignment) { UIStackViewAlignmentFill = 0, UIStackViewAlignmentLeading = 1, UIStackViewAlignmentTop = 1, UIStackViewAlignmentCenter = 3, UIStackViewAlignmentTrailing = 4, UIStackViewAlignmentBottom = 4 };
typedef NS_ENUM(NSInteger, UIStackViewDistribution) { UIStackViewDistributionFill = 0, UIStackViewDistributionFillEqually = 1, UIStackViewDistributionFillProportionally = 2, UIStackViewDistributionEqualSpacing = 3, UIStackViewDistributionEqualCentering = 4 };
typedef NS_ENUM(NSInteger, UIControlEvents) {
    UIControlEventTouchDown = 1 << 0, UIControlEventTouchDownRepeat = 1 << 1, UIControlEventTouchDragInside = 1 << 2,
    UIControlEventTouchDragOutside = 1 << 3, UIControlEventTouchDragEnter = 1 << 4, UIControlEventTouchDragExit = 1 << 5,
    UIControlEventTouchUpInside = 1 << 6, UIControlEventTouchUpOutside = 1 << 7, UIControlEventTouchCancel = 1 << 8,
    UIControlEventValueChanged = 1 << 12, UIControlEventEditingDidBegin = 1 << 16, UIControlEventEditingChanged = 1 << 17,
    UIControlEventEditingDidEnd = 1 << 18, UIControlEventEditingDidEndOnExit = 1 << 19, UIControlEventPrimaryActionTriggered = 1 << 13,
};
typedef NS_ENUM(NSInteger, UIControlState) { UIControlStateNormal = 0, UIControlStateHighlighted = 1 << 0, UIControlStateDisabled = 1 << 1, UIControlStateSelected = 1 << 2 };
typedef NS_ENUM(NSInteger, UIScrollViewContentInsetAdjustmentBehavior) { UIScrollViewContentInsetAdjustmentAutomatic = 0 };
typedef NS_ENUM(NSInteger, UIListContentTextAlignment) { UIListContentTextAlignmentNatural = 0, UIListContentTextAlignmentCenter = 1, UIListContentTextAlignmentJustified = 2 };
typedef NS_ENUM(NSInteger, UITableViewStyle) { UITableViewStylePlain = 0, UITableViewStyleGrouped = 1, UITableViewStyleInsetGrouped = 2 };
typedef NS_ENUM(NSInteger, UIMenuOptions) { UIMenuOptionsDisplayInline = 1 << 0, UIMenuOptionsDestructive = 1 << 1 };
typedef CGFloat UIFontWeight;
#define UIFontWeightUltraLight -0.8
#define UIFontWeightThin -0.6
#define UIFontWeightLight -0.4
#define UIFontWeightRegular 0
#define UIFontWeightMedium 0.23
#define UIFontWeightSemibold 0.3
#define UIFontWeightBold 0.4
#define UIFontWeightHeavy 0.56
#define UIFontWeightBlack 0.62

typedef NS_ENUM(NSInteger, UIFontTextStyle) { UIFontTextStyleBody = 0, UIFontTextStyleHeadline = 1, UIFontTextStyleSubheadline = 2, UIFontTextStyleFootnote = 3, UIFontTextStyleCaption1 = 4, UIFontTextStyleCaption2 = 5, UIFontTextStyleTitle1 = 6, UIFontTextStyleTitle2 = 7, UIFontTextStyleTitle3 = 8, UIFontTextStyleLargeTitle = 9, UIFontTextStyleCallout = 10 };
typedef NS_ENUM(NSInteger, UIGestureRecognizerState) { UIGestureRecognizerStatePossible = 0, UIGestureRecognizerStateBegan = 1, UIGestureRecognizerStateChanged = 2, UIGestureRecognizerStateEnded = 3, UIGestureRecognizerStateCancelled = 4, UIGestureRecognizerStateFailed = 5, UIGestureRecognizerStateRecognized = 3 };
typedef NS_ENUM(NSInteger, UIImagePickerControllerSourceType) { UIImagePickerControllerSourceTypePhotoLibrary = 0, UIImagePickerControllerSourceTypeCamera = 1, UIImagePickerControllerSourceTypeSavedPhotosAlbum = 2 };
typedef NS_ENUM(NSInteger, UIActivityIndicatorViewStyle) { UIActivityIndicatorViewStyleMedium = 100, UIActivityIndicatorViewStyleLarge = 101 };
typedef NS_ENUM(NSInteger, UIGraphicsImageRendererFormatRange) { UIGraphicsImageRendererFormatRangeUnspecified = -1, UIGraphicsImageRendererFormatRangeAutomatic = 0, UIGraphicsImageRendererFormatRangeExtended = 1, UIGraphicsImageRendererFormatRangeStandard = 2 };
typedef NS_ENUM(NSInteger, UISheetPresentationControllerDetentResolutionContext) { UISheetPresentationControllerDetentResolutionNone = 0 };
typedef NS_ENUM(NSInteger, UIDeviceOrientation) { UIDeviceOrientationPortrait = 1 };
typedef NS_ENUM(NSInteger, UIScrollViewIndicatorStyle) { UIScrollViewIndicatorStyleDefault = 0 };
typedef NS_ENUM(NSInteger, UITableViewRowAnimation) { UITableViewRowAnimationFade = 0, UITableViewRowAnimationAutomatic = 100 };
typedef NS_ENUM(NSInteger, UISwipeGestureRecognizerDirection) { UISwipeGestureRecognizerDirectionRight = 1 << 0, UISwipeGestureRecognizerDirectionLeft = 1 << 1, UISwipeGestureRecognizerDirectionUp = 1 << 2, UISwipeGestureRecognizerDirectionDown = 1 << 3 };
typedef NS_ENUM(NSInteger, UIEditMenuArrowDirection) { UIEditMenuArrowDirectionDown = 0 };
typedef NS_ENUM(NSInteger, UIUserInterfaceIdiom) { UIUserInterfaceIdiomUnspecified = -1, UIUserInterfaceIdiomPhone = 0, UIUserInterfaceIdiomPad = 1 };
typedef NS_ENUM(NSInteger, UIContentSizeCategory) { UIContentSizeCategoryLarge = 0 };

typedef NS_OPTIONS(NSUInteger, UIRectCorner) { UIRectCornerTopLeft = 1 << 0, UIRectCornerTopRight = 1 << 1, UIRectCornerBottomLeft = 1 << 2, UIRectCornerBottomRight = 1 << 3, UIRectCornerAllCorners = ~0UL };
typedef NS_OPTIONS(NSUInteger, UIViewKeyframeAnimationOptions) { UIViewKeyframeAnimationOptionLayoutSubviews = 1 << 0, UIViewKeyframeAnimationOptionAllowUserInteraction = 1 << 1, UIViewKeyframeAnimationOptionBeginFromCurrentState = 1 << 2, UIViewKeyframeAnimationOptionCalculationModeLinear = 0 << 10, UIViewKeyframeAnimationOptionCalculationModeCubic = 3 << 10, UIViewKeyframeAnimationOptionAllowAnimatedContent = 1 << 7 };
typedef NS_OPTIONS(NSUInteger, UIImagePickerControllerEditing) { UIImagePickerControllerSourceTypeSavedPhotosAlbumStub = 0 };
typedef NS_ENUM(NSInteger, UIAlertControllerStyle) { UIAlertControllerStyleActionSheet = 0, UIAlertControllerStyleAlert = 1 };

@interface NSColor : NSObject
@end

@protocol UIColorProtocol <NSObject>
@end

@interface UIColor : NSObject
+ (UIColor *)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a;
+ (UIColor *)colorWithWhite:(CGFloat)w alpha:(CGFloat)a;
+ (UIColor *)colorWithHexString:(NSString *)hex;
+ (UIColor *)colorNamed:(NSString *)name;
+ (UIColor *)colorWithDynamicProvider:(UIColor *(^)(id))provider;
+ (UIColor *)systemRedColor;
+ (UIColor *)systemBlueColor;
+ (UIColor *)systemGreenColor;
+ (UIColor *)systemOrangeColor;
+ (UIColor *)systemYellowColor;
+ (UIColor *)systemTealColor;
+ (UIColor *)systemGrayColor;
+ (UIColor *)systemPinkColor;
+ (UIColor *)systemPurpleColor;
+ (UIColor *)systemIndigoColor;
+ (UIColor *)labelColor;
+ (UIColor *)secondaryLabelColor;
+ (UIColor *)tertiaryLabelColor;
+ (UIColor *)quaternaryLabelColor;
+ (UIColor *)systemBackgroundColor;
+ (UIColor *)secondarySystemBackgroundColor;
+ (UIColor *)tertiarySystemBackgroundColor;
+ (UIColor *)systemGroupedBackgroundColor;
+ (UIColor *)secondarySystemGroupedBackgroundColor;
+ (UIColor *)tertiarySystemGroupedBackgroundColor;
+ (UIColor *)separatorColor;
+ (UIColor *)opaqueSeparatorColor;
+ (UIColor *)systemFillColor;
+ (UIColor *)tintColor;
+ (UIColor *)clearColor;
+ (UIColor *)whiteColor;
+ (UIColor *)blackColor;
+ (UIColor *)grayColor;
+ (UIColor *)redColor;
+ (UIColor *)blueColor;
+ (UIColor *)greenColor;
- (UIColor *)colorWithAlphaComponent:(CGFloat)a;
- (void)getRed:(CGFloat *)r green:(CGFloat *)g blue:(CGFloat *)b alpha:(CGFloat *)a;
- (void)setFill;
- (void)setStroke;
- (void)set;
@property (readonly) CGColorRef CGColor;
@end

@interface UIScreen : NSObject
+ (UIScreen *)mainScreen;
@property (readonly) CGRect bounds;
@property (readonly) CGRect nativeBounds;
@property (readonly) CGFloat scale;
@property (readonly) CGFloat nativeScale;
@property (readonly, getter=isCaptured) BOOL captured;
@property (readonly) id traitCollection;
@end

@interface UIImage : NSObject
+ (UIImage *)imageNamed:(NSString *)name;
+ (UIImage *)imageWithData:(NSData *)data;
+ (UIImage *)imageWithData:(NSData *)data scale:(CGFloat)scale;
+ (UIImage *)systemImageNamed:(NSString *)name;
+ (UIImage *)systemImageNamed:(NSString *)name withConfiguration:(id)config;
+ (UIImage *)imageWithCGImage:(CGImageRef)img;
- (void)drawInRect:(CGRect)rect;
- (void)drawAtPoint:(CGPoint)point;
- (UIImage *)imageWithRenderingMode:(NSInteger)mode;
@property (readonly) CGSize size;
@property (readonly) CGFloat scale;
@property (readonly) CGImageRef CGImage;
@property (readonly) NSInteger renderingMode;
typedef NS_ENUM(NSInteger, UIImageRenderingMode) { UIImageRenderingModeAutomatic = 0, UIImageRenderingModeAlwaysOriginal = 1, UIImageRenderingModeAlwaysTemplate = 2 };
@end
extern NSData *UIImagePNGRepresentation(UIImage *img);
extern NSData *UIImageJPEGRepresentation(UIImage *img, CGFloat quality);

@interface UIFont : NSObject
+ (UIFont *)systemFontOfSize:(CGFloat)size;
+ (UIFont *)boldSystemFontOfSize:(CGFloat)size;
+ (UIFont *)systemFontOfSize:(CGFloat)size weight:(CGFloat)weight;
+ (UIFont *)monospacedDigitSystemFontOfSize:(CGFloat)size weight:(CGFloat)weight;
+ (UIFont *)monospacedSystemFontOfSize:(CGFloat)size weight:(CGFloat)weight;
+ (UIFont *)preferredFontForTextStyle:(NSInteger)style;
@end

@class UIGraphicsImageRendererContext;
@interface UIGraphicsImageRendererFormat : NSObject
+ (instancetype)defaultFormat;
+ (instancetype)preferredFormat;
+ (instancetype)formatForTraitCollection:(id)trait;
@property CGFloat scale;
@property BOOL opaque;
@property NSInteger preferredRange;
@end

@interface UIGraphicsImageRendererContext : NSObject
@property (readonly) CGContextRef CGContext;
@end

@interface UIGraphicsImageRenderer : NSObject
- (instancetype)initWithSize:(CGSize)size;
- (instancetype)initWithSize:(CGSize)size format:(UIGraphicsImageRendererFormat *)format;
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *context))actions;
@end



extern void UIGraphicsBeginImageContextWithOptions(CGSize size, BOOL opaque, CGFloat scale);
extern UIImage *UIGraphicsGetImageFromCurrentImageContext(void);
extern void UIGraphicsEndImageContext(void);
extern CGContextRef UIGraphicsGetCurrentContext(void);
extern CGSize UIGraphicsGetCurrentContextSize(void);

@interface CALayer : NSObject
+ (instancetype)layer;
@property CGRect frame;
@property CGRect bounds;
@property CGPoint position;
@property CGFloat cornerRadius;
@property CGFloat borderWidth;
@property CGColorRef borderColor;
@property CGColorRef backgroundColor;
@property CGFloat opacity;
@property BOOL masksToBounds;
@property CGPoint anchorPoint;
@property CGFloat zPosition;
@property (copy) NSString *name;
@property CGPoint shadowOffset;
@property CGFloat shadowOpacity;
@property CGFloat shadowRadius;
@property CGColorRef shadowColor;
@property (readonly) CALayer *presentationLayer;
@property (readonly) CALayer *modelLayer;
@property (copy) NSString *compositingFilter;
@property (strong) id filters;
@property BOOL shouldRasterize;
@property CGFloat rasterizationScale;
@property (copy) NSArray *sublayers;
@property (weak) CALayer *superlayer;
- (void)addSublayer:(CALayer *)l;
- (void)removeFromSuperlayer;
- (void)setNeedsDisplay;
- (void)displayIfNeeded;
- (void)addAnimation:(CAAnimation *)anim forKey:(NSString *)key;
- (void)removeAnimationForKey:(NSString *)key;
- (void)removeAllAnimations;
- (CGPoint)convertPoint:(CGPoint)p fromLayer:(CALayer *)l;
- (CGPoint)convertPoint:(CGPoint)p toLayer:(CALayer *)l;
@property CGFloat speed;
@property CGFloat timeOffset;
@end

@class CAMediaTimingFunction;
@interface CAAnimation : NSObject
+ (instancetype)animation;
@property CFTimeInterval duration;
@property (strong) CAMediaTimingFunction *timingFunction;
@property BOOL removedOnCompletion;
@property CFTimeInterval beginTime;
@property (copy) NSString *fillMode;
@property float speed;
@property float repeatCount;
@property BOOL autoreverses;
@property (strong) id delegate;
@end

@interface CABasicAnimation : CAAnimation
+ (instancetype)animationWithKeyPath:(NSString *)path;
@property (strong) id fromValue;
@property (strong) id toValue;
@property (strong) id byValue;
@end

@interface CAKeyframeAnimation : CAAnimation
+ (instancetype)animationWithKeyPath:(NSString *)path;
@property (copy) NSArray *values;
@property (copy) NSArray *keyTimes;
@property (copy) NSArray *timingFunctions;
@property CGPathRef path;
@property (copy) NSString *calculationMode;
@property (copy) NSString *rotationMode;
@end

@interface CAPropertyAnimation : CAAnimation
@end

@interface CATransaction : NSObject
+ (void)begin;
+ (void)commit;
+ (void)setDisableActions:(BOOL)v;
+ (void)flush;
+ (void)setAnimationDuration:(CFTimeInterval)d;
@end

@interface CAMediaTimingFunction : NSObject
+ (instancetype)functionWithName:(NSString *)name;
+ (instancetype)functionWithControlPoints:(float)c1x :(float)c1y :(float)c2x :(float)c2y;
@end
extern NSString *const kCAMediaTimingFunctionEaseInEaseOut;
extern NSString *const kCAMediaTimingFunctionEaseIn;
extern NSString *const kCAMediaTimingFunctionEaseOut;
extern NSString *const kCAMediaTimingFunctionLinear;
extern NSString *const kCAMediaTimingFunctionDefault;



@class UIWindowScene, UIScene;
@interface UIResponder : NSObject
@property (readonly) UIResponder *nextResponder;
@property (readonly) id inputView;
@property (readonly) id inputAccessoryView;
@property (readonly) BOOL canBecomeFirstResponder;
- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;
- (void)touchesBegan:(id)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(id)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(id)touches withEvent:(UIEvent *)event;
- (void)touchesCancelled:(id)touches withEvent:(UIEvent *)event;
@end

@interface UILabel : UIResponder
@property (copy) NSString *text;
@property (strong) UIFont *font;
@property (strong) UIColor *textColor;
@property NSInteger textAlignment;
@property NSInteger numberOfLines;
@property CGFloat minimumScaleFactor;
@property BOOL adjustsFontSizeToFitWidth;
@property BOOL adjustsFontForContentSizeCategory;
@property NSInteger lineBreakMode;
@end

@protocol UILayoutSupport <NSObject>
@end

@interface UIView : UIResponder
- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithCoder:(NSCoder *)coder;
@property CGRect frame;
@property CGRect bounds;
@property CGPoint center;
@property (copy) NSString *accessibilityIdentifier;
@property (copy) NSString *accessibilityLabel;
@property NSUInteger accessibilityTraits;
@property BOOL isAccessibilityElement;
@property CGFloat alpha;
@property BOOL hidden;
@property BOOL opaque;
@property BOOL clipsToBounds;
@property BOOL userInteractionEnabled;
@property BOOL multipleTouchEnabled;
@property BOOL exclusiveTouch;
@property NSInteger contentMode;
@property (readonly) CALayer *layer;
@property (readonly) UIView *superview;
@property (readonly) NSArray<UIView *> *subviews;
@property (readonly) UIWindow *window;
@property CGFloat cornerRadius;
@property CGColorRef backgroundColor0;
@property (strong) UIColor *backgroundColor;
@property (strong) UIColor *tintColor;
@property (readonly) id traitCollection;
@property NSInteger tag;
@property CGFloat transform0;
@property BOOL isFocused;
@property (readonly) BOOL isFirstResponder;
@property (copy) NSString *debugDescription0;
- (void)addSubview:(UIView *)v;
- (void)insertSubview:(UIView *)v atIndex:(NSUInteger)i;
- (void)insertSubview:(UIView *)v belowSubview:(UIView *)s;
- (void)insertSubview:(UIView *)v aboveSubview:(UIView *)s;
- (void)removeFromSuperview;
- (void)bringSubviewToFront:(UIView *)v;
- (void)sendSubviewToBack:(UIView *)v;
- (void)layoutIfNeeded;
- (void)setNeedsLayout;
- (void)setNeedsDisplay;
- (void)drawRect:(CGRect)rect;
- (void)removeAllSubviews;
- (CGPoint)convertPoint:(CGPoint)p fromView:(UIView *)v;
- (CGPoint)convertPoint:(CGPoint)p toView:(UIView *)v;
- (CGRect)convertRect:(CGRect)r fromView:(UIView *)v;
- (CGRect)convertRect:(CGRect)r toView:(UIView *)v;
- (UIView *)hitTest:(CGPoint)p withEvent:(UIEvent *)e;
- (BOOL)pointInside:(CGPoint)p withEvent:(UIEvent *)e;
- (void)sizeToFit;
- (CGSize)sizeThatFits:(CGSize)s;
- (void)setContentHuggingPriority:(float)p forAxis:(NSInteger)axis;
- (void)setContentCompressionResistancePriority:(float)p forAxis:(NSInteger)axis;
- (BOOL)isDescendantOfView:(UIView *)v;
- (instancetype)snapshotViewAfterScreenUpdates:(BOOL)u;
- (void)setNeedsUpdateConstraints;
- (void)updateConstraints;
- (void)layoutSubviews;
- (void)didMoveToWindow;
- (void)didMoveToSuperview;
- (void)willMoveToWindow:(UIWindow *)w;
- (void)willMoveToSuperview:(UIView *)v;
- (void)setNeedsDisplayOnBoundsChange:(BOOL)b;
- (void)invalidateIntrinsicContentSize;
@end

extern void UIViewPerformWithoutAnimation(dispatch_block_t b);
extern void UIViewAnimateWithDuration(NSTimeInterval d, dispatch_block_t b);
extern void UIViewAnimateKeyframesWithDuration(NSTimeInterval d, NSUInteger opts, dispatch_block_t b, void (^c)(BOOL));
extern void UIViewAnimateWithDurationOpts(NSTimeInterval d, NSUInteger opts, dispatch_block_t b, void (^c)(BOOL));
extern void UIViewAnimateWithDurationSpring(NSTimeInterval d, CGFloat damping, CGFloat velocity, NSUInteger opts, dispatch_block_t b, void (^c)(BOOL));
extern void UIViewTransitionWithView(UIView *v, NSTimeInterval d, NSUInteger opts, dispatch_block_t b, void (^c)(BOOL));
extern void UIViewPerformWithoutAnimationBlock(void (^b)(void));

@interface UIWindow : UIView
@property (readonly, getter=isKeyWindow) BOOL keyWindow;
@property (strong) UIViewController *rootViewController;
@property (readonly) UIWindowScene *windowScene;
- (void)makeKeyAndVisible;
- (void)makeKeyWindow;
@property NSInteger windowLevel;
@property BOOL hidden0;
@end

@class UISceneSession;
@interface UIScene : NSObject
@property (readonly) UISceneSession *session;
@property (readonly) NSInteger activationState;
@property (copy) NSString *title;
@end

@interface UIWindowScene : UIScene
@property (readonly) NSArray<UIWindow *> *windows;
@property (readonly) UIScreen *screen;
@property (readonly) NSInteger interfaceOrientation;
@end

@class UIApplication;
@interface UIApplication : UIResponder
+ (UIApplication *)sharedApplication;
- (void)sendEvent:(UIEvent *)event;
@property (readonly) NSArray<id> *connectedScenes;
@property (readonly) NSArray<UIWindow *> *windows;
@property (readonly, getter=isIdleTimerDisabled) BOOL idleTimerDisabled;
- (void)setIdleTimerDisabled:(BOOL)d;
@property (readonly) UIWindow *keyWindow;
@property (readonly) NSInteger applicationState;
@property (copy, readonly) NSString *applicationId;
@property (copy, readonly) NSString *bundleIdentifier;
- (void)openURL:(id)url options:(NSDictionary *)o completionHandler:(void (^)(BOOL))c;
@property (readonly) id delegate;
@property (readonly) UIUserInterfaceIdiom userInterfaceIdiom;
@end

@interface UIDevice : NSObject
+ (UIDevice *)currentDevice;
@property (readonly) NSString *systemName;
@property (readonly) NSString *systemVersion;
@property (readonly) NSString *model;
@property (readonly) NSString *localizedModel;
@property (readonly) NSString *name;
@end

extern NSString *const UITrackingRunLoopMode;
extern NSString *const NSRunLoopCommonModes;
extern NSString *const UIScreenCaptureDidStartNotification;
extern NSString *const UIScreenCaptureDidStopNotification;
extern NSString *const UIApplicationDidBecomeActiveNotification;
extern NSString *const UIApplicationWillResignActiveNotification;
extern NSString *const UIWindowDidBecomeKeyNotification;
extern NSString *const UIApplicationDidEnterBackgroundNotification;
extern NSString *const UIApplicationWillEnterForegroundNotification;
extern NSString *const UIAccessibilityScreenChangedNotification;
extern NSString *const NSLocaleLanguageCode;

#endif
