#ifndef SMT_STUB_FOUNDATION_H
#define SMT_STUB_FOUNDATION_H
#import "base.h"
#include <objc/runtime.h>

@class NSString, NSArray, NSDictionary, NSData, NSError, NSValue, NSNumber, NSObject, NSCoder, NSNotification, NSBundle, NSURL;
@class NSMethodSignature, NSInvocation, NSEnumerator;

typedef struct objc_object *id;
typedef struct objc_selector *SEL;
typedef id (*IMP)(id, SEL, ...);
typedef struct objc_method *Method;


typedef NSString *NSRunLoopMode;
typedef NSUInteger NSStringEncoding;
typedef NSUInteger NSPointerFunctionsOptions;
typedef struct { unsigned long state; id __unsafe_unretained *itemsPtr; unsigned long *mutationsPtr; unsigned long extra[5]; } NSFastEnumerationState;

#ifndef NS_ROOT_CLASS
#define NS_ROOT_CLASS __attribute__((objc_root_class))
#endif

@protocol NSObject
- (BOOL)isEqual:(id)object;
- (NSUInteger)hash;
- (Class)class;
- (BOOL)isKindOfClass:(Class)aClass;
- (BOOL)isMemberOfClass:(Class)aClass;
- (BOOL)conformsToProtocol:(Protocol *)aProtocol;
- (BOOL)respondsToSelector:(SEL)aSelector;
- (id)retain;
- (void)release;
- (id)autorelease;
- (NSUInteger)retainCount;
- (NSString *)description;
@end

@protocol NSFastEnumeration
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id __unsafe_unretained *)stackbuf count:(NSUInteger)len;
@end

@protocol NSCopying
- (id)copyWithZone:(NSZone *)zone;
@end

@protocol NSMutableCopying
- (id)mutableCopyWithZone:(NSZone *)zone;
@end


@protocol NSCoding
- (void)encodeWithCoder:(NSCoder *)coder;
- (instancetype)initWithCoder:(NSCoder *)coder;
@end

NS_ROOT_CLASS @interface NSObject <NSObject> {
    Class isa;
}
+ (instancetype)alloc;
+ (instancetype)new;
+ (Class)class;
+ (Class)superclass;
+ (BOOL)instancesRespondToSelector:(SEL)sel;
+ (BOOL)resolveClassMethod:(SEL)sel;
+ (BOOL)resolveInstanceMethod:(SEL)sel;
+ (BOOL)conformsToProtocol:(Protocol *)p;
+ (BOOL)isSubclassOfClass:(Class)c;
+ (id)allocWithZone:(NSZone *)zone;
- (instancetype)init;
- (id)copy;
- (id)mutableCopy;
- (Class)class;
- (Class)superclass;
- (BOOL)isKindOfClass:(Class)cls;
- (BOOL)isMemberOfClass:(Class)cls;
- (BOOL)respondsToSelector:(SEL)sel;
- (BOOL)conformsToProtocol:(Protocol *)p;
- (BOOL)isEqual:(id)obj;
- (NSUInteger)hash;
- (NSString *)description;
- (id)performSelector:(SEL)sel;
- (id)performSelector:(SEL)sel withObject:(id)o1;
- (id)performSelector:(SEL)sel withObject:(id)o1 withObject:(id)o2;
- (void)performSelector:(SEL)sel withObject:(id)o afterDelay:(NSTimeInterval)d;
- (void)performSelector:(SEL)sel withObject:(id)o afterDelay:(NSTimeInterval)d inModes:(NSArray *)m;
- (void)performSelectorInBackground:(SEL)sel withObject:(id)o;
- (void)performSelectorOnMainThread:(SEL)sel withObject:(id)o waitUntilDone:(BOOL)w;
- (NSMethodSignature *)methodSignatureForSelector:(SEL)sel;
- (BOOL)isProxy;
- (id)self;
- (NSZone *)zone;
- (void)dealloc;
- (void)release;
- (id)retain;
- (id)autorelease;
- (NSUInteger)retainCount;
- (id)valueForKey:(NSString *)key;
- (void)setValue:(id)value forKey:(NSString *)key;
- (id)valueForKeyPath:(NSString *)keyPath;
- (void)setValue:(id)value forKeyPath:(NSString *)keyPath;
- (BOOL)isEqualTo:(id)o;
@end

