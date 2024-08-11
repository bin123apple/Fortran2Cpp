#include <iostream>
#include <complex>
#include <string>
#include <cassert>

int main() {
    float var_real = 3.141517f;
    int var_int = 6;
    std::complex<float> var_cplx(2, -4);
    bool var_log = true;
    char var_char = 'a';
    std::string mnsj = "Bienvenidos al curso de Fortran de PROTECO!";

    // Assertions to test the values
    assert(var_real == 3.141517f);
    assert(var_int == 6);
    assert(var_cplx == std::complex<float>(2, -4));
    assert(var_log == true);
    assert(var_char == 'a');
    assert(mnsj == "Bienvenidos al curso de Fortran de PROTECO!");

    std::cout << "All tests passed." << std::endl;  // Corrected line.

    return 0;
}