// =============================================
// Module interface unit
// Converted from: include/non_template.hpp
// Script: convert_header_to_module.py
// =============================================

module;
#include <iostream>
#include "config.hpp"

export module Demo : interface_partition_non_template;

export {
namespace demo {

DEMO_EXPORT int get_magic_number();

} // namespace demo
} // end export