@interface NSString : NSObject <NSCopying>
+ (instancetype)string;
+ (instancetype)stringWithUTF8String:(const char *)s;
+ (instancetype)stringWithFormat:(NSString *)fmt, ...;
+ (instancetype)stringWithString:(NSString *)s;
- (instancetype)initWithUTF8String:(const char *)s;
- (instancetype)initWithFormat:(NSString *)fmt, ...;
- (instancetype)initWithString:(NSString *)s;
- (const char *)UTF8String;
- (NSUInteger)length;
- (BOOL)isEqualToString:(NSString *)s;
- (BOOL)hasPrefix:(NSString *)s;
- (BOOL)hasSuffix:(NSString *)s;
- (BOOL)containsString:(NSString *)s;
- (NSString *)lowercaseString;
- (NSString *)uppercaseString;
- (NSString *)stringByAppendingString:(NSString *)s;
- (NSString *)stringByAppendingPathComponent:(NSString *)s;
- (NSString *)stringByReplacingOccurrencesOfString:(NSString *)a withString:(NSString *)b;
- (NSString *)substringToIndex:(NSUInteger)i;
- (NSString *)substringFromIndex:(NSUInteger)i;
- (NSArray *)componentsSeparatedByString:(NSString *)s;
- (NSInteger)integerValue;
- (double)doubleValue;
- (float)floatValue;
- (BOOL)boolValue;
- (NSString *)localizedString;
- (instancetype)localized;
@end

@interface NSMutableString : NSString
+ (instancetype)string;
- (void)appendString:(NSString *)s;
- (void)appendFormat:(NSString *)fmt, ...;
@end

@interface NSNumber : NSObject <NSCopying>
+ (NSNumber *)numberWithBool:(BOOL)v;
+ (NSNumber *)numberWithChar:(char)v;
+ (NSNumber *)numberWithInt:(int)v;
+ (NSNumber *)numberWithLong:(long)v;
+ (NSNumber *)numberWithUnsignedInteger:(NSUInteger)v;
+ (NSNumber *)numberWithInteger:(NSInteger)v;
+ (NSNumber *)numberWithDouble:(double)v;
+ (NSNumber *)numberWithFloat:(float)v;
- (BOOL)boolValue;
- (char)charValue;
- (int)intValue;
- (long)longValue;
- (NSInteger)integerValue;
- (NSUInteger)unsignedIntegerValue;
- (double)doubleValue;
- (float)floatValue;
- (NSString *)stringValue;
- (BOOL)isEqualToNumber:(NSNumber *)n;
@end

@interface NSData : NSObject <NSCopying>
+ (instancetype)data;
+ (instancetype)dataWithBytes:(const void *)b length:(NSUInteger)l;
+ (instancetype)dataWithContentsOfFile:(NSString *)p;
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)a;
- (BOOL)isEqualToData:(NSData *)d;
@property (readonly) const void *bytes;
@property (readonly) NSUInteger length;
@end

@interface NSMutableData : NSData
+ (instancetype)data;
- (void)appendBytes:(const void *)b length:(NSUInteger)l;
- (void)appendData:(NSData *)d;
@end

@interface NSArray<__covariant ObjectType> : NSObject <NSFastEnumeration, NSCopying>
+ (instancetype)array;
+ (instancetype)arrayWithObject:(ObjectType)o;
+ (instancetype)arrayWithObjects:(const ObjectType *)objs count:(NSUInteger)cnt;
+ (instancetype)arrayWithArray:(NSArray<ObjectType> *)a;
- (instancetype)initWithObjects:(const ObjectType *)objs count:(NSUInteger)cnt;
- (ObjectType)objectAtIndex:(NSUInteger)i;
- (ObjectType)objectAtIndexedSubscript:(NSUInteger)i;
- (NSUInteger)count;
- (BOOL)containsObject:(ObjectType)o;
- (NSUInteger)indexOfObject:(ObjectType)o;
@property (readonly) ObjectType firstObject;
@property (readonly) ObjectType lastObject;
- (void)enumerateObjectsUsingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;
- (NSArray<ObjectType> *)sortedArrayUsingSelector:(SEL)sel;
- (NSArray<ObjectType> *)arrayByAddingObject:(ObjectType)o;
@end

