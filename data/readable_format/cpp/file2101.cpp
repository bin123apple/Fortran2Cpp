#include <iostream>

int main() {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    std::cout << "The sum of the first 10 numbers is " << sum << std::endl;
    return 0;
}