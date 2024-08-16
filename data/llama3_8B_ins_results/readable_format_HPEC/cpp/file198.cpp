#include <iostream>
#include <iomanip>

void print_array(int ni, double c[][ni]) {
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < ni; j++) {
            std::cout << std::setw(10) << std::setprecision(5) << c[j][i] << " ";
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int ni = 10; // Replace with your desired value
    double c[ni][ni]; // Replace with your desired values

    // Initialize the array
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < ni; j++) {
            c[i][j] = i * ni + j; // Replace with your desired values
        }
    }

    print_array(ni, c);

    return 0;
}
