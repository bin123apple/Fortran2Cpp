#include <iostream>
#include <vector>
#include <cassert>

// Function declaration
void rysfun(std::vector<double>& ff);

int main() {
    std::vector<double> ff(13, 0.0); // Explicitly initialize array to zeros

    // Call the function
    rysfun(ff);

    // Verify the results
    bool all_correct = true;
    for (size_t i = 0; i < ff.size(); ++i) {
        if (i < 4) {
            if (ff[i] != 1.0) {
                all_correct = false;
                break;
            }
        } else {
            if (ff[i] != 0.0) {
                all_correct = false;
                break;
            }
        }
    }

    if (all_correct) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}

// Function definition
void rysfun(std::vector<double>& ff) {
    size_t m = 4;

    // Assuming the vector is already initialized to zeros in main
    while (m >= 1) {
        ff[m-1] = 1.0;
        m--;
    }
}