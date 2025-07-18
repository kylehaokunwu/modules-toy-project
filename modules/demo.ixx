// =============================================
// Primary Module Interface Unit
// =============================================
// This is the main entry point for the Demo module.
// It imports and re-exports all module partitions, making
// their symbols available to consumers who do 'import Demo;'
// =============================================

module;

// Include all system headers in global module fragment to prevent ODR violations
#include "system_headers.hpp"

// Define module-specific macros before including config
#define DEMO_BUILD_MODULE
#include "config.hpp"

export module Demo;

// Include project headers after module declaration
#include "template.hpp"
#include "non_template.hpp"