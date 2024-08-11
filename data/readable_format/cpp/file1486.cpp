#include <iostream>

int main() {
    int first = 1, second = 1, tmp = 0;
    int maximum = 4000000;
    int sumx = 0;

    while (true) {
        tmp = first + second;

        if (tmp > maximum) {
            break;
        }

        if (tmp % 2 == 0) {
            sumx += tmp;
        }

        first = second;
        second = tmp;
    }

    std::cout << sumx << std::endl;

    return 0;
}