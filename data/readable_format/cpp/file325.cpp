#include <iostream>
#include <cstdlib> // For abort()

class m {
public:
    static float x(int n, int m) {
        return m * n;
    }

    static void s() {
        upper();
        lower();
        // Corrected multi-line string literal
        std::cout << "Both upper and lower checks passed." << std::endl;
    }

private:
    static void upper() {
        float y = x(3, 1);
        if (int(y) != 3) std::abort();
    }

    static void lower() {
        float y = x(2, 1);
        if (int(y) != 2) std::abort();
    }
};

int main() {
    try {
        m::s();
    } catch (...) {
        // Corrected multi-line string literal
        std::cerr << "Test failed due to an unexpected error." << std::endl;
        return 1;
    }
    return 0;
}