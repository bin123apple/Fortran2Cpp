#include <iostream>
#include <vector>

void ynorm(int maxsiz, int jstrt, int jfins, std::vector<double> &observ, double rnorm) {
    // Adjusting jstrt and jfins for 0-based indexing
    jstrt -= 1;
    jfins -= 1;
    for (int i_res = jstrt; i_res <= jfins; ++i_res) {
        observ[i_res] = rnorm * observ[i_res];
    }
}

int main() {
    const int maxsiz = 10;
    std::vector<double> observ(maxsiz);
    double rnorm = 2.0;
    int jstrt = 2; // Adjusted in the ynorm function to match Fortran 1-based indexing
    int jfins = 5; // Adjusted in the ynorm function to match Fortran 1-based indexing

    // Populate the observ array with initial values
    for (int i = 0; i < maxsiz; ++i) {
        observ[i] = static_cast<double>(i + 1);
    }

    // Call the ynorm function
    ynorm(maxsiz, jstrt, jfins, observ, rnorm);

    // Print the results to verify the computation
    std::cout << "Observ array after calling ynorm:" << std::endl;
    for (int i = 0; i < maxsiz; ++i) {
        std::cout << observ[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}