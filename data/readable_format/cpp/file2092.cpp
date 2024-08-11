#include <iostream>

// Declare the add function directly in this file, instead of in a separate header.
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(1, 2);
    std::cout << "The result of adding 1 and 2 is: " << result << std::endl;
    return 0;
}