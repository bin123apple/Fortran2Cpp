// loop_fusion.cpp
#include <iostream>

void clawloop();

int main() {
    clawloop();
    return 0;
}

void clawloop() {
    int iend = 2, jend = 4, kend = 2;

    for (int i = 0; i <= iend; ++i) {
        if (i == 0) {
            std::cout << "First iteration of i " << i << std::endl;
        }
        for (int j = 0; j <= jend; ++j) {
            for (int k = 0; k <= kend; ++k) {
                std::cout << "First loop body:" << i << '/' << j << '/' << k << std::endl;
            }
        }

        for (int j = 2; j <= jend; ++j) {
            for (int k = 0; k <= kend; ++k) {
                std::cout << "Second loop body:" << i << '/' << j << '/' << k << std::endl;
            }
        }
    }
}