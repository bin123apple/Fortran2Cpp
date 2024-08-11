#include <iostream>
#include <array>
#include <stdexcept>

class Vector2D {
public:
    std::array<int, 2> values;

    Vector2D(int x = 0, int y = 0) {
        values[0] = x;
        values[1] = y;
    }

    // Overloaded '+' operator for adding two Vector2D objects
    Vector2D operator+(const Vector2D& rhs) const {
        return Vector2D(values[0] + rhs.values[0], values[1] + rhs.values[1]);
    }
};

// Simple test function to verify Vector2D addition
void testVector2DAddition() {
    Vector2D input1(0, 1), input2(3, 3), expectedSum(3, 4);
    Vector2D result = input1 + input2;

    if (result.values[0] == expectedSum.values[0] && result.values[1] == expectedSum.values[1]) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cerr << "Test failed." << std::endl;
        std::exit(1); // Exit the program with an error state
    }
}

int main() {
    testVector2DAddition();
    return 0;
}