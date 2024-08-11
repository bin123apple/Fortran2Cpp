#include <iostream>
#include <vector>

class M {
public:
    static int a, b;
};

int M::a = 0;
int M::b = 0;

void f1(std::vector<int>& c, std::vector<int>& d) {
    for (int i = 0; i < 64; ++i) {
        d[i] = M::a;
        M::a = M::a + c[i];
    }
}

int main() {
    std::vector<int> c(64, 1);  // Initialize with 1s
    std::vector<int> d(64);     // Automatically initialized to 0s
    M::a = 0;                   // Reset static member a to 0

    f1(c, d);

    // Output results to verify correctness
    for (int i = 0; i < 64; ++i) {
        std::cout << "d(" << i + 1 << ") = " << d[i] << std::endl;
    }
    std::cout << "Final value of a: " << M::a << std::endl;

    return 0;
}