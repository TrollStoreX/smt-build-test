#ifndef SMT_STUB_UIKIT2_H
#define SMT_STUB_UIKIT2_H
#import "UIKit-stub.h"

@class UIPresentationController, UIPopoverPresentationController, UISheetPresentationController, UINavigationItem, UIButtonConfiguration, UIImageConfiguration, UIVisualEffect, UIMenu, UIMenuElement, UITraitCollection, UIAppearance, UIImageView;

@interface UIEvent : NSObject
@property (readonly) NSInteger type;
@property (readonly) NSInteger subtype;
@property (readonly) NSTimeInterval timestamp;
- (NSSet<UITouch *> *)allTouches;
- (NSSet<UITouch *> *)touchesForWindow:(UIWindow *)w;
- (NSSet<UITouch *> *)touchesForView:(UIView *)v;
- (NSArray<UITouch *> *)coalescedTouchesForTouch:(UITouch *)touch;
- (NSArray<UITouch *> *)predictedTouchesForTouch:(UITouch *)touch;
@end

@interface UITouch : NSObject
@property (readonly) NSTimeInterval timestamp;
@property (readonly) NSInteger phase;
@property (readonly) NSInteger type;
@property (readonly) NSUInteger tapCount;
@property (readonly) UIWindow *window;
@property (readonly) UIView *view;
@property (readonly) CGFloat majorRadius;
@property (readonly) CGFloat majorRadiusTolerance;
@property (readonly) CGFloat force;
@property (readonly) CGFloat maximumPossibleForce;
@property (readonly) BOOL isFirstTouchForView;
@property (readonly) CGFloat altitudeAngle;
@property (readonly) CGFloat azimuthAngle;
- (CGPoint)locationInView:(UIView *)view;
- (CGPoint)preciseLocationInView:(UIView *)view;
- (CGPoint)previousLocationInView:(UIView *)view;
@end

@interface UITraitCollection : NSObject
@property (readonly) NSInteger userInterfaceStyle;
@property (readonly) CGFloat displayScale;
+ (instancetype)traitCollectionWithUserInterfaceStyle:(NSInteger)style;
@end

@interface UIViewController : UIResponder
@property (strong) UIView *view;
@property (copy) NSString *title;
@property (copy) NSString *navigationItemTitle;
@property (readonly) UINavigationController *navigationController;
@property (readonly) UINavigationItem *navigationItem;
@property (strong) UIBarButtonItem *navigationItemRightBarButtonItem;
- (void)loadView;
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewDidDisappear:(BOOL)animated;
- (void)viewWillLayoutSubviews;
- (void)viewDidLayoutSubviews;
- (void)viewSafeAreaInsetsDidChange;
@property (readonly) UIViewController *presentedViewController;
@property (readonly) UIViewController *presentingViewController;
@property (readonly) NSArray<UIViewController *> *childViewControllers;
@property NSInteger modalPresentationStyle;
@property NSInteger modalTransitionStyle;
@property BOOL definesPresentationContext;
@property (readonly) UISheetPresentationController *sheetPresentationController;
@property (readonly) UIPopoverPresentationController *popoverPresentationController;
@property (readonly) UIEdgeInsets preferredContentSize0;
@property (readwrite) CGSize preferredContentSize;
@property (copy) id transitionCoordinator;
- (void)presentViewController:(UIViewController *)vc animated:(BOOL)a completion:(dispatch_block_t)c;
- (void)dismissViewControllerAnimated:(BOOL)a completion:(dispatch_block_t)c;
- (void)addChildViewController:(UIViewController *)vc;
- (void)removeFromParentViewController;
@property (readonly) UIEdgeInsets safeAreaInsets;
@property (readonly) BOOL isBeingDismissed;
@property (readonly) BOOL isBeingPresented;
@property (readonly) BOOL isMovingFromParentViewController;
- (void)setNeedsStatusBarAppearanceUpdate;
@property (readonly) UIUserInterfaceStyle overrideUserInterfaceStyle;
- (void)setOverrideUserInterfaceStyle:(UIUserInterfaceStyle)s;
@end

@interface UIPresentationController : NSObject
@end
@interface UIPopoverPresentationController : NSObject
@property (strong) UIView *sourceView;
@property CGRect sourceRect;
@property NSInteger permittedArrowDirections;
@end

@class UISheetPresentationControllerDetent;
@interface UISheetPresentationControllerDetent : NSObject
+ (instancetype)mediumDetent;
+ (instancetype)largeDetent;
+ (instancetype)customDetentWithIdentifier:(NSString *)i resolver:(CGFloat (^)(id))r;
@end

@interface UISheetPresentationController : UIPresentationController
@property (copy) NSArray<UISheetPresentationControllerDetent *> *detents;
@property BOOL prefersGrabberVisible;
@property CGFloat preferredCornerRadius;
@property BOOL prefersScrollingExpandsWhenScrolledToEdge;
@property (weak) id delegate;
@property (copy) NSArray *largestUndimmedDetentIdentifiers;
@end

@interface UINavigationBar : UIView
@property NSInteger barStyle;
@property BOOL translucent;
@property (copy) NSString *prefersLargeTitles0;
@property BOOL prefersLargeTitles;
@property (copy) NSDictionary *titleTextAttributes;
- (void)setBackgroundImage:(UIImage *)img forBarMetrics:(NSInteger)m;
- (void)setShadowImage:(UIImage *)img;
@end

