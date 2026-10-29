#ifndef SMT_ROOTHIDE_COMPAT_H
#define SMT_ROOTHIDE_COMPAT_H
/* rootless/roothide 兼容层：sideload 构建里 rootDir 就是根目录 */
#ifndef JBROOT
#define JBROOT "/"
#endif
static inline const char *rootfs_get(const char *path) { return path; }
#endif