@interface NSMutableArray<ObjectType> : NSArray<ObjectType>
+ (instancetype)array;
+ (instancetype)arrayWithCapacity:(NSUInteger)n;
- (void)addObject:(ObjectType)o;
- (void)removeObject:(ObjectType)o;
- (void)removeObjectAtIndex:(NSUInteger)i;
- (void)removeAllObjects;
- (void)insertObject:(ObjectType)o atIndex:(NSUInteger)i;
- (void)addObjectsFromArray:(NSArray<ObjectType> *)a;
- (void)setObject:(ObjectType)o atIndexedSubscript:(NSUInteger)i;
@end

@interface NSDictionary<KeyType, ValueType> : NSObject <NSFastEnumeration, NSCopying>
+ (instancetype)dictionary;
+ (instancetype)dictionaryWithObjects:(const ValueType *)objs forKeys:(const KeyType *)keys count:(NSUInteger)cnt;
+ (instancetype)dictionaryWithObject:(ValueType)o forKey:(KeyType)key;
- (ValueType)objectForKey:(KeyType)key;
- (ValueType)objectForKeyedSubscript:(KeyType)key;
- (NSArray<KeyType> *)allKeys;
- (NSArray<ValueType> *)allValues;
- (NSUInteger)count;
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(KeyType key, ValueType obj, BOOL *stop))block;
@end

@interface NSMutableDictionary<KeyType, ValueType> : NSDictionary<KeyType, ValueType>
+ (instancetype)dictionary;
- (void)setObject:(ValueType)o forKey:(KeyType)key;
- (void)setObject:(ValueType)o forKeyedSubscript:(KeyType)key;
- (void)removeObjectForKey:(KeyType)key;
- (void)removeAllObjects;
- (void)addEntriesFromDictionary:(NSDictionary<KeyType, ValueType> *)d;
@end

@interface NSSet<ObjectType> : NSObject <NSFastEnumeration>
+ (instancetype)set;
+ (instancetype)setWithArray:(NSArray<ObjectType> *)a;
- (NSUInteger)count;
- (NSArray<ObjectType> *)allObjects;
- (BOOL)containsObject:(ObjectType)o;
@property (readonly) ObjectType anyObject;
@end

@interface NSMutableSet<ObjectType> : NSSet<ObjectType>
+ (instancetype)set;
- (void)addObject:(ObjectType)o;
- (void)removeObject:(ObjectType)o;
@end

@interface NSOrderedSet : NSObject
@end

@interface NSValue : NSObject <NSCopying>
+ (NSValue *)valueWithCGPoint:(CGPoint)p;
+ (NSValue *)valueWithCGRect:(CGRect)r;
+ (NSValue *)valueWithCGSize:(CGSize)s;
+ (NSValue *)valueWithNonretainedObject:(id)o;
+ (NSValue *)valueWithPointer:(const void *)p;
+ (NSValue *)valueWithCGAffineTransform:(CGAffineTransform)t;
+ (NSValue *)valueWithUIEdgeInsets:(UIEdgeInsets)i;
- (CGPoint)CGPointValue;
- (CGRect)CGRectValue;
- (CGSize)CGSizeValue;
- (CGAffineTransform)CGAffineTransformValue;
- (UIEdgeInsets)UIEdgeInsetsValue;
- (void *)pointerValue;
- (id)nonretainedObjectValue;
@end

@interface NSMapTable<KeyType, ValueType> : NSObject
+ (instancetype)weakToStrongObjectsMapTable;
+ (instancetype)strongToStrongObjectsMapTable;
+ (instancetype)strongToWeakObjectsMapTable;
+ (instancetype)weakToWeakObjectsMapTable;
+ (instancetype)mapTableWithKeyOptions:(NSUInteger)ko valueOptions:(NSUInteger)vo;
- (ValueType)objectForKey:(KeyType)key;
- (void)setObject:(ValueType)o forKey:(KeyType)key;
- (void)removeObjectForKey:(KeyType)key;
- (void)removeAllObjects;
- (NSUInteger)count;
@end

@interface NSHashTable<ObjectType> : NSObject
+ (instancetype)weakObjectsHashTable;
+ (instancetype)hashTableWithOptions:(NSUInteger)o;
- (void)addObject:(ObjectType)o;
- (void)removeObject:(ObjectType)o;
- (NSArray<ObjectType> *)allObjects;
@end

