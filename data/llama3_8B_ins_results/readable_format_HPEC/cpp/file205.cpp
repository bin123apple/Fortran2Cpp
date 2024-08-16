#include <iostream>
#include <iomanip>

void print_array(int ni, int nj, double c[][ni]) {
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            std::cout << std::setw(10) << std::setprecision(5) << c[j][i] << std::endl;
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    int ni = 10; // replace with your desired value
    int nj = 20; // replace with your desired value
    double c[nj][ni]; // replace with your desired data

    // initialize c array with your desired data

    print_array(ni, nj, c);

    return 0;
}
