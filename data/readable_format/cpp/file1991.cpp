#include <iostream>

class TPEProblem9 {
public:
    static void present() {
        std::cout << "Problem 9. Special Pythagorean triplet." << std::endl;
        std::cout << "Product 1: " << product1() << std::endl;
    }

private:
    static int product1() {
        const int limit = 1000;
        for (int c = 1; c <= limit; ++c) {
            for (int b = 1; b < c; ++b) {
                for (int a = 1; a < b; ++a) {
                    if (a + b + c == limit) {
                        if (a * a + b * b == c * c) {
                            return a * b * c;
                        }
                    }
                }
            }
        }
        return 0; // In case no triplet is found, which shouldn't happen for this problem
    }
};

int main() {
    TPEProblem9::present();
    return 0;
}