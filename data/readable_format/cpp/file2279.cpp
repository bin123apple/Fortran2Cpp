#include <iostream>
#include <cmath>

struct test_typ {
    float a;
};

int main() {
    test_typ my_test_typ;
    my_test_typ.a = 1.0f;

    if (std::fabs(my_test_typ.a - 1.0f) > 1e-6) {
        std::cerr << "Test failed!" << std::endl;
        return 1;
    }

    return 0;
}