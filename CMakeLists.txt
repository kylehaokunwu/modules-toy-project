# =============================================
# Dual-Mode Build System Configuration
# =============================================
# This project supports both traditional header-based builds
# and C++20 module-based builds. The build mode is controlled
# by the DEMO_USE_MODULES option.
#
# Traditional Mode (DEMO_USE_MODULES=OFF):
# - Compiles lib/lib.cpp with header includes
# - Uses visibility attributes for shared library symbols
#
# Module Mode (DEMO_USE_MODULES=ON):
# - Compiles module interface units (.ixx files)
# - Uses C++20 module export for symbol visibility
# - Includes lib/lib.cpp for actual implementations
# =============================================

# File: CMakeLists.txt

cmake_minimum_required(VERSION 3.28)
project(modular_toy_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable modules and file sets
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Option to enable debug build
option(DEMO_DEBUG "Enable debug flags" OFF)

# Option to enable C++20 modules
option(DEMO_USE_MODULES "Enable C++20 modules mode" OFF)

if (DEMO_DEBUG)
    add_compile_definitions(DEMO_DEBUG)
endif()

if (DEMO_USE_MODULES)
    message(STATUS "Building with C++20 modules")
    add_compile_definitions(DEMO_USE_MODULES)
else()
    message(STATUS "Building with traditional headers")
endif()

# Include headers globally
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories conditionally
if(DEMO_USE_MODULES)
    # Build from modules
    add_subdirectory(modules)
else()
    # Build from traditional source
add_subdirectory(lib)
endif()

# App always needs to be built
add_subdirectory(app)
