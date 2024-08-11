#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Declare a function to run the logic we want to test.
int runTestLogic() {
    const int N = 10;
    std::vector<int> random_array(N);
    std::vector<int> a(N);
    int sa, result;
    std::vector<float> tmp(N);

    result = 0;
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < N; ++i) {
        tmp[i] = static_cast<float>(std::rand()) / RAND_MAX;
    }

    for (int i = 0; i < N; ++i) {
        random_array[i] = static_cast<int>(tmp[i] * 10000);
    }

    for (int i = 0; i < N; ++i) {
        a[i] = random_array[i];
    }

    int ans_val = 0;
    for (int i = 0; i < N; ++i) {
        ans_val |= random_array[i];
    }

    sa = 0;
    for (int i = 0; i < N; ++i) {
        sa |= a[i];
    }

    if (sa != ans_val) {
        result = -1;
    }

    if (result == 0) {
        std::cout << "PASS" << std::endl;
        return 0;
    } else {
        std::cout << "ERROR" << std::endl;
        return 1;
    }
}

// This is the entry point for your program.
int main() {
    const int test_runs = 100;
    int testResult = 0;

    for (int i = 0; i < test_runs; ++i) {
        testResult = runTestLogic();
        if (testResult != 0) {
            std::cerr << "Test failed on iteration " << i + 1 << std::endl;
            return 1;  // Return an error code.
        }
    }
    std::cout << "All tests passed!" << std::endl;
    return 0;  // Success
}