#include <iostream>

volatile bool t1;
bool t2;
int i;

int main() {
    t2 = false;
    t1 = false;
    for (i = 1; i <= 2; ++i) {
        if (t1) std::cout << "VolatileNotOptimizedAway" << std::endl;
        if (t2) std::cout << "NonVolatileNotOptimizedAway" << std::endl;
    }
    return 0;
}