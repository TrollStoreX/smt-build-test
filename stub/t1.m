#import "UIKit3.h"
@interface Foo : NSObject
@property (strong) UIColor *c;
@end
@implementation Foo
- (void)bar { UIView *v = [[UIView alloc] initWithFrame:CGRectMake(0,0,10,10)]; v.backgroundColor = [UIColor redColor]; UILabel *l = [[UILabel alloc] init]; l.text = @"x"; l.font = [UIFont systemFontOfSize:12]; [v addSubview:l]; [v removeFromSuperview]; _c = [UIColor systemRedColor]; }
@end
