#include <iostream>
#include <openacc.h>

// The function to be tested
void oacc1(int& result) {
    const int n = 5;
    int a = 1;
    result = 0;

    #pragma acc parallel loop reduction(+:result)
    for (int i = 1; i <= n; i++) {
        result += a;
    }
}

// Manual test for the function
void test_oacc1() {
    int result;
    oacc1(result);
    if (result == 5) {
        std::cout << "Test passed: Result is " << result << std::endl;
    } else {
        std::cout << "Test failed: Expected 5, got " << result << std::endl;
    }
}

int main() {
    // Run the test
    test_oacc1();
    return 0;
}