// =============================================
// Module implementation unit
// Converted from: lib/lib.cpp
// Script: convert_source_to_module.py
// =============================================

module;
#include <iostream>
#include "config.hpp"

module Demo : implementation_partition_lib;
import :interface_partition_non_template;

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
