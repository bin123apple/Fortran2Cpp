#include <iostream>
#include <vector>
#include <string>

// Define the class in place of the separate header
class PermanentArrays {
public:
    // Integer arrays
    std::vector<int> labels;
    std::vector<double> xparam; // Assuming double precision is required
    std::vector<std::string> simbol; // For character arrays

    // Other arrays can be defined similarly...
};

// Test the functionality within the same file
int main() {
    PermanentArrays pa;

    // Allocate and set values - example
    pa.labels = {1, 2, 3, 4, 5};
    pa.xparam = {1.0, 2.0, 3.0, 4.0, 5.0};
    pa.simbol = {"H", "He"};

    // Example test - print values to verify
    std::cout << "Labels: ";
    for (const auto& label : pa.labels) {
        std::cout << label << " ";
    }
    std::cout << std::endl; // Correctly break line

    std::cout << "XParam: ";
    for (const auto& x : pa.xparam) {
        std::cout << x << " ";
    }
    std::cout << std::endl; // Correctly break line

    std::cout << "Simbol: ";
    for (const auto& s : pa.simbol) {
        std::cout << s << " ";
    }
    std::cout << std::endl; // Correctly break line

    return 0;
}