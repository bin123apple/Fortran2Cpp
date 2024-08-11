#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

class SimpleQuadpack {
public:
    // Example of a basic numerical integration method (Simpson's Rule)
    double integrate(const std::function<double(double)>& f, double a, double b, int n) {
        double h = (b - a) / n;
        double s = f(a) + f(b);
        for (int i = 1; i < n; i += 2) {
            s += 4 * f(a + i * h);
        }
        for (int i = 2; i < n - 1; i += 2) {
            s += 2 * f(a + i * h);
        }
        return s * h / 3;
    }
};

// Example function to integrate: f(x) = x^2
double f(double x) {
    return x * x;
}

int main() {
    SimpleQuadpack qp;
    double a = 0; // lower limit of integration
    double b = 1; // upper limit of integration
    int n = 1000; // number of subdivisions

    double result = qp.integrate(f, a, b, n);
    std::cout << "Integration result: " << result << std::endl;
    return 0;
}