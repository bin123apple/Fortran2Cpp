#include <cmath>
#include <cstdlib>
#include <iostream>

using ProcType = double (*)(double);

void test(ProcType proc) {
    double a, b, c;

    a = 1.0;
    b = std::sin(a);
    c = proc(a);

    if (std::abs(b - c) > 0.001) {
        std::abort();
    }
}

double sinWrapper(double x) {
    return std::sin(x);
}

double customFunc(double x) {
    return 2.0 * std::sin(x);
}

int main() {
    std::cout << "Testing with sinWrapper" << std::endl;
    test(sinWrapper);
    std::cout << "Test with sinWrapper completed successfully" << std::endl;

    std::cout << "Testing with customFunc" << std::endl;
    test(customFunc);  // This should cause an abort
    
    std::cout << "Test with customFunc completed successfully" << std::endl;
    return 0;
}