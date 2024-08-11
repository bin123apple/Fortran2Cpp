// Sss.cpp
#include <iostream>

class Sss {
public:
    void exampleMethod() {
        std::cout << "This is an example method within the class Sss." << std::endl;
    }
};

int main() {
    Sss instance; // Create an instance of the class.
    instance.exampleMethod(); // Call the method to print the message.
    return 0;
}