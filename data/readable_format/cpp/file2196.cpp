#include <iostream>
#include <iomanip>

int main() {
    double r = -3e2;
    double s = r;
    std::cout << std::fixed << std::setprecision(1) << r << " " << s << std::endl;
    return 0;
}