#pragma once

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
