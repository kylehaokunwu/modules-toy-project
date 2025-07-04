#include <iostream>
#include "config.hpp"
#include "non_template_lib.hpp"
#include "template_lib.hpp"

int main()
{
    int magic = demo::get_magic_number();
    std::cout << "Magic number: " << magic << "\n";

    int result = demo::add_magic(100);
    std::cout << "100 + magic = " << result << "\n";

    DEMO_TEST_EQ(result, 142);

    return 0;
}
