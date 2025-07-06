// =============================================
// Module interface unit
// Converted from: include/template.hpp
// Script: convert_header_to_module.py
// =============================================

module;
#include "config.hpp"

export module Demo : interface_partition_template;
export import :interface_partition_non_template;

export {
namespace demo {

#if defined(DEMO_WITH_FEATURE_X)

template <typename T>
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
} // end export
