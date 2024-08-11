#include <iostream>
#include <vector>
#include <cstdlib>

struct t {
    int A;
    std::vector<float> B;
};

void check(const std::vector<t>& z) {
    if (z.size() != 10) std::abort();
    for (int i = 0; i < 10; i++) {
        if (z[i].A != -(i + 1) || z[i].B.size() != 4) std::abort();
        for (int j = 0; j < 4; j++) {
            if (z[i].B[j] != (j + 1) * (i + 1)) std::abort();
        }
    }
}

void classFunc(const std::vector<t>& z) {
    check(z);
}

void classExplicit(const std::vector<t>& u, int n) {
    if (n != 10) std::abort();
    check(u);
}

void run_tests() {
    std::cout << "Running C++ Unit Tests..." << std::endl;

    std::vector<t> x(10);
    // Initialize x with specified values for testing
    for (int i = 0; i < 10; i++) {
        x[i].A = -(i + 1);
        x[i].B.resize(4);
        for (int j = 0; j < 4; j++) {
            x[i].B[j] = (j + 1) * (i + 1);
        }
    }

    // Tests are simplistic as main functionality already includes checks
    // Would normally include assertions or conditions to validate behavior
    classFunc(x);
    classExplicit(x, x.size());

    std::cout << "C++ Unit Tests Completed Successfully." << std::endl;
}

int main() {
    // Main functionality goes here
    // For simplicity, this example will directly proceed to run tests
    run_tests();
    
    return 0;
}