@interface UINavigationItem : NSObject
@property (copy) NSString *title;
@property (strong) UIBarButtonItem *rightBarButtonItem;
@property (strong) UIBarButtonItem *leftBarButtonItem;
@property (strong) UIView *titleView;
@property (copy) NSString *backButtonTitle;
@property BOOL hidesBackButton;
@property BOOL largeTitleDisplayMode;
- (void)setRightBarButtonItems:(NSArray<UIBarButtonItem *> *)items animated:(BOOL)a;
@end

@interface UINavigationController : UIViewController
- (instancetype)initWithRootViewController:(UIViewController *)vc;
- (void)pushViewController:(UIViewController *)vc animated:(BOOL)a;
- (UIViewController *)popViewControllerAnimated:(BOOL)a;
@property (readonly) NSArray<UIViewController *> *viewControllers;
- (void)setViewControllers:(NSArray<UIViewController *> *)vcs animated:(BOOL)a;
@property (readonly) UINavigationBar *navigationBar;
@property BOOL navigationBarHidden;
- (void)setNavigationBarHidden:(BOOL)h animated:(BOOL)a;
@property (readonly) UIViewController *topViewController;
@property (readonly) UIViewController *visibleViewController;
@property BOOL interactivePopGestureRecognizerEnabled0;
@end

@interface UITabBarController : UIViewController
@end

typedef void (^UIActionHandler)(id action);
@interface UIAction : NSObject
+ (instancetype)actionWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)i handler:(UIActionHandler)h;
+ (instancetype)actionWithHandler:(UIActionHandler)h;
@property (copy) NSString *title;
@property (strong) UIImage *image;
@property (readonly) NSString *identifier;
@property (getter=isEnabled) BOOL enabled;
@end

@interface UIMenuElement : NSObject
@end
@interface UIMenu : UIMenuElement
+ (instancetype)menuWithTitle:(NSString *)t children:(NSArray<UIMenuElement *> *)c;
+ (instancetype)menuWithTitle:(NSString *)t image:(UIImage *)i identifier:(NSString *)id options:(NSUInteger)o children:(NSArray<UIMenuElement *> *)c;
@end
@interface UIDeferredMenuElement : UIMenuElement
+ (instancetype)elementWithProvider:(void (^)(void (^)(NSArray<UIMenuElement *> *)))p;
+ (instancetype)uncachedProvider:(void (^)(void (^)(NSArray<UIMenuElement *> *)))p;
@end

@interface UIImageConfiguration : NSObject
@end

@interface UIBarButtonItem : NSObject
- (instancetype)initWithBarButtonSystemItem:(NSInteger)item target:(id)t action:(SEL)a;
- (instancetype)initWithTitle:(NSString *)title style:(NSInteger)style target:(id)t action:(SEL)a;
- (instancetype)initWithImage:(UIImage *)img style:(NSInteger)style target:(id)t action:(SEL)a;
- (instancetype)initWithBarButtonSystemItem:(NSInteger)item primaryAction:(UIAction *)a;
- (instancetype)initWithTitle:(NSString *)title image:(UIImage *)img target:(id)t action:(SEL)a menu:(UIMenu *)m;
- (instancetype)initWithImage:(UIImage *)img menu:(UIMenu *)m;
- (instancetype)initWithPrimaryAction:(UIAction *)a;
@property (strong) UIMenu *menu;
@property (copy) NSString *title;
@property (strong) UIImage *image;
@property (strong) UIAction *primaryAction;
@end

@interface UIControl : UIView
- (void)addTarget:(id)t action:(SEL)a forControlEvents:(NSUInteger)e;
- (void)removeTarget:(id)t action:(SEL)a forControlEvents:(NSUInteger)e;
- (void)sendActionsForControlEvents:(NSUInteger)e;
@property (getter=isEnabled) BOOL enabled;
@property (getter=isSelected) BOOL selected;
@property (getter=isHighlighted) BOOL highlighted;
@property (readonly) NSUInteger state;
@property (copy) NSString *accessibilityHint30;
@end

@interface UISwitch : UIControl
@property (getter=isOn) BOOL on;
- (void)setOn:(BOOL)on animated:(BOOL)a;
@property (strong) UIColor *onTintColor;
@property (strong) UIColor *thumbTintColor;
@end

@interface UISlider : UIControl
@property float value;
@property float minimumValue;
@property float maximumValue;
- (void)setValue:(float)v animated:(BOOL)a;
@property (strong) UIColor *minimumTrackTintColor;
@property (strong) UIColor *maximumTrackTintColor;
@property (strong) UIColor *thumbTintColor;
@property (copy) UIImage *minimumValueImage;
- (void)setThumbImage:(UIImage *)img forState:(NSUInteger)s;
@end

extern void UISliderSendActions(UISlider *s);

@interface UIButton : UIControl
+ (instancetype)buttonWithType:(NSInteger)t;
- (void)setTitle:(NSString *)t forState:(NSUInteger)s;
- (void)setImage:(UIImage *)i forState:(NSUInteger)s;
- (void)setTitleColor:(UIColor *)c forState:(NSUInteger)s;
- (void)setBackgroundImage:(UIImage *)i forState:(NSUInteger)s;
- (void)setAttributedTitle:(id)a forState:(NSUInteger)s;
@property (copy) NSString *titleLabelText0;
@property (readonly) UILabel *titleLabel;
@property (readonly) UIImageView *imageView;
@property (strong) UIColor *tintColor;

@end

extern UIButton *UIButtonWithType(NSInteger t);

#endif
