#include <iostream>
#include <array>

// Assuming the kinds are predefined for the purpose of this example
const int ng25 = 20; // Adjust as needed

class rrsw_kg25 {
public:
    static const int no25 = 16;

    std::array<std::array<std::array<double, no25>, 13>, 5> kao{};
    std::array<double, no25> sfluxrefo{};
    std::array<double, no25> abso3ao{}, abso3bo{};
    std::array<double, no25> raylo{};

    std::array<std::array<std::array<double, ng25>, 13>, 5> ka{};
    std::array<std::array<double, ng25>, 65> absa{};
    std::array<double, ng25> sfluxref{};
    std::array<double, ng25> abso3a{}, abso3b{};
    std::array<double, ng25> rayl{};
};

int main() {
    rrsw_kg25 instance;

    // Initialize some values
    instance.kao[0][0][0] = 1.0; // Note the 0-based indexing in C++
    instance.sfluxrefo[0] = 2.0;
    instance.abso3ao[0] = 3.0;

    // Test the values
    if (instance.kao[0][0][0] == 1.0 && instance.sfluxrefo[0] == 2.0 && instance.abso3ao[0] == 3.0) {
        std::cout << "C++ Test Passed" << std::endl;
    } else {
        std::cout << "C++ Test Failed" << std::endl;
    }

    return 0;
}