#pragma once

// =============================================
// User-Facing Library Interface
// =============================================
// This is the single entry point for library users.
// It provides a unified interface that works for both
// traditional header-based builds and C++20 module builds.
// Users only need to include this header regardless of
// which build mode is being used.
// =============================================

#if defined(DEMO_USE_MODULES)
// ============================================
// Module Mode - Import C++20 Module
// ============================================
#include "config.hpp" //  because modules don't export macros and user code uses DEMO_TEST_EQ
import Demo;
#else
// ============================================
// Traditional Header Mode - Include Headers
// ============================================
#include "config.hpp"
#include "non_template.hpp"
#include "template.hpp"
#endif
