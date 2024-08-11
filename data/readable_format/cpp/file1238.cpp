#include <iostream>
#include <cstdlib> // For exit()

int main() {
    int a[10] = {2, 1, 4, 6, 3, 2, 6, 3, 3, 1};
    int sa, ia;

    // Find the maximum value and its index
    sa = a[0];
    ia = 0;
    for (int i = 1; i < 10; ++i) {
        if (sa < a[i]) {
            ia = i;
            sa = a[i];
        }
    }

    if (ia == 3 && sa == 6) { // Adjusted for 0-based indexing
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
        exit(1);
    }

    // Find the minimum value and its index
    sa = a[0];
    ia = 0;
    for (int i = 1; i < 10; ++i) {
        if (sa > a[i]) {
            ia = i;
            sa = a[i];
        }
    }

    if (ia == 1 && sa == 1) { // Adjusted for 0-based indexing
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
        exit(1);
    }

    return 0;
}