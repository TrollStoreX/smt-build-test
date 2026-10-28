#ifndef SMT_STUB_OBJC_RUNTIME_H
#define SMT_STUB_OBJC_RUNTIME_H

#include <stddef.h>
#include <stdint.h>

typedef struct objc_class *Class;
typedef struct objc_object { Class isa; } *id;
typedef struct objc_selector *SEL;
typedef id (*IMP)(id, SEL, ...);
typedef struct objc_method *Method;
typedef struct objc_ivar *Ivar;
typedef struct objc_property *objc_property_t;
typedef struct objc_category *Category;

#define Nil ((Class)0)
#define nil ((id)0)

typedef struct { long version_b; long version; const char *name; } objc_method_description;

#define OBJC_ASSOCIATION_ASSIGN 0
#define OBJC_ASSOCIATION_RETAIN_NONATOMIC 1
#define OBJC_ASSOCIATION_COPY_NONATOMIC 3
#define OBJC_ASSOCIATION_RETAIN 01401
#define OBJC_ASSOCIATION_COPY 01403

id objc_getClass(const char *name);
Class objc_lookUpClass(const char *name);
Class objc_getMetaClass(const char *name);
void objc_setAssociatedObject(id object, const void *key, id value, long policy);
id objc_getAssociatedObject(id object, const void *key);
void objc_removeAssociatedObjects(id object);
id objc_msgSend(id self, SEL op, ...);
SEL sel_registerName(const char *str);
const char *sel_getName(SEL sel);
BOOL sel_isEqual(SEL a, SEL b);
Class object_getClass(id obj);
Class class_getSuperclass(Class cls);
Method class_getInstanceMethod(Class cls, SEL name);
Method *class_copyMethodList(Class cls, unsigned int *outCount);
SEL method_getName(Method m);
IMP method_getImplementation(Method m);
void method_setImplementation(Method m, IMP imp);
const char *method_getTypeEncoding(Method m);
BOOL class_addMethod(Class cls, SEL name, IMP imp, const char *types);
unsigned int method_getNumberOfArguments(Method m);
Class objc_allocateClassPair(Class superclass, const char *name, size_t extraBytes);
void objc_registerClassPair(Class cls);
id class_createInstance(Class cls, size_t extra);
void *object_getIndexedIvars(id obj);
IMP class_getMethodImplementation(Class cls, SEL name);
void objc_enumerationMutation(id obj);
void objc_storeStrong(id *location, id obj);
id objc_retain(id o);
void objc_release(id o);
id objc_autorelease(id o);
id objc_autoreleaseReturnValue(id o);
id objc_retainAutoreleasedReturnValue(id o);
id objc_retainAutoreleaseReturnValue(id o);
id objc_alloc(Class c);
id objc_loadWeakRetained(id *location);
void objc_initWeak(id *location, id obj);
void objc_destroyWeak(id *location);
BOOL object_isClass(id obj);

#endif
