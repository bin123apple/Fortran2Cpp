#include <gtest/gtest.h>

// Define the namespace and structure within the same file
namespace aot_fun_declaration_module {

    struct aot_fun_type {
        int handle = 0;
        int arg_count = 0;

        // Constructor (optional, since default member initializers are used)
        aot_fun_type(int h = 0, int a = 0) : handle(h), arg_count(a) {}
    };

} // namespace aot_fun_declaration_module

// Unit tests
using namespace aot_fun_declaration_module;

TEST(AOTFunTypeTest, DefaultInitialization) {
    aot_fun_type default_fun;
    EXPECT_EQ(default_fun.handle, 0);
    EXPECT_EQ(default_fun.arg_count, 0);
}

TEST(AOTFunTypeTest, CustomInitialization) {
    aot_fun_type custom_fun(1, 5);
    EXPECT_EQ(custom_fun.handle, 1);
    EXPECT_EQ(custom_fun.arg_count, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}