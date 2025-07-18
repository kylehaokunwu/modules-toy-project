#pragma once

// =============================================
// Template Function Declarations
// =============================================
// This header declares template functions that are
// implemented inline. These templates use visibility
// attributes for shared library exports in header-based builds.
// =============================================

#include "config.hpp"
#include "non_template.hpp"  // for get_magic_number()

namespace demo {

#if defined(DEMO_WITH_FEATURE_X)

// Template function with dual export support:
// - DEMO_MODULE_EXPORT: export keyword for module builds
// - DEMO_FORCEINLINE: compiler hint for inline optimization
DEMO_MODULE_EXPORT template <typename T>
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
