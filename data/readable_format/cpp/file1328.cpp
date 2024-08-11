#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

// Assuming ME_mj is a constant representing the size of the arrays
const int ME_mj = 5;

// Function declaration
void memcf6(float& backfl, const std::vector<float>& mask, const std::vector<float>& back, float pixsol, int& ierr);

// Function definition
void memcf6(float& backfl, const std::vector<float>& mask, const std::vector<float>& back, float pixsol, int& ierr) {
    if (ierr != 0) {
        return; // Equivalent to the Fortran 'goto 999'
    }

    float sum = 0.0f;
    for (int pixel = 0; pixel < ME_mj; ++pixel) { // Adjust the loop for 0-based indexing
        sum += mask[pixel] * back[pixel];
    }
    
    backfl = sum * pixsol;
    // Label 999 continue; is replaced by just returning from the function
}

// Unit test function
void testMemcf6() {
    std::vector<float> mask = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> back = {2.0, 2.0, 2.0, 2.0, 2.0};
    float backfl;
    float pixsol = 2.0;
    int ierr;

    // Test 1: Normal operation
    ierr = 0;
    memcf6(backfl, mask, back, pixsol, ierr);
    assert(std::fabs(backfl - 60.0) < 1e-5); // Using a small epsilon for floating point comparison
    std::cout << "Test 1 passed: backfl = " << backfl << std::endl;

    // Test 2: Error handling, expecting no change in backfl if it's initialized to a known value
    backfl = 0.0; // Resetting backfl
    ierr = 1;
    memcf6(backfl, mask, back, pixsol, ierr);
    assert(backfl == 0.0); // Assuming function does nothing on error
    std::cout << "Test 2 passed: backfl = " << backfl << std::endl;
}

int main() {
    testMemcf6();
    return 0;
}