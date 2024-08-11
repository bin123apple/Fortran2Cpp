#include <iostream>

// Declaration of the function before main, to ensure it's recognized.
int f(int& i);

int main() {
    int i, j;
    j = -1;
    i = f(j); // Note the function takes a reference to modify j.
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    return 0;
}

// Definition of the function.
int f(int& i) {
    std::cout << i << std::endl;
    if (i < 0) {
        i = 999;
        return i;
    }
    return i + 1;
}