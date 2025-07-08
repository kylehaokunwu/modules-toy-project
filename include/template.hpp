#pragma once


#if DEMO_USE_MODULES

module;
#include "config.hpp"

export module Demo : interface_partition_template;
export import :interface_partition_non_template;

#define DEMO_EXPORT export

#else

#include "config.hpp"
#include "non_template.hpp"  // for get_magic_number()
#define DEMO_EXPORT 

#endif


namespace demo {

#if defined(DEMO_WITH_FEATURE_X)

template <typename T>
DEMO_EXPORT T add_magic(T input)
{
    int magic = get_magic_number();  // call the non-template function
    DEMO_ASSERT(magic == 42);        // use test macro

    T result = input + static_cast<T>(magic);
    DEMO_TEST_EQ(result, input + 42);  // simple runtime check

    return result;
}

#endif // DEMO_WITH_FEATURE_X

} // namespace demo
