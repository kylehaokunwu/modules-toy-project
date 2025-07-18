#pragma once

// =============================================
// Project Configuration and Platform Abstractions
// =============================================
// This header provides all project-wide configuration macros,
// platform abstractions, and build-time definitions.
//
// Contents:
// - Visibility macros for shared library exports
// - Build configuration flags (C++20 modules, features, debug)
// - Compiler/platform abstractions (inline, unused variables)
// - Testing and assertion macros
// - Feature detection and utility macros
// =============================================

// ========================
// 1. Visibility Macros 
// ========================
// Used in traditional header-based/shared-library builds
#if defined(_MSC_VER)
#  define DEMO_EXPORT __declspec(dllexport)
#else
#  define DEMO_EXPORT __attribute__((visibility("default")))
#endif

// Used only in module interface files (e.g. demo.ixx)
#ifdef DEMO_BUILD_MODULE
#  define DEMO_MODULE_EXPORT export  // Export symbols from module interface
#  undef DEMO_EXPORT
#  define DEMO_EXPORT                 // Empty in module mode (no visibility needed)
#else
#  define DEMO_MODULE_EXPORT          // Empty in header mode (no export needed)
#endif

// ============================
// 2. Build Configuration 
// ============================
#define DEMO_HAVE_CXX20_MODULES

#ifndef DEMO_WITH_FEATURE_X
#define DEMO_WITH_FEATURE_X
#endif

// =======================================
// 3. Compiler/Platform Abstractions 
// =======================================
#if defined(__GNUC__)
#  define DEMO_FORCEINLINE inline __attribute__((always_inline))
#else
#  define DEMO_FORCEINLINE __forceinline
#endif

#define DEMO_UNUSED(x) (void)x

// ===========================
// 4. Testing Macros 
// ===========================
#include <cassert>
#define DEMO_ASSERT(cond) assert(cond)
#define DEMO_TEST_EQ(a, b) assert((a) == (b))

// ============================================
// 5. Feature Detection & Configuration 
// ============================================
#define DEMO_HAVE_EXTERNAL_LIB

// ===================================
// 6. Preprocessor Utility Macros 
// ===================================
#define DEMO_PP_STRINGIZE(x) #x
#define DEMO_PP_CAT(a, b) a##b

