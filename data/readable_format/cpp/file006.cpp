#include <iostream>

class m1 {
public:
    static int i; // Declare static member variable

    static void set_i(int val) {
        i = val; // Define method to set `i`
    }

    static int get_i() {
        return i; // Define method to get `i`
    }
};

// Initialize the static member variable `i` of class `m1`
int m1::i = 0;

int main() {
    // Manual test for the functionality of m1

    // Test setting and getting `i`
    m1::set_i(5); // Set `i` to 5
    int testValue = m1::get_i(); // Get the value of `i`

    // Verify the test
    if (testValue == 5) {
        std::cout << "Test Passed: m1::i is 5" << std::endl;
    } else {
        std::cout << "Test Failed: m1::i is not 5. It is " << testValue << std::endl;
    }

    return 0;
}