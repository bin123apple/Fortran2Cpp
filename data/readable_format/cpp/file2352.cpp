#include <iostream>
#include <string>

// Separate enums reflecting the Fortran structure
enum WeekDay {
    sun, mon = 2, wed = 1
};

enum Fruit {
    apple, mango
};

void verify_enum(int actual, int expected, const std::string& name) {
    if (actual != expected) {
        std::cout << "Test failed for " << name << ": expected " << expected << " but got " << actual << std::endl;
    } else {
        std::cout << "Test passed for " << name << std::endl;
    }
}

int main() {
    // Test cases for WeekDay
    verify_enum(sun, 0, "sun");
    verify_enum(mon, 2, "mon");
    verify_enum(wed, 1, "wed");

    // Test cases for Fruit
    verify_enum(apple, 0, "apple");
    verify_enum(mango, 1, "mango");

    return 0;
}