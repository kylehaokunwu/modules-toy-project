# =============================================
# Traditional Header-Based Build Configuration
# =============================================
# This file configures the build when DEMO_USE_MODULES=OFF.
# It builds a shared library from traditional source files
# and headers, using visibility attributes for symbol export.
# =============================================

add_library(demo_lib SHARED lib.cpp)
target_include_directories(demo_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(demo_lib PUBLIC DEMO_WITH_FEATURE_X)
