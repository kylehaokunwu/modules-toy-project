// =============================================
// Module implementation unit
// Converted from: lib/lib.cpp
// Script: convert_source_to_module.py
// =============================================

module;
#include "config.hpp"

module Demo : implementation_partition_lib;
import :interface_partition_non_template;

namespace demo {

extern "C++" int get_magic_number();

}
