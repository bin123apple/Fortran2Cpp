#include <gtest/gtest.h>

// Define the TemplateModule class in the same file
class TemplateModule {
public:
    TemplateModule() : var1(0), var2(0) {}

    void Sub1(int par1, float& par2, int& par3) {
        // Example implementation for testing
        par2 += 1.0f;
        par3 = 2;
    }

    float Fun1() {
        // Example implementation for testing
        return 10.0f;
    }

private:
    int var1;
    int var2;

    void Sub2() {
        // Placeholder for private subroutine
    }
};

// Unit tests using Google Test framework
TEST(TemplateModuleTest, TestFun1) {
    TemplateModule module;
    float result = module.Fun1();
    EXPECT_FLOAT_EQ(result, 10.0f); // Assuming Fun1 is expected to return 10.0
}

TEST(TemplateModuleTest, TestSub1) {
    TemplateModule module;
    float par2 = 5.0f;
    int par3;
    module.Sub1(1, par2, par3);
    EXPECT_FLOAT_EQ(par2, 6.0f); // Assuming Sub1 modifies par2 to 6.0
    EXPECT_EQ(par3, 2); // Assuming Sub1 sets par3 to 2
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}