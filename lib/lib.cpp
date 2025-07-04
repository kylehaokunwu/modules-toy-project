#include "non_template_lib.hpp"
#include "config.hpp"

namespace demo {

int get_magic_number()
{
#ifdef DEMO_DEBUG
    // Simulate debug-only behavior
    const char* msg = "Debug mode active";
    DEMO_UNUSED(msg); // suppress unused variable warning
#endif

    return 42;
}

}
