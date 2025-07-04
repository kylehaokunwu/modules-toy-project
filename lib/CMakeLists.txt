add_library(demo_lib SHARED lib.cpp)
target_include_directories(demo_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(demo_lib PUBLIC DEMO_WITH_FEATURE_X)
