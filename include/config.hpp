#pragma once

// ========================
// 1. Visibility Macros 🧱
// ========================
#if defined(_MSC_VER)
#  define DEMO_EXPORT __declspec(dllexport)
#else
#  define DEMO_EXPORT __attribute__((visibility("default")))
#endif

// ============================
// 2. Build Configuration ⚙️
// ============================
#define DEMO_HAVE_CXX20_MODULES

#ifndef DEMO_WITH_FEATURE_X
#define DEMO_WITH_FEATURE_X
#endif

#ifndef DEMO_DEBUG
#define DEMO_DEBUG
#endif

// =======================================
// 3. Compiler/Platform Abstractions 🔁
// =======================================
#if defined(__GNUC__)
#  define DEMO_FORCEINLINE inline __attribute__((always_inline))
#else
#  define DEMO_FORCEINLINE __forceinline
#endif

#define DEMO_UNUSED(x) (void)x

// ===========================
// 4. Testing Macros 🧪
// ===========================
#include <cassert>
#define DEMO_ASSERT(cond) assert(cond)
#define DEMO_TEST_EQ(a, b) assert((a) == (b))

// ============================================
// 5. Feature Detection & Configuration 🔍
// ============================================
#define DEMO_HAVE_EXTERNAL_LIB

// ===================================
// 6. Preprocessor Utility Macros 🔄
// ===================================
#define DEMO_PP_STRINGIZE(x) #x
#define DEMO_PP_CAT(a, b) a##b
