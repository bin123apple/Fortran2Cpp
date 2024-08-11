#include <iostream>
#include <complex>
#include <array>
#include <stdexcept>
#include <cassert>

using std::complex;
using std::array;

void sub_rk(array<double, 2>& r) {
    if (r[0] != -1.0 || r[1] != -3.0) {
        throw std::runtime_error("Assertion failed in sub_rk");
    }
    r[0] = 3.0;
    r[1] = 2.0;
}

void sub_ck(array<complex<double>, 2>& r) {
    if (r[0] != complex<double>(-1.0, 0.0) || r[1] != complex<double>(-3.0, 0.0)) {
        throw std::runtime_error("Assertion failed in sub_ck");
    }
    r[0] = 3.0;
    r[1] = 2.0;
}

// Unit tests
void test_sub_rk() {
    array<double, 2> rk = {-1.0, -3.0};
    sub_rk(rk);
    assert(rk[0] == 3.0 && rk[1] == 2.0);
    std::cout << "sub_rk test passed." << std::endl;
}

void test_sub_ck() {
    array<complex<double>, 2> ck = {complex<double>(-1.0, 0.0), complex<double>(-3.0, 0.0)};
    sub_ck(ck);
    assert(ck[0] == complex<double>(3.0, 0.0) && ck[1] == complex<double>(2.0, 0.0));
    std::cout << "sub_ck test passed." << std::endl;
}

int main() {
    try {
        test_sub_rk();
        test_sub_ck();
        std::cout << "All tests passed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}