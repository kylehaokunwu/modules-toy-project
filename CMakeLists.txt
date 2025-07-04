# File: CMakeLists.txt

cmake_minimum_required(VERSION 3.28)
project(modular_toy_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Option to enable debug build
option(DEMO_DEBUG "Enable debug flags" ON)

if (DEMO_DEBUG)
    add_compile_definitions(DEMO_DEBUG)
endif()

# Include headers globally
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(lib)
add_subdirectory(app)
