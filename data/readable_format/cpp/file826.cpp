#include <iostream>
#include <string>

int main() {
    char z = 'z';
    // In practical scenarios, avoid using excessively large numbers for repetition
    int repetitions = 10; // For demonstration, using a small number
    
    // Creating a string with 'repetitions' number of z's
    std::string output(repetitions, z);
    
    // Printing the string
    std::cout << output << std::endl;
    
    return 0;
}