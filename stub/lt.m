typedef void NSObject;
@interface UIApplication @end
@interface UIEvent @end
#import "lg.h"
%hook(UIApplication)
- (void)sendEvent:(UIEvent *)event {
    %orig;
    int x = 1;
}
%end
