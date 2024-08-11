// sum.cpp
#include <iostream>

class Sum {
public:
    static int addNumbers(int a, int b) {
        return a + b;
    }
};

int main() {
    std::cout << "Testing sum of 5 and 3: " << Sum::addNumbers(5, 3) << std::endl;
    return 0;
}