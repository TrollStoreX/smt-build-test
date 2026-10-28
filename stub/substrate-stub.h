#ifndef SMT_SUBSTRATE_STUB_H
#define SMT_SUBSTRATE_STUB_H

/*
 * 极简 Logos shim（不依赖 Theos / Substrate）。
 *
 * tools/logosify.py 先把
 *      %hook(Class)  ->  SMT_BEGIN(Class)
 *      %end          ->  SMT_END(Class)
 *      %orig         ->  SMT_ORIG
 * 改写后再交给 clang（clang 不允许宏名里带 %）。
 *
 * 机制：
 *   SMT_BEGIN 生成子类 __SMT_HOOK_Class : Class，方法体按原签名书写；
 *   SMT_END 用运行时 API 把子类上的每个方法「搬」到父类：
 *     记下父类原 IMP，然后 method_setImplementation 成子类方法。
 *   钩子方法里的 SMT_ORIG(self, _cmd, ...) 就是调用父类的原 IMP。
 */

extern id objc_msgSend(id self, SEL op, ...);
extern IMP method_getImplementation(Method m);
extern void method_setImplementation(Method m, IMP imp);
extern Method class_getInstanceMethod(Class cls, SEL name);
extern unsigned int method_getNumberOfArguments(Method m);

// 由 HookRegistry.m 实现
extern void __smt_hook_apply(Class hookedClass, Class hookClass);

#define SMT_PASTE2(a, b) a##b
#define SMT_PASTE(a, b) SMT_PASTE2(a, b)
#define __SMT_HOOK_NAME(cls) SMT_PASTE(__SMT_HOOK_, cls)
#define __SMT_CTOR_NAME(cls) SMT_PASTE(__SMT_CTOR_, cls)

/* 钩子方法里的 %orig —— 调用原实现 */
#define SMT_ORIG __smt_orig

/* %hook(Class) */
#define SMT_BEGIN(cls) \
    @interface __SMT_HOOK_NAME(cls) : cls \
    @end \
    @implementation __SMT_HOOK_NAME(cls) \
    + (Class)__smt_hookedClass { return cls; } \
    - (void)__smt_marker_##cls { }

/* %end */
#define SMT_END(cls) \
    @end \
    __attribute__((constructor)) static void __SMT_CTOR_NAME(cls)(void) { \
        __smt_hook_apply([cls class], [__SMT_HOOK_NAME(cls) class]); \
    }

#endif
