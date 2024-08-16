#include <iostream>
#include <iomanip>

void print_array(int ni, int nl, double g[][nl]) {
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nl; j++) {
            std::cout << std::setw(10) << std::setprecision(5) << g[j][i] << std::endl;
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    int ni = 10; // replace with your desired value
    int nl = 20; // replace with your desired value
    double g[nl][ni]; // replace with your desired array initialization

    // initialize and print the array
    print_array(ni, nl, g);

    return 0;
}
