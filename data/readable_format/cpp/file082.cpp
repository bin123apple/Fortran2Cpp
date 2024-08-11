#include <iostream>
#include <cmath> // For std::fabs()

void plane_eq(double x1, double y1, double z1, 
              double x2, double y2, double z2, 
              double x3, double y3, double z3, 
              double x0, double y0, double& output) {
    double a, b, c, d;

    d = x1*y2*z3 + y1*z2*x3 + z1*x2*y3 - x1*z2*y3 - y1*x2*z3 - z1*y2*x3;

    if(d != 0.0) {
        a = (y2*z3 + y1*z2 + z1*y3 - z2*y3 - y1*z3 - z1*y2) / d;
        b = (x1*z3 + z2*x3 + z1*x2 - x1*z2 - x2*z3 - z1*x3) / d;
        c = (x1*y2 + y1*x3 + x2*y3 - x1*y3 - y1*x2 - y2*x3) / d;
        if(c != 0.0) {
            output = (1.0 - a*x0 - b*y0) / c;
        } else {
            output = 0.0;
        }
    } else {
        output = 0.0;
    }
}

int main() {
    double output;

    plane_eq(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.5, 0.5, output);
    std::cout << "C++ Test Output: " << output << std::endl;

    return 0;
}