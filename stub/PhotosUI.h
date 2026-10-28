#ifndef SMT_STUB_PHOTOSUI_H
#define SMT_STUB_PHOTOSUI_H
#import "UIKit3.h"

@class PHPickerConfiguration, PHPickerResult;

@interface PHPickerFilter : NSObject
+ (instancetype)imagesFilter;
@end

@interface PHPickerConfiguration : NSObject
- (instancetype)initWithPhotoLibrary:(id)library;
@property NSInteger selectionLimit;
@property (strong) PHPickerFilter *filter;
@end

@interface PHPickerResult : NSObject
@property (readonly) id itemProvider;
@end

@protocol PHPickerViewControllerDelegate <NSObject>
- (void)pickerViewController:(UIViewController *)picker didFinishPicking:(NSArray<PHPickerResult *> *)results;
@end

@interface PHPickerViewController : UIViewController
- (instancetype)initWithConfiguration:(PHPickerConfiguration *)configuration;
@property (weak) id<PHPickerViewControllerDelegate> delegate;
@end

@protocol UITableViewDataSource <NSObject>
@end
@protocol UITableViewDelegate <NSObject>
@end

#endif
