#import "UIKit-stub.h"
@implementation Foo : NSObject
- (void)bar { UIView *v = [[UIView alloc] initWithFrame:CGRectMake(0,0,10,10)]; v.backgroundColor = [UIColor redColor]; [v removeFromSuperview]; }
@end
