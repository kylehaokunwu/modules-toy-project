#pragma once

#include "config.hpp"
#include "non_template_lib.hpp"  // for get_magic_number()

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

}
