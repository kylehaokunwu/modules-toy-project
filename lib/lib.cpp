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
