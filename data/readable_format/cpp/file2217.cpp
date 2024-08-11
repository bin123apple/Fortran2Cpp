#include <iostream>

void ai(double* a, int size) {
    // The function is provided to align with Fortran's behavior.
    // Currently, it does not modify the array.
}

int main() {
    const int size = 6; // Including index -1 to 4
    double array[size] = {-1.0, 0.0, 1.0, 2.0, 3.0, 4.0};

    // The array in C++ is 0-indexed, so we adjust the pointer to start
    // from the element intended to represent index -1 in Fortran terms.
    ai(array, size);

    // Print the array
    for(int i = -1; i < 4; ++i) {
        std::cout << "a[" << i << "] = " << array[i+1] << std::endl;
    }

    return 0;
}