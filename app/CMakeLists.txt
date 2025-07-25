# =============================================
# Example Application Build Configuration
# =============================================
# This file configures the build for the example application.
# It creates an executable that links against the demo library
# and works with both traditional and module-based builds.
# =============================================

add_executable(demo_app main.cpp)
target_link_libraries(demo_app PRIVATE demo_lib)
