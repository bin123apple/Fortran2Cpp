#include<iostream>

void mysub(double a, double b, double& c, double& d) {
    c = a + b;
    d = a - b;
}

int main() {
    double a = 5.0, b = 3.0;
    double c, d;
    
    mysub(a, b, c, d);
    
    std::cout << "c = " << c << ", d = " << d << std::endl;
    
    return 0;
}