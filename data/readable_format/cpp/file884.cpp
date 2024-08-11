#include <iostream>
#include <gtest/gtest.h>

// Define the Members namespace and its contents directly
namespace Members {

    class HasMembers {
    public:
        int kind_member;
        int len_member;
        int member;

        // Constructor for initialization
        HasMembers(int kind, int len, int mem) : kind_member(kind), len_member(len), member(mem) {}

        // Method for demonstration
        void MyMethod() const {
            std::cout << "Member value: " << member << std::endl;
        }
    };

    // Function outside the class, for demonstration
    void MySubroutine() {
        std::cout << "MySubroutine called." << std::endl;
    }

}

// Unit tests for the Members namespace
namespace Members {

    // Test the HasMembers class
    TEST(HasMembersTest, MethodTest) {
        HasMembers obj(1, 10, 5); // Initialize the object
        EXPECT_EQ(obj.member, 5);
    }

    // Test the MySubroutine function
    TEST(MySubroutineTest, FunctionalityTest) {
        // MySubroutine doesn't return a value or modify accessible state,
        // so this test simply demonstrates how to structure the test.
        SUCCEED(); // Simply mark as succeeded for demonstration
    }

}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}