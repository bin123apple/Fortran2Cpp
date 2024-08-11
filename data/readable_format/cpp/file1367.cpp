#include <iostream>
#include <array>
#include <algorithm>

// Definition of the Block struct and its members, mimicking the Fortran COMMON block and EQUIVALENCE
struct Block {
    union {
        struct {
            int a, b; // a and b are normal integers.
        };
        struct {
            int n1, n2; // n1 and n2 are part of the equivalence with a and b respectively.
        };
    };
    union {
        struct {
            int c, d; // c and d are normal integers.
        };
        struct {
            int n3, n4; // n3 and n4 are part of the equivalence with c and d respectively.
        };
    };
} block;

// Function to run a basic "unit test" to verify the values in the Block struct
void test_block_values() {
    // Creating an array to hold the values for comparison
    std::array<int, 4> n = {block.n1, block.n2, block.n3, block.n4};
    std::array<int, 4> expected_values = {1, 2, 3, 4};

    // Check if the block's values are as expected
    if (std::equal(n.begin(), n.end(), expected_values.begin())) {
        std::cout << "Test Passed: Values are as expected." << std::endl;
    } else {
        std::cout << "Test Failed: Values are not as expected." << std::endl;
    }
}

int main() {
    // Initializing the values in the Block
    block.a = 1;
    block.b = 2;
    block.c = 3;
    block.d = 4;
    
    // Run the basic test
    test_block_values();

    return 0;
}