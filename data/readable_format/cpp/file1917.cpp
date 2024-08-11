#include <iostream>
#include <cstring> // For strncpy

class MyTyp {
public:
    char a[4]; // Extra character for null terminator

    MyTyp() {
        a[0] = 'X'; a[1] = 'Y'; a[2] = 'Z'; a[3] = '\0'; // Correct null termination
    }

    MyTyp(const char* initVal) {
        strncpy(a, initVal, 3);
        a[3] = '\0'; // Correct null termination
    }
};

int main() {
    MyTyp defaultInstance;
    MyTyp customInstance("ABC");

    // Test default constructor
    if (std::strcmp(defaultInstance.a, "XYZ") == 0) {
        std::cout << "Default constructor test passed." << std::endl;
    } else {
        std::cout << "Default constructor test failed." << std::endl;
    }

    // Test custom constructor
    if (std::strcmp(customInstance.a, "ABC") == 0) {
        std::cout << "Custom constructor test passed." << std::endl;
    } else {
        std::cout << "Custom constructor test failed." << std::endl;
    }

    return 0;
}