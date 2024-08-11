#include <iostream>
#include <array>

class spcore_I {
public:
    static void spcore(int NI, int NJ, double R, std::array<std::array<double, 2>, 10>& CORE) {
        for (int i = 0; i < 10; ++i) {
            CORE[i][0] = NI * R + (i + 1); // Adjusted to match Fortran's 1-based indexing
            CORE[i][1] = NJ * R - (i + 1);
        }
    }
};

int main() {
    std::array<std::array<double, 2>, 10> CORE;
    int NI = 5;
    int NJ = 10;
    double R = 2.5;

    spcore_I::spcore(NI, NJ, R, CORE);

    std::cout << "CORE array values:" << std::endl;
    for (const auto& row : CORE) {
        std::cout << "(" << row[0] << ", " << row[1] << ")" << std::endl;
    }

    return 0;
}