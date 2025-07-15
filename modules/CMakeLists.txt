# =============================================
# Module Build Configuration
# =============================================
# This file configures the build when DEMO_USE_MODULES=ON.
# It compiles module interface units (.ixx) and includes
# the traditional implementation file (lib.cpp) to provide
# the actual function implementations.
# =============================================

# Build shared library from C++20 modules using file sets
add_library(demo_lib)

target_sources(demo_lib
    PUBLIC
        FILE_SET demo_lib_public_sources TYPE CXX_MODULES FILES
            demo.ixx              # primary module interface unit
            non_template.ixx      # module interface unit for non-template functions
            template.ixx          # module interface unit wrapper for template functions
    PRIVATE
        ${PROJECT_SOURCE_DIR}/lib/lib.cpp  # traditional implementation file
)

target_compile_definitions(demo_lib PUBLIC DEMO_WITH_FEATURE_X)
