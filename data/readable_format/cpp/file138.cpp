#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class CArrays {
public:
    // Function 1: Sum elements of an array
    static double array_in(const std::vector<double>& x) {
        return std::accumulate(x.begin(), x.end(), 0.0);
    }

    // Function 2: Sum the first four elements of an array
    static double array_in_2(const std::vector<double>& x) {
        double sum = 0;
        for (int i = 0; i < 4 && i < x.size(); ++i) {
            sum += x[i];
        }
        return sum;
    }

    // Subroutine 3: Set all elements of x to 20 and all elements of y to 30
    static void array_out(std::vector<double>& x, std::vector<double>& y) {
        std::fill(x.begin(), x.end(), 20.0);
        std::fill(y.begin(), y.end(), 30.0);
    }

    // Function 4: Calculate the dot product of two arrays
    static double inner_prod(const std::vector<double>& a, const std::vector<double>& b) {
        if (a.size() != b.size()) {
            std::cerr << "Arrays must be of the same size" << std::endl;
            return 0; // Or throw an exception
        }

        double sum = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            sum += a[i] * b[i];
        }
        return sum;
    }
};

int main() {
    // Test 1: Summing all elements of an array
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::cout << "Sum of elements in x: " << CArrays::array_in(x) << std::endl;

    // Test 2: Summing the first four elements of an array
    std::vector<double> y = {1, 2, 3};
    std::cout << "Sum of first four elements in y: " << CArrays::array_in_2(y) << std::endl;

    // Test 3: Setting all elements of two arrays x and y to 20 and 30, respectively
    CArrays::array_out(x, y);
    std::cout << "First element of x after array_out: " << x[0] << std::endl;
    std::cout << "First element of y after array_out: " << y[0] << std::endl;

    // Test 4: Calculating the dot product of two arrays
    std::vector<double> a = {1, 2, 3};
    std::vector<double> b = {4, 5, 6};
    std::cout << "Dot product of a and b: " << CArrays::inner_prod(a, b) << std::endl;

    return 0;
}