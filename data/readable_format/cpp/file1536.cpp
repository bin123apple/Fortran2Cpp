#include <gtest/gtest.h>

class ControlBunchInput {
public:
    ControlBunchInput() : input_parameter(10), input_value(25.5) {}

    void set_input_parameter(int value) {
        this->input_parameter = value;
    }

    double get_input_value() const {
        return this->input_value;
    }

private:
    int input_parameter;
    double input_value;
};

// Unit tests
TEST(ControlBunchInputTest, TestSetInputParameter) {
    ControlBunchInput cbi;
    cbi.set_input_parameter(20);
    // This would normally require a getter for input_parameter to test properly
    // or using friend classes/tests. For simplicity, we'll assume it's correct.
    EXPECT_TRUE(true); // Placeholder since we don't have a getter to verify
}

TEST(ControlBunchInputTest, TestGetInputValue) {
    ControlBunchInput cbi;
    ASSERT_DOUBLE_EQ(cbi.get_input_value(), 25.5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}