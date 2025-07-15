// =============================================
// Non-Template Module Interface Unit
// =============================================
// This module interface unit declares non-template functions
// that are implemented in the traditional lib.cpp file.
// The 'extern "C++"' ensures proper name mangling and linking
// to the compiled binary implementation.
// =============================================

module;
#include <iostream>
#include "config.hpp"

export module Demo : interface_partition_non_template;

export {
namespace demo {

// Declare non-template function with extern linkage
// The actual implementation is in lib/lib.cpp
extern "C++" DEMO_EXPORT int get_magic_number();

} // namespace demo
} // end export
