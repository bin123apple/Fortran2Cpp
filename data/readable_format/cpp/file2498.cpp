// Define a module mmm as a class in C++
class mmm {
public:
    int j; // Equivalent to the integer variable in the Fortran module
};

int main() {
    mmm moduleInstance; // Create an instance of the class
    moduleInstance.j = 0; // Initialize or use the variable as needed

    // Example usage
    moduleInstance.j = 5;
    std::cout << "Value of j: " << moduleInstance.j << std::endl;

    return 0;
}