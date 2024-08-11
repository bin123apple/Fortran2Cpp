#include <iostream>
#include <string>

// Define a structure similar to the Fortran TYPE
struct Person {
    int age;
    std::string name;
};

int main() {
    // Initialize a Person instance
    Person p = {21, "JOHN SMITH"};
    
    // Output the desired information
    // Note: substr(0, 10) is used to mimic Fortran's p%name(1:10)
    // In C++, string indexing starts at 0, and substr takes starting index and length
    std::cout << p.name.substr(0, 10) << " is " << p.age << " years old" << std::endl;
    
    return 0;
}