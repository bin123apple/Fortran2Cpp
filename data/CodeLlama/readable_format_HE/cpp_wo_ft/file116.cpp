#include <cmath>
#include <cstdlib>
#include <iostream>

int x_or_y(int n, int x, int y)
{
    bool isp = true;
    if (n < 2) isp = false;
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            isp = false;
            break;
        }
    }

    if (isp) {
        return x;
    } else {
        return y;
    }
}

int main()
{
    if (x_or_y(7, 34, 12) != 34) {
        std::cout << "Assertion failed: x_or_y(7, 34, 12) == 34" << std::endl;
        std::exit(1);
    }

    if (x_or_y(15, 8, 5) != 5) {
        std::cout << "Assertion failed: x_or_y(15, 8, 5) == 5" << std::endl;
        std::exit(1);
    }

    if (x_or_y(3, 33, 5212) != 33) {
        std::cout << "Assertion failed: x_or_y(3, 33, 5212) == 33" << std::endl;
        std::exit(1);
    }

    if (x_or_y(1259, 3, 52) != 3) {
        std::cout << "Assertion failed: x_or_y(1259, 3, 52) == 3" << std::endl;
        std::exit(1);
    }

    if (x_or_y(7919, -1, 12) != -1) {
        std::cout << "Assertion failed: x_or_y(7919, -1, 12) == -1" << std::endl;
        std::exit(1);
    }

    if (x_or_y(3609, 1245, 583) != 583) {
        std::cout << "Assertion failed: x_or_y(3609, 1245, 583) == 583" << std::endl;
        std::exit(1);
    }

    if (x_or_y(91, 56, 129) != 129) {
        std::cout << "Assertion failed: x_or_y(91, 56, 129) == 129" << std::endl;
        std::exit(1);
    }

    if (x_or_y(6, 34, 1234) != 1234) {
        std::cout << "Assertion failed: x_or_y(6, 34, 1234) == 1234" << std::endl;
        std::exit(1);
    }

    if (x_or_y(1, 2, 0) != 0) {
        std::cout << "Assertion
