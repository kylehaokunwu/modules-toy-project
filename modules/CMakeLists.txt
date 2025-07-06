# Build shared library from C++20 modules using file sets
add_library(demo_lib)

target_sources(demo_lib
    PUBLIC
        FILE_SET demo_lib_public_sources TYPE CXX_MODULES FILES
            demo.ixx              # primary module interface unit
            non_template.ixx      # module interface unit
            template.ixx          # module interface unit
    PRIVATE
        FILE_SET demo_lib_private_sources TYPE CXX_MODULES FILES
            lib.ixx               # module implementation unit
)


target_compile_definitions(demo_lib PUBLIC DEMO_WITH_FEATURE_X)
