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

DEMO_EXPORT int get_magic_number();

} // namespace demo
