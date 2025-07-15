// =============================================
// Traditional Implementation File
// =============================================
// This file contains the implementation of non-template functions
// that are declared in include/non_template.hpp. It is used in
// traditional header-based builds and also linked into module
// builds to provide the actual function implementations.
// =============================================

#include "non_template.hpp"
#include "config.hpp"
#include <iostream>

namespace demo {

int get_magic_number()
{
#ifdef DEMO_DEBUG
    // Simulate debug-only behavior
    const char* msg = "Debug mode active";
    DEMO_UNUSED(msg); // suppress unused variable warning
    std::cout << "Getting magic number..." << std::endl;
#endif

    return 42;
}

}
