#include <iostream>
#include <cstdlib> // For std::abort

class Vector2 {
public:
    int data[2];

    Vector2(int x = 0, int y = 0) {
        data[0] = x;
        data[1] = y;
    }

    // Overload the + operator to add two Vector2 objects
    Vector2 operator+(const Vector2& rhs) const {
        return Vector2(data[0] + rhs.data[0], data[1] + rhs.data[1]);
    }
};

void test_sub(const Vector2& input1, const Vector2& input2) {
    Vector2 mysum = input1 + input2;
    if (mysum.data[0] == 3 && mysum.data[1] == 4) {
        std::cout << "Test passed in subroutine equivalent." << std::endl;
    } else {
        std::cout << "Test failed in subroutine equivalent." << std::endl;
        std::abort();
    }
}

void test_interface() {
    Vector2 input1(0, 1);
    Vector2 input2(3, 3);
    Vector2 mysum = input1 + input2;
    if (mysum.data[0] == 3 && mysum.data[1] == 4) {
        std::cout << "Test passed in main test function." << std::endl;
    } else {
        std::cout << "Test failed in main test function." << std::endl;
        std::abort();
    }
    test_sub(input1, input2);
}

int main() {
    test_interface();
    return 0;
}