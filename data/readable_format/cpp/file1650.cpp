#include <iostream>

void clawloop() {
    int i, j, k;
    
    // First set of nested loops
    for(i = 1; i <= 5; i++) {
        for(j = 1; j <= 4; j++) {
            for(k = 1; k <= 2; k++) {
                std::cout << "First loop body: " << i << " " << j << std::endl;
            }
        }
    }
    
    // Second set of nested loops
    for(j = 1; j <= 4; j++) {
        for(i = 1; i <= 5; i++) {
            for(k = 1; k <= 2; k++) {
                std::cout << "Second loop body: " << i << " " << j << std::endl;
            }
        }
    }
}

int main() {
    clawloop();
    return 0;
}