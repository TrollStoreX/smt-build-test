#ifndef SMT_STUB_BASE_H
#define SMT_STUB_BASE_H

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
static inline double hypot(double,double);
static inline double fabs(double);
static inline double round(double);
static inline double floor(double);
static inline double ceil(double);
extern double pow(double,double);
extern double sqrt(double);
#define memset __builtin_memset
#define memcpy __builtin_memcpy
extern int strcmp(const char*, const char*);


#define __has_feature_stub(x) 0
#define NS_ASSUME_NONNULL_BEGIN
#define NS_ASSUME_NONNULL_END
#define NS_DESIGNATED_INITIALIZER
#define API_AVAILABLE(...)
#define API_UNAVAILABLE(...)
#define API_DEPRECATED(...)
#define AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER
#define NS_REQUIRES_SUPER
#define NS_SWIFT_UNAVAILABLE(x)
#define UI_APPEARANCE_SELECTOR
#define __IOS_PROHIBITED
#ifndef IBOutlet
#define IBOutlet
#endif
#ifndef IBAction
#define IBAction void
#endif
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#define NS_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
#define NS_SWIFT_NAME(x)
#define NS_REFINED_FOR_SWIFT
#define FOUNDATION_EXPORT extern
#define UIKIT_EXTERN extern
#define FOUNDATION_EXTERN extern
#define CF_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#define CF_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
#define OBJC_BOOL_IS_BOOL 0
#define __BEGIN_DECLS
#define __END_DECLS
#define LDBL_MAX 1e308
#define DBL_MAX 1.7976931348623157e+308
#define INFINITY (__builtin_inff())
#define NAN (__builtin_nanf(""))
#define HUGE_VAL (__builtin_huge_val())
#define M_PI 3.14159265358979323846264338327950288
#define NSEC_PER_SEC 1000000000ull
#define NSEC_PER_MSEC 1000000ull
#define NULL_RESETTABLE
#define _Nullable
#define _Nonnull
#define _Null_unspecified
#define __kindof
#define NS_NOESCAPE
#define __block __block
#define __weak __weak
#define __unsafe_unretained __unsafe_unretained
#define __strong
#define NSZone void
#define __has_include_stub 0
#define DEPRECATED_ATTRIBUTE
#define NS_ROOT_CLASS __attribute__((objc_root_class))
#define __IOS_AVAILABLE(x)
#define __OSX_AVAILABLE(...)
#define UNAVAILABLE_ATTRIBUTE __attribute__((unavailable))
#define NS_VALID_UNTIL_END_OF_SCOPE
#define NS_RETURNS_RETAINED __attribute__((ns_returns_retained))
#define NS_RETURNS_INNER_POINTER
#define NS_CONSUMED
#define NS_CONSUMES_SELF
#define NS_FORMAT_FUNCTION(a,b)
#define __DARWIN_NULL ((void*)0)
#define NIL ((void*)0)
#define YES ((BOOL)1)
#define NO ((BOOL)0)
#define nil ((id)0)
#define Nil ((Class)0)
#define TRUE 1
#define FALSE 0
#define MAXPATHLEN 1024
#define IPHONE_OS_VERSION_MAX_ALLOWED 170000
#define TARGET_OS_IPHONE 1
#define TARGET_OS_IOS 1
#define TARGET_OS_MAC 0
#define TARGET_OS_SIMULATOR 0
#define TARGET_OS_CATALYST 0
#define TARGET_OS_WATCH 0

typedef signed char BOOL;
typedef unsigned char BOOLEAN;
typedef unsigned long NSUInteger;
typedef long NSInteger;
typedef double CGFloat;
typedef struct CGPoint { CGFloat x; CGFloat y; } CGPoint;
typedef struct CGSize { CGFloat width; CGFloat height; } CGSize;
typedef struct CGRect { CGPoint origin; CGSize size; } CGRect;
typedef struct CGVector { CGFloat dx; CGFloat dy; } CGVector;
typedef struct CGAffineTransform { CGFloat a,b,c,d,tx,ty; } CGAffineTransform;
typedef struct UIEdgeInsets { CGFloat top, left, bottom, right; } UIEdgeInsets;
typedef struct _NSRange { NSUInteger location, length; } NSRange;
typedef struct CGColor *CGColorRef;
typedef struct CGImage *CGImageRef;
typedef struct CGContext *CGContextRef;
typedef struct CGPath *CGPathRef;
typedef struct CGGradient *CGGradientRef;
typedef struct CGDataProvider *CGDataProviderRef;
typedef struct __CFString *CFStringRef;
typedef struct __CFNumber *CFNumberRef;
typedef struct __CFDictionary *CFDictionaryRef;
typedef struct __CFArray *CFArrayRef;
typedef struct __CFData *CFDataRef;
typedef struct __CFRunLoop *CFRunLoopRef;
typedef struct __CFRunLoopSource *CFRunLoopSourceRef;
typedef struct __CFRunLoopObserver *CFRunLoopObserverRef;
typedef struct __CFTimeZone *CFTimeZoneRef;
typedef const struct __CFAllocator *CFAllocatorRef;
typedef double CFTimeInterval;
typedef double CFAbsoluteTime;
typedef unsigned long CFOptionFlags;
typedef long CFIndex;
typedef unsigned int CFStringEncoding;
typedef unsigned char UInt8;
typedef signed char SInt8;
typedef unsigned short UInt16;
typedef signed short SInt16;
typedef unsigned int UInt32;
typedef signed int SInt32;
typedef unsigned long long UInt64;
typedef signed long long SInt64;
typedef int32_t OSStatus;
typedef int32_t kern_return_t;
typedef uint32_t mach_port_t;
typedef unsigned int UIBackgroundTaskIdentifier;
typedef NSUInteger UIRectEdge;
typedef NSUInteger UIAutoresizingMask;
typedef NSUInteger UIViewAutoresizing;
typedef NSUInteger NSStringCompareOptions;
typedef double NSTimeInterval;
typedef NSUInteger NSCoderOptions;
typedef uint64_t mach_absolute_time_t;

