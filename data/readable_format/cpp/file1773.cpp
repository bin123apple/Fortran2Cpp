#include <iostream>
#include <vector>
#include <array>

class XYZ_2_LATLON_MINMAX__genmod {
public:
    static void XYZ_2_LATLON_MINMAX(int NSPEC, int NGLOB, const std::array<std::array<std::array<std::vector<int>, 5>, 5>, 5>& IBOOL,
                                    const std::vector<float>& XSTORE, const std::vector<float>& YSTORE, const std::vector<float>& ZSTORE,
                                    double& LAT_MIN, double& LAT_MAX, double& LON_MIN, double& LON_MAX) {
        // Assuming the implementation of the conversion logic goes here
        LAT_MIN = 0.0;  // Example dummy values
        LAT_MAX = 90.0;
        LON_MIN = -180.0;
        LON_MAX = 180.0;
    }
};

int main() {
    int NSPEC = 1;
    int NGLOB = 3;
    std::array<std::array<std::array<std::vector<int>, 5>, 5>, 5> IBOOL{}; // Simplified for the example
    std::vector<float> XSTORE = {0.0f, 1.0f, 0.5f};
    std::vector<float> YSTORE = {0.0f, 0.0f, 1.0f};
    std::vector<float> ZSTORE = {1.0f, 1.0f, 1.0f};
    double LAT_MIN, LAT_MAX, LON_MIN, LON_MAX;
    
    XYZ_2_LATLON_MINMAX__genmod::XYZ_2_LATLON_MINMAX(NSPEC, NGLOB, IBOOL, XSTORE, YSTORE, ZSTORE, LAT_MIN, LAT_MAX, LON_MIN, LON_MAX);
    
    // Print results
    std::cout << "LAT_MIN: " << LAT_MIN << std::endl;
    std::cout << "LAT_MAX: " << LAT_MAX << std::endl;
    std::cout << "LON_MIN: " << LON_MIN << std::endl;
    std::cout << "LON_MAX: " << LON_MAX << std::endl;

    // Here you would typically validate the results against expected values
    // For this example, we're just printing the results

    return 0;
}