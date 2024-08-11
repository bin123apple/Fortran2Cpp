#include <iostream>
#include <complex>
#include <cmath> // For std::abs

namespace constants {

  constexpr double pi = 3.1415926535897932384626433832795028841971693993751;
  constexpr std::complex<double> ci1(0.0,1.0);
  constexpr std::complex<double> c1(1.0,0.0);
  constexpr double proton_mass = 1.67262158E-27;
  constexpr double epsilon_0 = 8.85418782E-12;
  constexpr double unit_charge_si = 1.602176487E-19;

}

// A simple assert function for demonstration
void assert_close(double val, double expected, double tolerance, const std::string& test_name) {
    if (std::abs(val - expected) > tolerance) {
        std::cout << "Test failed: " << test_name << " | Value: " << val << " Expected: " << expected << std::endl;
    } else {
        std::cout << "Test passed: " << test_name << std::endl;
    }
}

void assert_complex_close(std::complex<double> val, std::complex<double> expected, double tolerance, const std::string& test_name) {
    if (std::abs(val.real() - expected.real()) > tolerance || std::abs(val.imag() - expected.imag()) > tolerance) {
        std::cout << "Test failed: " << test_name << " | Value: (" << val.real() << ", " << val.imag() << ") Expected: (" << expected.real() << ", " << expected.imag() << ")" << std::endl;
    } else {
        std::cout << "Test passed: " << test_name << std::endl;
    }
}

int main() {
    using namespace constants;

    assert_close(pi, 3.1415926535897932384626433832795028841971693993751, 1e-15, "pi");
    assert_complex_close(ci1, std::complex<double>(0.0,1.0), 1e-15, "ci1");
    assert_complex_close(c1, std::complex<double>(1.0,0.0), 1e-15, "c1");
    assert_close(proton_mass, 1.67262158E-27, 1e-15, "proton_mass");
    assert_close(epsilon_0, 8.85418782E-12, 1e-15, "epsilon_0");
    assert_close(unit_charge_si, 1.602176487E-19, 1e-15, "unit_charge_si");

    return 0;
}