#include <array>
#include <iostream>

// Assuming 'a' is a global variable as in the Fortran module
std::array<std::array<float, 10>, 10> a;

int main() {
    // Example initialization, in real case you would have some meaningful values
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            a[i][j] = static_cast<float>(i * 10 + j);
        }
    }
    
    // Assigning a(5,6) to a(3,2), note the index shift (Fortran is 1-based, C++ is 0-based)
    a[2][1] = a[4][5];
    
    // Just for demonstration, print the value to verify
    std::cout << "a[3][2] = " << a[2][1] << std::endl;

    return 0;
}