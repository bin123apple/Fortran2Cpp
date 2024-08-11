#include <gtest/gtest.h>

// Define the namespace, struct, and its members all in one place
namespace mod_class_fitness_calculator_exit_code {

    struct ClassFitnessCalculatorExitCode {
        inline static const int SUCCESS = 0;
        inline static const int FAIL_AND_GIVE_UP = 1;
        inline static const int FAIL_AND_TRY_AGAIN = 2;
    };

} // namespace mod_class_fitness_calculator_exit_code

// Unit tests using Google Test
class ClassFitnessCalculatorExitCodeTest : public ::testing::Test {
protected:
    mod_class_fitness_calculator_exit_code::ClassFitnessCalculatorExitCode codes;
};

TEST_F(ClassFitnessCalculatorExitCodeTest, ExitCodes) {
    EXPECT_EQ(codes.SUCCESS, 0);
    EXPECT_EQ(codes.FAIL_AND_GIVE_UP, 1);
    EXPECT_EQ(codes.FAIL_AND_TRY_AGAIN, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}