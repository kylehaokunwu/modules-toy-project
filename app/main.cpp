// =============================================
// Example Application
// =============================================
// This application demonstrates how to use the library
// in both traditional header-based and C++20 module-based builds.
// It includes demo.hpp which provides a unified interface
// regardless of the underlying build mode.
// =============================================

#include <iostream>
#include "demo.hpp"

int main()
{
    int magic = demo::get_magic_number();
    std::cout << "Magic number: " << magic << "\n";

    int result = demo::add_magic(100);
    std::cout << "100 + magic = " << result << "\n";

    DEMO_TEST_EQ(result, 142); // downstream users directly use macros form config.hpp

    return 0;
}
