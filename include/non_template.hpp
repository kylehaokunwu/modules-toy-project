#pragma once

// =============================================
// Non-Template Function Declarations
// =============================================
// This header declares non-template functions that are
// implemented in the traditional source file (lib/lib.cpp).
// These functions use visibility attributes for shared library
// exports in header-based builds.
// =============================================

#include "config.hpp"
#include <iostream>

namespace demo {

// - DEMO_EXPORT: visibility attribute for shared library builds
// - DEMO_EXPORT_FUNCTION: expand to export keyword and extern "C++" for module builds
DEMO_EXPORT DEMO_EXPORT_FUNCTION int get_magic_number();

} // namespace demo
