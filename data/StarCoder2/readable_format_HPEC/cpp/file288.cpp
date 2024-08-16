#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is double for this example
using DATA_TYPE = double;

// Constants for output formatting
const std::string DATA_PRINTF_MODIFIER = "%.6g "; // Example format specifier

void print_array(int cz, int cxm, int cym, DATA_TYPE*** bza, DATA_TYPE*** ex, DATA_TYPE*** ey, DATA_TYPE*** hz) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i <= cz; ++i) {
        for (int j = 0; j <= cym; ++j) {
            for (int k = 0; k <= cxm; ++k) {
                std::cout << DATA_PRINTF_MODIFIER << bza[k][j][i] << " ";
                std::cout << DATA_PRINTF_MODIFIER << ex[k][j][i] << " ";
                std::cout << DATA_PRINTF_MODIFIER << ey[k][j][i] << " ";
                std::cout << DATA_PRINTF_MODIFIER << hz[k][j][i] << " ";

                if ((i * cxm + j) % 20 == 0) {
                    std::cout << std::endl;
                }
            }
        }
    }
    std::cout << std::endl;
}

// Example of how to call the function
int main() {
    int cz = 10, cxm = 10, cym = 10;

    // Dynamically allocate 3D arrays
    DATA_TYPE*** bza = new DATA_TYPE**[cxm + 1];
    DATA_TYPE*** ex = new DATA_TYPE**[cxm + 1];
    DATA_TYPE*** ey = new DATA_TYPE**[cxm + 1];
    DATA_TYPE*** hz = new DATA_TYPE**[cxm + 1];

    for (int i = 0; i <= cxm; ++i) {
        bza[i] = new DATA_TYPE*[cym + 1];
        ex[i] = new DATA_TYPE*[cym + 1];
        ey[i] = new DATA_TYPE*[cym + 1];
        hz[i] = new DATA_TYPE*[cym + 1];

        for (int j = 0; j <= cym; ++j) {
            bza[i][j] = new DATA_TYPE[cz + 1];
            ex[i][j] = new DATA_TYPE[cz + 1];
            ey[i][j] = new DATA_TYPE[cz + 1];
            hz[i][j] = new DATA_TYPE[cz + 1];
        }
    }

    // Populate arrays with some values (example)
    for (int i = 0; i <= cxm; ++i) {
        for (int j = 0; j <= cym; ++j) {
            for (int k = 0; k <= cz; ++k) {
                bza[i][j][k] = i + j + k;
                ex[i][j][k] = i - j + k;
                ey[i][j][k] = i + j - k;
                hz[i][j][k] = i - j - k;
            }
        }
    }

    print_array(cz, cxm, cym, bza, ex, ey, hz);

    // Clean up
    for (int i = 0; i <= cxm; ++i) {
        for (int j = 0; j <= cym; ++j) {
            delete[] bza[i][j];
            delete[] ex[i][j];
            delete[] ey[i][j];
            delete[] hz[i][j];
        }
        delete[] bza[i];
        delete[] ex[i];
        delete[] ey[i];
        delete[] hz[i];
    }

    return 0;
}
