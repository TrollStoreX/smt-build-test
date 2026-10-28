#import <Foundation/Foundation.h>

/*
 * Theos 兼容宏（仅用于在没有 Theos / iOS SDK 的环境下编译本 tweak）。
 */

#define CONFIG(x) (x)
#define THEOS_PACKAGE_SCHEME_ROOTLESS 0
#define THEOS_PACKAGE_SCHEME_ROOTHIDE 0
#define PACKAGE_NAME "ShowMyTouches"

#include <objc/runtime.h>

#pragma mark - %hook / %end

#define __SMT_PRIMITIVE_EXPAND(...) __VA_ARGS__

#include "substrate-stub.h"
