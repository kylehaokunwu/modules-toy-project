#pragma once

// =============================================
// User-Facing Library Interface
// =============================================
// This is the single entry point for library users.
// It provides a unified interface that works for both
// traditional header-based and C++20 module builds.
// Users only need to include this header regardless of
// which build mode is being used.
// =============================================


#include "config.hpp"

#if defined(DEMO_USE_MODULES)
// ============================================
// Module Mode - Import C++20 Module
// ============================================
// In module mode, import the Demo module and include config.hpp
// for macros that aren't exported by modules (like DEMO_TEST_EQ)
import Demo;
#else
// ============================================
// Traditional Header Mode - Include Headers
// ============================================
// In header mode, include all necessary headers directly
#include "non_template.hpp"
#include "template.hpp"
#endif
 