extern void MSHookMessageEx(Class _c, SEL s, IMP r, IMP *o);
#define SMT_ORIG_CALLBACK __smt_orig_cb
#define %hook(cls) \
    static id __smt_orig_cb(id self, SEL _cmd, ...); \
    static id __smt_hookbody_##cls(id self, SEL _cmd, ...) __asm__("__smt_hookbody_" #cls); \
    @interface __SMT_HOOKNAME(cls) : cls @end \
    @implementation __SMT_HOOKNAME(cls) \
    + (Class)__smt_hookedClass { return cls; }
#define %end @end