@interface NSNotification : NSObject
@property (readonly) NSString *name;
@property (readonly) id object;
@property (readonly) NSDictionary *userInfo;
@end

@interface NSNotificationCenter : NSObject
+ (instancetype)defaultCenter;
- (void)addObserver:(id)o selector:(SEL)s name:(NSString *)n object:(id)obj;
- (id)addObserverForName:(NSString *)n object:(id)obj queue:(id)q usingBlock:(void (^)(NSNotification *))block;
- (void)postNotificationName:(NSString *)n object:(id)obj;

- (void)removeObserver:(id)o;
- (void)removeObserver:(id)o name:(NSString *)n object:(id)obj;
@end

@interface NSUserDefaults : NSObject
+ (instancetype)standardUserDefaults;
- (instancetype)initWithSuiteName:(NSString *)name;
- (id)objectForKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
- (float)floatForKey:(NSString *)key;
- (double)doubleForKey:(NSString *)key;
- (NSData *)dataForKey:(NSString *)key;
- (NSString *)stringForKey:(NSString *)key;
- (NSArray *)arrayForKey:(NSString *)key;
- (void)setObject:(id)o forKey:(NSString *)key;
- (void)setBool:(BOOL)b forKey:(NSString *)key;
- (void)setInteger:(NSInteger)i forKey:(NSString *)key;
- (void)setFloat:(float)f forKey:(NSString *)key;
- (void)setDouble:(double)d forKey:(NSString *)key;
- (void)removeObjectForKey:(NSString *)key;
- (void)registerDefaults:(NSDictionary *)d;
- (void)removePersistentDomainForName:(NSString *)name;
- (NSDictionary *)dictionaryRepresentation;
- (BOOL)synchronize;
@end

@interface NSKeyedArchiver : NSObject
+ (NSData *)archivedDataWithRootObject:(id)o requiringSecureCoding:(BOOL)r error:(id *)e;
+ (NSData *)archivedDataWithRootObject:(id)o;
+ (void)setClassName:(NSString *)n forClass:(Class)c;
@end

@interface NSKeyedUnarchiver : NSObject
+ (id)unarchivedObjectOfClass:(Class)c fromData:(NSData *)d error:(id *)e;
+ (id)unarchivedObjectOfClasses:(NSSet *)cs fromData:(NSData *)d error:(id *)e;
+ (id)unarchiveObjectWithData:(NSData *)d;
+ (void)setClass:(Class)c forClassName:(NSString *)n;
@end

@interface NSSecureUnarchiveFromDataTransformer : NSObject
@end

@interface NSValueTransformer : NSObject
+ (void)setValueTransformer:(NSValueTransformer *)t forName:(NSString *)n;
@end

@interface NSCoder : NSObject
@end

@interface NSBundle : NSObject
+ (instancetype)mainBundle;
+ (instancetype)bundleForClass:(Class)c;
+ (instancetype)bundleWithPath:(NSString *)p;
+ (instancetype)bundleWithIdentifier:(NSString *)i;
- (NSString *)pathForResource:(NSString *)n ofType:(NSString *)t;
- (NSString *)pathForResource:(NSString *)n ofType:(NSString *)t inDirectory:(NSString *)d;
- (NSString *)bundlePath;
- (NSString *)resourcePath;
- (id)objectForInfoDictionaryKey:(NSString *)k;
- (NSDictionary *)infoDictionary;
- (NSString *)localizedStringForKey:(NSString *)k value:(NSString *)v table:(NSString *)t;
- (NSString *)preferredLocalizations0;
@end

@interface NSLocale : NSObject
+ (instancetype)currentLocale;
+ (NSSet *)preferredLanguages;
- (NSString *)objectForKey:(NSString *)k;
@end

@interface NSProcessInfo : NSObject
+ (instancetype)processInfo;
@property (readonly) NSUInteger processorCount;
@property (readonly) NSString *operatingSystemVersionString;
@property (readonly) NSUInteger operatingSystemVersionMajor8;
@end

@interface NSRunLoop : NSObject
+ (instancetype)mainRunLoop;
+ (instancetype)currentRunLoop;
- (void)addTimer:(id)t forMode:(NSString *)m;
- (BOOL)runMode:(NSString *)m beforeDate:(id)d;
@end

@interface NSDate : NSObject
+ (instancetype)date;
+ (instancetype)dateWithTimeIntervalSinceNow:(NSTimeInterval)t;
- (NSTimeInterval)timeIntervalSinceNow;
@end

