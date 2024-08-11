// Define a namespace to encapsulate the constants
namespace constant {
    // Declare the variables as double (equivalent to real*8 in Fortran)
    double sgam;
    double smue;
    double sram;
    double seps;
    double szero;
    double szero2;
    double somga;
}

int main() {
    // Example usage of the constants
    constant::sgam = 1.0; // Assign a value to sgam
    constant::smue = 2.0; // Assign a value to smue
    // ... and so on for the other variables

    // Print the values
    std::cout << "sgam: " << constant::sgam << std::endl;
    std::cout << "smue: " << constant::smue << std::endl;

    return 0;
}