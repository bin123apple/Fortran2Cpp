#include <iostream>

void great_rsd(int a, int b) {
    std::cout << "Called great_rsd with " << a << " and " << b << ". Sum is: " << a + b << std::endl;
}

int main() {
    great_rsd(1, 2);
    great_rsd(3, 4);
    great_rsd(-5, -6);
    great_rsd(0, 0);
    return 0;
}