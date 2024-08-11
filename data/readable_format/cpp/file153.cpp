#include <iostream>
#include <limits>

int main() {
    int i;
    double d = 2.0;
    double x = 1.0;
    double x_p;

    for (i = 1; i <= 2000; ++i) {
        x_p = x + d;
        if (x_p == x) {
            break;
        }
        d = d / 2.0;
    }

    std::cout << i << " " << d << " " << std::numeric_limits<double>::epsilon() << std::endl;

    return 0;
}