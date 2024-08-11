#include <iostream>

const int ntq = 200;
const int ntc = 0;
const int nss = 1;
const int nt = ntq + nss * ntc;
const int ng0 = 100;
const int ng = ntq * ng0;
const int nl = 13;
const int ngd0 = 500;
const int ngd = ntq * ngd0;
const int ntqss = ntq + nss;
const int norbit = 800;
const int Ngrid = 0;

int main() {
    std::cout << "ntq: " << ntq << std::endl;
    std::cout << "ntc: " << ntc << std::endl;
    std::cout << "nss: " << nss << std::endl;
    std::cout << "nt: " << nt << std::endl;
    std::cout << "ng0: " << ng0 << std::endl;
    std::cout << "ng: " << ng << std::endl;
    std::cout << "nl: " << nl << std::endl;
    std::cout << "ngd0: " << ngd0 << std::endl;
    std::cout << "ngd: " << ngd << std::endl;
    std::cout << "ntqss: " << ntqss << std::endl;
    std::cout << "norbit: " << norbit << std::endl;
    std::cout << "Ngrid: " << Ngrid << std::endl;

    return 0;
}