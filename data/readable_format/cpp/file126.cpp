#include <iostream>

void sub1() {
    static int a = 0;
    a++;
    std::cout << "Value of a: " << a << std::endl;
}

int main() {
    sub1();
    sub1();
    return 0;
}