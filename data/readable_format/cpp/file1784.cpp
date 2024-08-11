#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

int main() {
    int n = 3;
    float s = 0.0;

    { // Equivalent to the first Fortran block
        { // Equivalent to the second Fortran block
            { // Equivalent to the third Fortran block
                { // Equivalent to the fourth Fortran block
                    { // Equivalent to the fifth Fortran block
                        std::vector<float> a(n, 3.0); // Creating a vector 'a' with 'n' elements, each initialized to 3.0
                        s = std::accumulate(a.begin(), a.end(), 0.0); // Summing up elements of 'a'
                    }
                }
            }
        }
    }

    if (s != 9) {
        std::cerr << "Aborting due to unexpected sum." << std::endl;
        return 1; // Equivalent to Fortran's call abort
    }

    return 0;
}