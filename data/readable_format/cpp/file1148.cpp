#include <iostream>
#include <stdexcept>
#include <cassert>

int polygon(int p, int n) {
    int result;
    int a;

    switch (p) {
        case 3:
            if (n % 2 == 0) {
                a = n / 2;
                result = a * (n + 1);
            } else {
                a = (n + 1) / 2;
                result = n * a;
            }
            break;
        case 5:
            if (n % 2 == 0) {
                a = n / 2;
                result = a * (n * 3 - 1);
            } else {
                a = n + (n - 1) / 2;
                result = n * a;
            }
            break;
        case 6:
            result = n * (2 * n - 1);
            break;
        default:
            throw std::runtime_error("Invalid polygon type");
    }

    return result;
}

void solver() {
    int i = 285, j = 165, k = 143;
    int pt, pp, ph;

    pp = polygon(5, j);
    ph = polygon(6, k);

    do {
        i++;
        pt = polygon(3, i);

        while (pp < pt) {
            j++;
            pp = polygon(5, j);
        }

        while (ph < pt) {
            k++;
            ph = polygon(6, k);
        }
    } while (pt != pp || pt != ph);

    std::cout << "result = " << pt << std::endl;
}

void testPolygon() {
    assert(polygon(3, 285) == 40755);
    assert(polygon(5, 165) == 40755);
    assert(polygon(6, 143) == 40755);
    std::cout << "All tests passed." << std::endl;
}

int main() {
    try {
        solver();
        testPolygon();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}