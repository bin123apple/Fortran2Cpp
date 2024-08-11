#include <iostream>

double stheta_sq(double x) {
    if (x <= -0.5) {
        return 0.0;
    }
    if (x < 0.5) {
        return x + 0.5;
    }
    return 1.0;
}

int main() {
    // Example usage
    double x = 0.3;
    std::cout << "stheta_sq(" << x << ") = " << stheta_sq(x) << std::endl;
    
    return 0;
}