#include <iostream>
#include <cstdbool> // For bool type in C++

// Assuming the function signature from the previous example:
void meshFEM3DModelCrust(double lat, double lon, double r, double& vpc,
                         double& vsc, double& rhoc, double& moho,
                         bool& foundCrust, bool elemInCrust) {
    // Hypothetical implementation based on the provided signature
    vpc = lat + lon + r; // Placeholder calculation
    vsc = lat * lon * r; // Placeholder calculation
    rhoc = lat - lon - r; // Placeholder calculation
    moho = lat / lon / r; // Placeholder calculation
    foundCrust = elemInCrust; // Directly use the input boolean as the output
}

int main() {
    double lat = 45.0, lon = 90.0, r = 6371.0;
    double vpc, vsc, rhoc, moho;
    bool foundCrust, elemInCrust = true;

    meshFEM3DModelCrust(lat, lon, r, vpc, vsc, rhoc, moho, foundCrust, elemInCrust);

    // Demonstrating the usage and printing out the results
    std::cout << "VPC: " << vpc << std::endl;
    std::cout << "VSC: " << vsc << std::endl;
    std::cout << "RHOC: " << rhoc << std::endl;
    std::cout << "MOHO: " << moho << std::endl;
    std::cout << "Found Crust: " << std::boolalpha << foundCrust << std::endl;

    return 0;
}