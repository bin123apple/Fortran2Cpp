#include <iostream>

namespace parameter {
    constexpr int lx = 128;
    constexpr int ly = 128;
    constexpr int lz = 128;
    constexpr int lstep = 10;
    constexpr int lnpx = 2;
    constexpr int lnpy = 2;
    constexpr int lnpz = 2;
    constexpr int llx = lx / lnpx;
    constexpr int lly = ly / lnpy;
    constexpr int llz = lz / lnpz;
}

int main() {
    std::cout << "lx: " << parameter::lx << std::endl;
    std::cout << "ly: " << parameter::ly << std::endl;
    std::cout << "lz: " << parameter::lz << std::endl;
    std::cout << "lstep: " << parameter::lstep << std::endl;
    std::cout << "lnpx: " << parameter::lnpx << std::endl;
    std::cout << "lnpy: " << parameter::lnpy << std::endl;
    std::cout << "lnpz: " << parameter::lnpz << std::endl;
    std::cout << "llx: " << parameter::llx << std::endl;
    std::cout << "lly: " << parameter::lly << std::endl;
    std::cout << "llz: " << parameter::llz << std::endl;

    return 0;
}