// test_foo_modified.cpp
#include <omp.h>
#include <iostream>

void foo(int &r) {
    #pragma omp teams distribute parallel for reduction(+:r)
    for (int i = 1; i <= 10; ++i) {
        r = r + 1;
    }
}

int main() {
    int result = 0;
    foo(result);

    if (result == 10) {
        std::cout << "Test Passed: result = " << result << std::endl;
    } else {
        std::cout << "Test Failed: result = " << result << std::endl;
    }

    return 0;
}