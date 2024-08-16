#include <iostream>
#include <vector>
#include <sstream>
#include <omp.h>

int main() {
    // Define a vector of strings to hold the character arrays
    std::vector<std::string> a(100);

    // OpenMP parallel region
    #pragma omp parallel for private(str)
    for (int i = 0; i < 100; ++i) {
        std::stringstream str;
        // Format the integer i into a string with width 10
        str << std::setw(10) << i;
        // Assign the formatted string to the vector element
        a[i] = str.str();
    }

    // Print the 23rd element of the array
    std::cout << "a[i] = " << a[22] << std::endl;

    return 0;
}
