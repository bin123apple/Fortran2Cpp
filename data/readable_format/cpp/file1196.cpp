#include <iostream>
#include <functional>
#include <cstdlib>
#include <gtest/gtest.h>

struct Tx {
    int i;
    Tx(int i = 0) : i(i) {} // Constructor to initialize 'i', default to 0 if no argument is provided
};

class T {
public:
    Tx x; // Equivalent to 'type(tx) :: x'
    std::function<Tx(const T&)> ppc; // Procedure pointer equivalent

    T() : x(0) {} // Default constructor initializing 'x' with 0

    // Equivalent to the 'find_x' procedure in Fortran
    static Tx find_x(const T& this_t) {
        return zero;
    }

    // A pointer to the 'zero' target, which will be modified
    static Tx zero;

    // Static method for initializing 'zero'
    static void set_zero(int val) {
        zero = Tx(val);
    }
};

// Initialize the 'zero' static member
Tx T::zero = Tx(0);

TEST(TxTest, FindX) {
    T this_t;
    
    // Test 1
    T::set_zero(1);
    this_t.x = T::find_x(this_t);
    EXPECT_EQ(1, this_t.x.i);
    
    // Test 2
    T::set_zero(2);
    this_t.ppc = T::find_x;
    this_t.x = this_t.ppc(this_t);
    EXPECT_EQ(2, this_t.x.i);
    
    // Test 3
    T::set_zero(3);
    this_t.ppc = &T::find_x; // Assigning member function pointer
    this_t.x = this_t.ppc(this_t);
    EXPECT_EQ(3, this_t.x.i);
    
    // Test 4
    T::set_zero(4);
    this_t.x = T::find_x(this_t); // Direct call to the static class method
    EXPECT_EQ(4, this_t.x.i);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}