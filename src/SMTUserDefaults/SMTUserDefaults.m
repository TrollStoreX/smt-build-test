#import <SMTUserDefaults/SMTUserDefaults.h>

@implementation SMTUserDefaults
{
    NSData *_cachedImageData;
    UIImage *_cachedImage;
}

static NSString *const kDefaultsSuiteName = @"com.dvntm.showmytouches";

+ (SMTUserDefaults *)standardUserDefaults {
    static dispatch_once_t onceToken;
    static SMTUserDefaults *defaults = nil;

    dispatch_once(&onceToken, ^{
        defaults = [[self alloc] initWithSuiteName:kDefaultsSuiteName];
        [defaults registerDefaults];
    });

    return defaults;
}

- (void)reset {
    [self removePersistentDomainForName:kDefaultsSuiteName];
}

- (void)registerDefaults {
    NSData *touchColorData = [self dataWithColor:[UIColor secondaryLabelColor]];
    NSData *borderColorData = [self dataWithColor:[UIColor grayColor]];

    [self registerDefaults:@{
        @"enable": @YES,
        @"recording": @YES,
        @"morph": @NO,
        @"comet": @NO,
        @"useImage": @NO,
        @"touchColor": touchColorData,
        @"borderColor": borderColorData,
        @"duration": @0.3,
        @"touchSize": @40,
        @"touchRadius": @20,
        @"borderWidth": @3.0
    }];

#if SIDELOADING
    [self registerDefaults:@{
        @"openTwoFingerHold": @YES,
        @"openFourFingerTap": @NO,
        @"openThreeFingerHold": @NO,
        @"openShake": @NO
    }];

    // 老版本只存过旧手势的开关时，用「双指长按」作为新的默认值，
    // 保证升级后仍然有一个入口可用。
    [self migrateSettingsGesturesIfNeeded];
#endif
}

+ (void)resetUserDefaults {
    [[self standardUserDefaults] reset];
}

- (NSData *)dataWithColor:(UIColor *)color {
    return [NSKeyedArchiver archivedDataWithRootObject:color requiringSecureCoding:NO error:nil];
}

- (BOOL)isEnabled {
    return [self boolForKey:@"enable"];
}

- (BOOL)onlyWhileRecording {
    return [self boolForKey:@"recording"];
}

- (BOOL)isMorphEnabled {
    return [self boolForKey:@"morph"];
}

- (BOOL)isCometEnabled {
    return [self boolForKey:@"comet"];
}

- (BOOL)isImageEnabled {
    return [self boolForKey:@"useImage"];
}

#if SIDELOADING
+ (NSArray<NSString *> *)openSettingsKeys {
    return @[@"openTwoFingerHold", @"openFourFingerTap", @"openThreeFingerHold", @"openShake"];
}

- (void)migrateSettingsGesturesIfNeeded {
    static NSString *const kMigrationKey = @"openGesturesMigratedV2";
    if ([self boolForKey:kMigrationKey]) return;
    [self setBool:YES forKey:kMigrationKey];

    // 没有任何手势键被写过 = 全新安装，注册的默认值已经够用
    NSArray<NSString *> *legacy = @[@"openFourFingerTap", @"openThreeFingerHold", @"openShake"];
    BOOL hasStoredValue = NO;
    for (NSString *key in legacy) {
        if ([self objectForKey:key] != nil) { hasStoredValue = YES; break; }
    }
    if (!hasStoredValue) return;

    [self setBool:YES forKey:@"openTwoFingerHold"];
    [self setBool:NO forKey:@"openFourFingerTap"];
    [self setBool:NO forKey:@"openThreeFingerHold"];
    [self setBool:NO forKey:@"openShake"];
}

- (BOOL)twoFingerHoldOpensSettings {
    return [self boolForKey:@"openTwoFingerHold"];
}

- (BOOL)fourFingerTapOpensSettings {
    return [self boolForKey:@"openFourFingerTap"];
}

- (BOOL)threeFingerHoldOpensSettings {
    return [self boolForKey:@"openThreeFingerHold"];
}

- (BOOL)shakeOpensSettings {
    return [self boolForKey:@"openShake"];
}
#endif

- (UIColor *)touchColor {
    return [self colorForKey:@"touchColor"];
}

- (UIColor *)borderColor {
    return [self colorForKey:@"borderColor"];
}

- (CGFloat)touchSize {
    return [self floatForKey:@"touchSize"];
}

- (CGFloat)touchRadius {
    return [self floatForKey:@"touchRadius"];
}

- (CGFloat)borderWidth {
    return [self floatForKey:@"borderWidth"];
}

- (CGFloat)duration {
    return [self floatForKey:@"duration"];
}

- (UIColor *)colorForKey:(NSString *)key {
    NSData *colorData = [self objectForKey:key];
    return colorData ? [NSKeyedUnarchiver unarchivedObjectOfClass:[UIColor class] fromData:colorData error:nil] : nil;
}

- (void)setColor:(UIColor *)color forKey:(NSString *)key {
    [self setObject:[self dataWithColor:color] forKey:key];
}

- (UIImage *)touchImage {
    NSData *data = [self dataForKey:@"touchImage"];
    if (!data) {
        return nil;
    }

    if (![data isEqualToData:_cachedImageData]) {
        _cachedImageData = data;
        _cachedImage = [UIImage imageWithData:data];
    }

    return _cachedImage;
}

- (void)setTouchImage:(UIImage *)image {
    if (!image || image.size.width <= 0 || image.size.height <= 0) {
        [self removeObjectForKey:@"touchImage"];
        return;
    }

    CGSize pixels = CGSizeMake(image.size.width * image.scale, image.size.height * image.scale);
    CGFloat factor = MIN(1.0, kSMTTouchImageMaxPixels / MAX(pixels.width, pixels.height));
    CGSize size = CGSizeMake(MAX(round(pixels.width * factor), 1), MAX(round(pixels.height * factor), 1));

    UIGraphicsImageRendererFormat *format = [UIGraphicsImageRendererFormat preferredFormat];
    format.scale = 1.0;
    format.opaque = NO;

    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:size format:format];
    UIImage *resized = [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        [image drawInRect:CGRectMake(0, 0, size.width, size.height)];
    }];

    [self setObject:UIImagePNGRepresentation(resized) forKey:@"touchImage"];
}

@end
