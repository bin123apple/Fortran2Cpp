#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a type that can be printed, e.g., int, float, double, etc.
// If DATA_TYPE is a complex type, you might need to overload the stream insertion operator << for it to work correctly.
template<typename DATA_TYPE>
void print_array(const DATA_TYPE* a, int nr, int nq, int np) {
    // Loop indices start from 0 in C++
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nq; ++j) {
            for (int k = 0; k < np; ++k) {
                // Print the element
                std::cout << a[k + j*np + i*nq*np] << " ";
                // Add a newline every 20 elements
                if ((k + 1) % 20 == 0) {
                    std::cout << std::endl;
                }
            }
            std::cout << std::endl; // Newline after each row
        }
        std::cout << std::endl; // Newline after each plane
    }
    std::cout << std::endl; // Final newline
}

// Example usage
int main() {
    const int nr = 10, nq = 10, np = 10;
    int array[nr*nq*np]; // Example array
    
    // Initialize array with some values
    for(int i = 0; i < nr*nq*np; ++i) {
        array[i] = i; // Example initialization
    }
    
    print_array(array, nr, nq, np);
    
    return 0;
}