typedef enum { kCFRunLoopRunFinished = 1, kCFRunLoopRunStopped = 2, kCFRunLoopRunTimedOut = 3, kCFRunLoopRunHandledSource = 4 } CFRunLoopRunResult;
typedef CFStringEncoding CFStringBuiltInEncodings;
#define kCFStringEncodingUTF8 0x08000100
#define kCFStringEncodingUnicode 0x0100

static inline CGRect CGRectMake(CGFloat x, CGFloat y, CGFloat w, CGFloat h) { CGRect r = {{x,y},{w,h}}; return r; }
static inline CGPoint CGPointMake(CGFloat x, CGFloat y) { CGPoint p = {x,y}; return p; }
static inline CGSize CGSizeMake(CGFloat w, CGFloat h) { CGSize s = {w,h}; return s; }
static inline UIEdgeInsets UIEdgeInsetsMake(CGFloat t, CGFloat l, CGFloat b, CGFloat r) { UIEdgeInsets i = {t,l,b,r}; return i; }
static inline CGAffineTransform CGAffineTransformMakeScale(CGFloat sx, CGFloat sy) { CGAffineTransform t = {sx,0,0,sy,0,0}; return t; }
static inline CGAffineTransform CGAffineTransformMakeTranslation(CGFloat x, CGFloat y) { CGAffineTransform t = {1,0,0,1,x,y}; return t; }
static inline CGAffineTransform CGAffineTransformIdentity(void) { CGAffineTransform t = {1,0,0,1,0,0}; return t; }
static inline CGRect CGRectZero_(void) { return CGRectMake(0,0,0,0); }
#define CGRectZero CGRectMake(0,0,0,0)
#define CGPointZero CGPointMake(0,0)
#define CGSizeZero CGSizeMake(0,0)
#define UIEdgeInsetsZero UIEdgeInsetsMake(0,0,0,0)
#define CGAffineTransformIdentity CGAffineTransformIdentity()
#define CGRectNull CGRectMake(INFINITY,INFINITY,0,0)
#define CGRectInfinite CGRectMake(-INFINITY,-INFINITY,INFINITY,INFINITY)
static inline BOOL CGRectIsEmpty(CGRect r) { return r.size.width <= 0 || r.size.height <= 0; }
static inline BOOL CGRectIsNull(CGRect r) { return 0; }
static inline BOOL CGRectIsInfinite(CGRect r) { return 0; }
static inline CGRect CGRectInset(CGRect r, CGFloat dx, CGFloat dy) { return CGRectMake(r.origin.x+dx, r.origin.y+dy, r.size.width-2*dx, r.size.height-2*dy); }
static inline CGRect CGRectOffset(CGRect r, CGFloat dx, CGFloat dy) { return CGRectMake(r.origin.x+dx, r.origin.y+dy, r.size.width, r.size.height); }
static inline CGRect CGRectStandardize(CGRect r) { return r; }
static inline CGRect CGRectIntegral(CGRect r) { return r; }
static inline CGFloat CGRectGetMinX(CGRect r) { return r.size.width < 0 ? r.origin.x + r.size.width : r.origin.x; }
static inline CGFloat CGRectGetMinY(CGRect r) { return r.size.height < 0 ? r.origin.y + r.size.height : r.origin.y; }
static inline CGFloat CGRectGetMidX(CGRect r) { return r.origin.x + r.size.width/2; }
static inline CGFloat CGRectGetMidY(CGRect r) { return r.origin.y + r.size.height/2; }
static inline CGFloat CGRectGetMaxX(CGRect r) { return r.origin.x + r.size.width; }
static inline CGFloat CGRectGetMaxY(CGRect r) { return r.origin.y + r.size.height; }
static inline CGFloat CGRectGetWidth(CGRect r) { return r.size.width < 0 ? -r.size.width : r.size.width; }
static inline CGFloat CGRectGetHeight(CGRect r) { return r.size.height < 0 ? -r.size.height : r.size.height; }
static inline CGRect CGRectUnion(CGRect a, CGRect b) { return a; }
static inline CGRect CGRectIntersection(CGRect a, CGRect b) { return a; }
static inline BOOL CGRectContainsPoint(CGRect r, CGPoint p) { return 0; }
static inline BOOL CGRectIntersectsRect(CGRect a, CGRect b) { return 0; }
static inline BOOL CGPointEqualToPoint(CGPoint a, CGPoint b) { return a.x==b.x && a.y==b.y; }
static inline BOOL CGSizeEqualToSize(CGSize a, CGSize b) { return a.width==b.width && a.height==b.height; }
static inline BOOL CGRectEqualToRect(CGRect a, CGRect b) { return 0; }
static inline CGFloat CGPointDistance(CGPoint a, CGPoint b) { return hypot(a.x-b.x, a.y-b.y); }

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#ifndef ABS
#define ABS(a) ((a)<0?-(a):(a))
#endif

extern double CACurrentMediaTime(void);
extern void NSLog(CFStringRef format, ...);
extern void *dlopen(const char *path, int mode);
extern void *dlsym(void *handle, const char *symbol);
extern char *dlerror(void);
#define RTLD_LAZY 0x1
#define RTLD_NOW 0x2
#define RTLD_GLOBAL 0x8
#define RTLD_LOCAL 0x4
extern void free(void *);
extern void *malloc(size_t);
extern void *calloc(size_t, size_t);
extern int getpid(void);

#endif
