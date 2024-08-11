#include <cmath> // For std::abs
#include <iostream> // For std::cout

class Orders {
public:
    // Overloaded lt_order (Less Than) functions
    static bool lt_order(double a, double b) {
        return a < b;
    }
    static bool lt_order(int a, int b) {
        return a < b;
    }
    static bool lt_order(float a, float b) {
        return a < b;
    }

    // Overloaded gtabs_order (Greater Than Absolute) functions
    static bool gtabs_order(double a, double b) {
        return std::abs(a) > std::abs(b);
    }
    static bool gtabs_order(int a, int b) {
        return std::abs(a) > std::abs(b);
    }
    static bool gtabs_order(float a, float b) {
        return std::abs(a) > std::abs(b);
    }

    // Overloaded gt_order (Greater Than) functions
    static bool gt_order(double a, double b) {
        return a > b;
    }
    static bool gt_order(int a, int b) {
        return a > b;
    }
    static bool gt_order(float a, float b) {
        return a > b;
    }
};

// Main function for testing
int main() {
    // Testing lt_order
    if (Orders::lt_order(1, 2) && Orders::lt_order(1.0, 2.0) && Orders::lt_order(1.0f, 2.0f)) {
        std::cout << "lt_order tests passed." << std::endl;
    } else {
        std::cout << "lt_order tests failed." << std::endl;
    }

    // Testing gtabs_order
    if (Orders::gtabs_order(-2, 1) && Orders::gtabs_order(-2.0, 1.0) && Orders::gtabs_order(-2.0f, 1.0f)) {
        std::cout << "gtabs_order tests passed." << std::endl;
    } else {
        std::cout << "gtabs_order tests failed." << std::endl;
    }

    // Testing gt_order
    if (!Orders::gt_order(1, 2) && !Orders::gt_order(1.0, 2.0) && !Orders::gt_order(1.0f, 2.0f)) {
        std::cout << "gt_order tests passed." << std::endl;
    } else {
        std::cout << "gt_order tests failed." << std::endl;
    }

    return 0;
}