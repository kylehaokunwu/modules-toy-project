#pragma once

// =============================================
// EXPERIMENTAL: Dual-Mode Template Header
// =============================================
// This header uses preprocessor conditions to act as:
// 1. Traditional header (when DEMO_USE_MODULES is OFF)
// 2. Module interface unit (when DEMO_USE_MODULES is ON)
//
// In module mode, this file is compiled as a translation unit
// and exports template functions for the Demo module.
// =============================================

#if DEMO_USE_MODULES

// Module mode: This header becomes a module interface unit
module;
#include "config.hpp"

export module Demo : interface_partition_template;
export import :interface_partition_non_template;

// Redefine DEMO_EXPORT to 'export' for module export
#undef DEMO_EXPORT
#define DEMO_EXPORT export

#else

// Traditional header mode: Normal includes and visibility attributes
#include "config.hpp"
#include "non_template.hpp"  // for get_magic_number()

// Redefine DEMO_EXPORT to nothing for header mode
#undef DEMO_EXPORT
#define DEMO_EXPORT

#endif

namespace demo {

#if defined(DEMO_WITH_FEATURE_X)

// DEMO_EXPORT expands to 'export' in module mode, nothing in header mode
DEMO_EXPORT template <typename T>
DEMO_FORCEINLINE T add_magic(T input)
{
    int magic = get_magic_number();  // call the non-template function
    DEMO_ASSERT(magic == 42);        // use test macro

    T result = input + static_cast<T>(magic);
    DEMO_TEST_EQ(result, input + 42);  // simple runtime check

    return result;
}

#endif // DEMO_WITH_FEATURE_X

} // namespace demo
