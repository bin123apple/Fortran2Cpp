namespace turbKE {
    // Constants are declared as `constexpr` for compile-time evaluation
    // The `double` type in C++ is equivalent to `real*8` in Fortran for representing floating-point numbers
    constexpr double ke_C_mu = 0.09;
    constexpr double ke_C_eps1 = 1.44;
    constexpr double ke_C_eps2 = 1.92;
    constexpr double ke_sigma = 1.3;
    constexpr double ke_otherstuff = 1.50; // In C++, 1.50 is already a double, 'd0' suffix is not needed
}