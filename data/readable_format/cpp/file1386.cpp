#include <gtest/gtest.h>
#include <vector>

class MyTypes {
public:
    static int i_priv; // Static member to hold the private integer.

    static int get_i() {
        return i_priv; // Return the static member variable.
    }

    class MyType {
    public:
        int dummy; // Public integer member.

        MyType(int d = 0) : dummy(d) {} // Constructor with default value.

        int i() const { // Marked as const to indicate it doesn't modify the object.
            return MyTypes::get_i(); // Access the static member of the enclosing class.
        }
    };
};

// Initialize the static member variable.
int MyTypes::i_priv = 13;

bool test() {
    MyTypes::MyType a; // Default constructed with dummy = 0
    const MyTypes::MyType a_const(0); // const object to test const correctness

    std::vector<int> x(MyTypes::get_i()); // Use the static function to set vector size
    std::vector<int> y(a.i()); // Use member function i() to set vector size
    std::vector<int> z(a_const.i()); // This should now compile without error.

    // Return true if all vectors have the expected size of 13, false otherwise.
    return (x.size() == 13) && (y.size() == 13) && (z.size() == 13);
}

// Test case for get_i() function.
TEST(MyTypesTest, GetI) {
    EXPECT_EQ(13, MyTypes::get_i());
}

// Test case for testing the sizes of vectors x, y, and z in the test function.
TEST(MyTypesTest, ArraySizes) {
    EXPECT_TRUE(test());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}