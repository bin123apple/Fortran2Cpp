#include <iostream>
#include <string>
#include <cctype> // for toupper, tolower, and isalpha functions

void grid2deg(const std::string& grid0, double& dlong, double& dlat) {
    std::string grid = grid0;
    grid.resize(6, ' '); // Ensure grid is at least 6 characters long
    
    // Adjust fifth and sixth characters if necessary
    int i = static_cast<int>(grid[4]);
    if(grid[4] == ' ' || i <= 64 || i >= 128) grid[4] = grid[5] = 'm';
    
    // Convert first and second characters to uppercase if they are lowercase
    if(isalpha(grid[0]) && islower(grid[0])) grid[0] = toupper(grid[0]);
    if(isalpha(grid[1]) && islower(grid[1])) grid[1] = toupper(grid[1]);

    // Convert fifth and sixth characters to lowercase if they are uppercase
    if(isalpha(grid[4]) && isupper(grid[4])) grid[4] = tolower(grid[4]);
    if(isalpha(grid[5]) && isupper(grid[5])) grid[5] = tolower(grid[5]);

    // Perform calculations
    double nlong = 180 - 20 * (static_cast<int>(grid[0]) - 'A');
    double n20d = 2 * (static_cast<int>(grid[2]) - '0');
    double xminlong = 5 * (static_cast<int>(grid[4]) - 'a' + 0.5);
    dlong = nlong - n20d - xminlong / 60.0;
    
    double nlat = -90 + 10 * (static_cast<int>(grid[1]) - 'A') + (static_cast<int>(grid[3]) - '0');
    double xminlat = 2.5 * (static_cast<int>(grid[5]) - 'a' + 0.5);
    dlat = nlat + xminlat / 60.0;
}

// C++ Unit Test Code
#include <cassert>
#include <cmath> // for fabs function

void testGrid2DegCpp() {
    double dlong, dlat;
    grid2deg("A1B2C3", dlong, dlat);
    std::cout << "C++: Test 1: Grid=A1B2C3, Longitude=" << dlong << ", Latitude=" << dlat << std::endl;
    assert(std::fabs(dlong - 143.79166666666666) < 1e-6 && std::fabs(dlat + 249.89583333333334) < 1e-6);
}

int main() {
    testGrid2DegCpp();
    std::cout << "All C++ tests passed successfully!" << std::endl;
    return 0;
}