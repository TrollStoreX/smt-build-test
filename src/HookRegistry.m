#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#include <string.h>

/*
 * 把 __SMT_HOOK_<Class> 子类里定义的方法搬到 <Class> 上，并保存原 IMP，
 * 供钩子方法里的 SMT_ORIG(self, _cmd, ...) 调用。
 */

#define SMT_MAX_HOOKS 32

typedef struct {
    Class hookedClass;
    SEL selector;
    IMP original;
} SMTHookRecord;

static SMTHookRecord gHookRecords[SMT_MAX_HOOKS];
static int gHookCount;

IMP __smt_hook_original(Class hookedClass, SEL selector);   /* 供调试 */

static IMP __smt_orig_lookup(Class hookedClass, SEL selector) {
    for (int i = 0; i < gHookCount; i++) {
        if (gHookRecords[i].hookedClass == hookedClass && sel_isEqual(gHookRecords[i].selector, selector)) {
            return gHookRecords[i].original;
        }
    }
    return NULL;
}

/* 由宏展开调用 */
void __smt_hook_apply(Class hookedClass, Class hookClass) {
    if (!hookedClass || !hookClass) return;

    unsigned int count = 0;
    Method *methods = class_copyMethodList(hookClass, &count);

    for (unsigned int i = 0; i < count; i++) {
        SEL selector = method_getName(methods[i]);
        const char *name = sel_getName(selector);

        // 跳过 +__smt_hookedClass（类方法不在列表里）、占位方法和 dealloc 之外的东西
        if (strncmp(name, "__smt_", 6) == 0) continue;

        Method target = class_getInstanceMethod(hookedClass, selector);
        if (!target) continue;

        IMP original = method_getImplementation(target);
        if (gHookCount < SMT_MAX_HOOKS) {
            gHookRecords[gHookCount].hookedClass = hookedClass;
            gHookRecords[gHookCount].selector = selector;
            gHookRecords[gHookCount].original = original;
            gHookCount++;
        }

        method_setImplementation(target, method_getImplementation(methods[i]));
    }

    if (methods) free(methods);
}

/* 在钩子方法里查明「我这个类 + 这个 selector 的原实现」 */
static IMP __smt_orig_imp(id self, SEL _cmd) {
    Class cls = object_getClass(self);
    // 沿父类链找到被 hook 的那个类
    for (Class c = cls; c != Nil; c = class_getSuperclass(c)) {
        IMP imp = __smt_orig_lookup(c, _cmd);
        if (imp) return imp;
    }
    return NULL;
}
