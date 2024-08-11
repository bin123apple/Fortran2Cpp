#include <iostream>
#include <cstdint>
#include <limits>

// Definition of the maxmin function
void maxmin(const int16_t* data, int npix, int nlin, int inval, int& datmax, int& datmin, int& ierr) {
    bool first = true;
    ierr = 0; // Assuming no error initially.
    datmax = std::numeric_limits<int>::min(); // Set to minimum possible value
    datmin = std::numeric_limits<int>::max(); // Set to maximum possible value

    for (int line = 0; line < nlin; ++line) {
        for (int pixel = 0; pixel < npix; ++pixel) {
            int datval = data[line * npix + pixel]; // Adjusting for 0-based indexing and flattened array access
            if (datval != inval) {
                if (first) {
                    datmax = datval;
                    datmin = datval;
                    first = false;
                } else {
                    datmax = std::max(datmax, datval);
                    datmin = std::min(datmin, datval);
                }
            }
        }
    }

    if (first) {
        // If still first, it means all values were invalid.
        ierr = 1;
        datmin = inval;
        datmax = inval;
    }
}

// Main function for the unit test
int main() {
    const int npix = 3, nlin = 3;
    int16_t data[npix * nlin] = {1, 2, 3, -1, 5, 6, 7, 8, 9}; // Flattened array
    int datmax, datmin, ierr;

    // Call the maxmin function with the test data
    maxmin(data, npix, nlin, -1, datmax, datmin, ierr);

    // Print the results
    std::cout << "Max: " << datmax << std::endl;
    std::cout << "Min: " << datmin << std::endl;
    std::cout << "Error: " << ierr << std::endl;

    return 0;
}