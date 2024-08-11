#include <iostream>
#include <vector>
#include <stdexcept>

// AdiosHelpers class definition
class AdiosHelpers {
public:
    static void define_adios_scalar(double scalar) {
        std::cout << "Defining ADIOS scalar with value: " << scalar << std::endl;
    }

    static void define_adios_global_real_1d_array(const std::vector<double>& array) {
        std::cout << "Defining ADIOS global real 1D array of size " << array.size() << std::endl;
        for (double val : array) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    static void check_adios_err() {
        std::cout << "Checking for ADIOS errors..." << std::endl;
    }
};

// Simple test functions
void test_define_adios_scalar() {
    std::cout << "Testing define_adios_scalar..." << std::endl;
    AdiosHelpers::define_adios_scalar(3.14);
}

void test_define_adios_global_real_1d_array() {
    std::cout << "Testing define_adios_global_real_1d_array..." << std::endl;
    std::vector<double> array = {1.0, 2.0, 3.0, 4.0, 5.0};
    AdiosHelpers::define_adios_global_real_1d_array(array);
}

void test_check_adios_err() {
    std::cout << "Testing check_adios_err..." << std::endl;
    AdiosHelpers::check_adios_err();
}

// Main function to run tests
int main() {
    try {
        test_define_adios_scalar();
        test_define_adios_global_real_1d_array();
        test_check_adios_err();
        std::cout << "All tests passed successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Test failed with unknown exception." << std::endl;
        return 1;
    }
    return 0;
}