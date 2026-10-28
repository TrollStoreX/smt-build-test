#ifndef SMT_STUB_UIKIT3_H
#define SMT_STUB_UIKIT3_H
#import "UIKit2.h"

@interface UIImageView : UIView
- (instancetype)initWithImage:(UIImage *)img;
@property (strong) UIImage *image;
@property NSInteger contentMode;
@property (strong) UIColor *tintColor;
@end

@interface UIVisualEffect : NSObject
@end
@interface UIBlurEffect : UIVisualEffect
+ (instancetype)effectWithStyle:(NSInteger)style;
@end
@interface UIVisualEffectView : UIView
- (instancetype)initWithEffect:(UIVisualEffect *)e;
@property (copy) UIVisualEffect *effect;
@property (readonly) UIView *contentView;
@end

@interface UIStackView : UIView
- (instancetype)initWithArrangedSubviews:(NSArray<UIView *> *)views;
@property (copy) NSArray<UIView *> *arrangedSubviews;
- (void)addArrangedSubview:(UIView *)v;
- (void)removeArrangedSubview:(UIView *)v;
@property NSInteger axis;
@property NSInteger distribution;
@property NSInteger alignment;
@property CGFloat spacing;
@end

@interface UIScrollView : UIView
@property CGPoint contentOffset;
@property CGSize contentSize;
@property UIEdgeInsets contentInset;
@property (getter=isScrollEnabled) BOOL scrollEnabled;
@property BOOL showsVerticalScrollIndicator;
@property BOOL showsHorizontalScrollIndicator;
@property BOOL alwaysBounceVertical;
@property NSInteger contentInsetAdjustmentBehavior;
@property (getter=isPagingEnabled) BOOL pagingEnabled;
@property BOOL bounces;
@property (readonly) UIGestureRecognizer *panGestureRecognizer;
@end

@interface UITableView : UIScrollView
- (instancetype)initWithFrame:(CGRect)f style:(NSInteger)s;
- (void)registerClass:(Class)c forCellReuseIdentifier:(NSString *)i;
- (id)dequeueReusableCellWithIdentifier:(NSString *)i;
- (id)dequeueReusableCellWithIdentifier:(NSString *)i forIndexPath:(NSIndexPath *)p;
- (void)reloadData;
- (void)reloadSections:(NSIndexSet *)s withRowAnimation:(NSInteger)a;
@property (weak) id delegate;
@property (weak) id dataSource;
@property CGFloat rowHeight;
@property CGFloat estimatedRowHeight;
@property CGFloat estimatedSectionHeaderHeight;
@property UIEdgeInsets separatorInset;
@property NSInteger separatorStyle;
@property (strong) UIColor *separatorColor;
@property (strong) UIView *tableHeaderView;
@property (strong) UIView *tableFooterView;
- (void)selectRowAtIndexPath:(NSIndexPath *)p animated:(BOOL)a scrollPosition:(NSInteger)sp;
- (void)deselectRowAtIndexPath:(NSIndexPath *)p animated:(BOOL)a;
@end

#define UITableViewCellStyleDefault 0
#define UITableViewCellStyleValue1 1
#define UITableViewCellStyleValue2 2
#define UITableViewCellStyleSubtitle 3
#define UITableViewCellAccessoryNone 0
#define UITableViewCellAccessoryDisclosureIndicator 1
#define UITableViewCellAccessoryDetailDisclosureButton 2
#define UITableViewCellAccessoryCheckmark 3
#define UITableViewCellAccessoryDetailButton 4
#define UITableViewCellSelectionStyleNone 0
#define UITableViewCellSelectionStyleDefault 1
#define UITableViewCellSelectionStyleGray 1
#define UITableViewCellSelectionStyleBlue 2
#define UITableViewCellEditingStyleNone 0
#define UITableViewCellEditingStyleDelete 1
#define UITableViewCellEditingStyleInsert 2
#define UITableViewCellSeparatorStyleNone 0
#define UITableViewCellSeparatorStyleSingleLine 1
#define UITableViewStylePlain 0
#define UITableViewStyleGrouped 1
#define UITableViewStyleInsetGrouped 2

@interface UITableViewCell : UIView
- (instancetype)initWithStyle:(NSInteger)style reuseIdentifier:(NSString *)i;
@property (readonly) UILabel *textLabel;
@property (readonly) UILabel *detailTextLabel;
@property (strong) UIImageView *imageView;
@property (readonly) UIView *contentView;
@property (strong) UIView *accessoryView;
@property NSInteger accessoryType;
@property NSInteger selectionStyle;
@property (readonly) NSString *reuseIdentifier;
@end

@interface UIGestureRecognizer : NSObject
- (instancetype)initWithTarget:(id)t action:(SEL)a;
- (void)addTarget:(id)t action:(SEL)a;
- (void)removeTarget:(id)t action:(SEL)a;
@property (getter=isEnabled) BOOL enabled;
@property (readonly) NSInteger state;
@property (readonly) UIView *view;
- (void)requireGestureRecognizerToFail:(UIGestureRecognizer *)g;
@end

@interface UITapGestureRecognizer : UIGestureRecognizer
@property NSUInteger numberOfTapsRequired;
@property NSUInteger numberOfTouchesRequired;
@end
@interface UILongPressGestureRecognizer : UIGestureRecognizer
@property NSTimeInterval minimumPressDuration;
@property CGFloat allowableMovement;
@property NSUInteger numberOfTouchesRequired;
@end
@interface UISwipeGestureRecognizer : UIGestureRecognizer
@property NSUInteger direction;
@property NSUInteger numberOfTouchesRequired;
@end
@interface UIPanGestureRecognizer : UIGestureRecognizer
@end

@interface UIColorWell : UIControl
@property (copy) NSString *title;
@property (strong) UIColor *selectedColor;
@property BOOL supportsAlpha;
@end

@interface UIAlertAction : NSObject
+ (instancetype)actionWithTitle:(NSString *)t style:(NSInteger)s handler:(void (^)(UIAlertAction *a))h;
@property (getter=isEnabled) BOOL enabled;
@end
@interface UIAlertController : UIViewController
+ (instancetype)alertControllerWithTitle:(NSString *)t message:(NSString *)m preferredStyle:(NSInteger)s;
- (void)addAction:(UIAlertAction *)a;
- (void)addTextFieldWithConfigurationHandler:(void (^)(id tf))h;
@property (copy) NSString *message;
@property (readonly) NSArray<UIAlertAction *> *actions;
@end
#define UIAlertActionStyleDefault 0
#define UIAlertActionStyleCancel 1
#define UIAlertActionStyleDestructive 2
#define UIAlertControllerStyleAlert 1
#define UIAlertControllerStyleActionSheet 0

@interface UIActivityViewController : UIViewController
- (instancetype)initWithActivityItems:(NSArray *)items applicationActivities:(NSArray *)a;
@end

@interface UITextField : UIControl
@property (copy) NSString *text;
@property (copy) NSString *placeholder;
@property (strong) UIFont *font;
@property (strong) UIColor *textColor;
@property NSInteger textAlignment;
@property NSInteger keyboardType;
@end

@interface UIPickerView : UIView
@end

#endif