@interface NSTimer : NSObject
+ (instancetype)scheduledTimerWithTimeInterval:(NSTimeInterval)t repeats:(BOOL)r block:(void (^)(id timer))b;
+ (instancetype)timerWithTimeInterval:(NSTimeInterval)t repeats:(BOOL)r block:(void (^)(id timer))b;
- (void)invalidate;
@end

@interface NSIndexPath : NSObject
+ (instancetype)indexPathForRow:(NSInteger)r inSection:(NSInteger)s;
@property (readonly) NSInteger row;
@property (readonly) NSInteger section;
@property (readonly) NSUInteger length;
- (NSUInteger)indexAtPosition:(NSUInteger)p;
@end

@interface NSIndexSet : NSObject
+ (instancetype)indexSetWithIndex:(NSUInteger)i;
@property (readonly) NSUInteger count;
@end

@interface NSInvocation : NSObject
@end
@interface NSMethodSignature : NSObject
+ (instancetype)signatureWithObjCTypes:(const char *)t;
@end
@interface NSLayoutConstraint : NSObject
@end
@interface NSURL : NSObject
+ (instancetype)URLWithString:(NSString *)s;
+ (instancetype)fileURLWithPath:(NSString *)p;
@property (readonly) NSString *path;
@property (readonly) NSString *absoluteString;
@end
@interface NSError : NSObject

@property (readonly) NSString *localizedDescription;
@property (readonly) NSInteger code;
@end
@interface NSException : NSObject
@end
@interface NSAttributedString : NSObject
@end
@interface NSMutableAttributedString : NSAttributedString
@end
@interface NSBlockOperation : NSObject
@end
@interface NSOperationQueue : NSObject
+ (instancetype)mainQueue;
@end

typedef void (^dispatch_block_t)(void);
typedef void *dispatch_queue_t;
typedef long dispatch_once_t;
typedef void *dispatch_group_t;
typedef unsigned long long dispatch_time_t;
extern dispatch_queue_t dispatch_get_main_queue(void);
extern dispatch_queue_t dispatch_get_global_queue(long identifier, unsigned long flags);
extern void dispatch_async(dispatch_queue_t q, dispatch_block_t b);
extern void dispatch_sync(dispatch_queue_t q, dispatch_block_t b);
extern void dispatch_once(dispatch_once_t *predicate, dispatch_block_t b);
extern void dispatch_after(dispatch_time_t when, dispatch_queue_t q, dispatch_block_t b);
#define DISPATCH_TIME_NOW 0ull
#define DISPATCH_TIME_FOREVER (~0ull)
extern dispatch_time_t dispatch_time(dispatch_time_t when, long long delta);
extern void dispatch_retain(dispatch_queue_t q);
extern void dispatch_release(dispatch_queue_t q);
#define DISPATCH_QUEUE_PRIORITY_DEFAULT 0
#define DISPATCH_QUEUE_PRIORITY_HIGH 2
#define DISPATCH_QUEUE_PRIORITY_LOW (-2)
#define DISPATCH_QUEUE_PRIORITY_BACKGROUND (-32768)

extern id objc_getClass(const char *name);
extern Class objc_lookUpClass(const char *name);
extern Class objc_getMetaClass(const char *name);
extern void objc_setAssociatedObject(id object, const void *key, id value, long policy);
extern id objc_getAssociatedObject(id object, const void *key);
extern void objc_removeAssociatedObjects(id object);
extern id objc_msgSend(id self, SEL op, ...);
extern void objc_msgSendSuper2(void);
extern id objc_retain(id o);
extern void objc_release(id o);
extern id objc_autorelease(id o);
extern id objc_autoreleaseReturnValue(id o);
extern id objc_retainAutoreleasedReturnValue(id o);
extern void objc_enumerationMutation(id obj);
extern void objc_storeStrong(id *p, id o);
extern void objc_destructInstance(id o);
extern id objc_alloc(Class c);
#define OBJC_ASSOCIATION_ASSIGN 0
#define OBJC_ASSOCIATION_RETAIN_NONATOMIC 1
#define OBJC_ASSOCIATION_COPY_NONATOMIC 3
#define OBJC_ASSOCIATION_RETAIN 01401
#define OBJC_ASSOCIATION_COPY 01403

#endif
