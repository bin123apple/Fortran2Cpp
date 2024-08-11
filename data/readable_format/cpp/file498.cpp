#include <iostream>
#include <complex>

int main() {
    int int_var = 6;
    float r_var = 3.5f; // 'float' is equivalent to 'real' in Fortran
    std::complex<float> z(2, 5.9); // Equivalent to 'complex' in Fortran

    // Complex + integer
    std::complex<float> sum_z_int = z + static_cast<float>(int_var);
    std::cout << "Complex + integer: " << sum_z_int.real() << " + " << sum_z_int.imag() << "i" << std::endl;

    // Complex + real
    std::complex<float> sum_z_rvar = z + r_var;
    std::cout << "Complex + real: " << sum_z_rvar.real() << " + " << sum_z_rvar.imag() << "i" << std::endl;

    // Real + integer (the integer 'int_var' is implicitly converted to float)
    float sum_rvar_int = r_var + int_var;
    std::cout << "Real + integer: " << sum_rvar_int << std::endl;

    return 0;
}