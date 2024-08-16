#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> a(100);

    #pragma omp parallel for private(std::string str)
    for (int i = 1; i <= 100; ++i) {
        std::ostringstream oss;
        oss << i;
        std::string str = oss.str();
        a[i-1] = str; // note: Fortran arrays are 1-based, C++ arrays are 0-based
    }

    std::cout << "a(i) = " << a[22] << std::endl; // equivalent to a(23) in Fortran

    return 0;
}
