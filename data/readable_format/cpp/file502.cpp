#include <iostream>
#include <vector>

int main() {
    int me = 1; // Assuming a single process
    std::vector<int> aa(10);
    int nerr = 0;

    for (int i = 0; i < 10; i++) {
        if (me == 3) {
            aa[i] = 10 - (i + 1);
        } else {
            aa[i] = -(i + 1) * 100;
        }
    }

    for (int i = 0; i < 10; i++) {
        int ival;
        if (me == 1 && i == 2) {
            ival = 555;
        } else if (me == 1 && i == 3) {
            ival = 666;
        } else if (me == 3) {
            ival = 10 - (i + 1);
        } else {
            ival = -(i + 1) * 100;
        }
        
        if (aa[i] != ival) {
            std::cout << "Mismatch at i=" << (i + 1) << " with aa[i]=" << aa[i] << " and ival=" << ival << std::endl;
            nerr++;
        }
    }

    if (nerr == 0) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "number of NGs: " << nerr << std::endl;
    }

    return 0;
}