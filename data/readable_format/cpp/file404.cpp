#include <cmath>
#include <iostream>

class Functions {
public:
    static double epsilon;

    static double f_sqrt(double x) {
        return std::pow(x, 2) - 4.0;
    }

    static double fprime_sqrt(double x) {
        return 2.0 * x;
    }

    static double f_quartic(double x) {
        return std::pow(x - 1.0, 4) - epsilon;
    }

    static double fprime_quartic(double x) {
        return 4.0 * std::pow(x - 1.0, 3);
    }
};

double Functions::epsilon = 1e-6;

void testFunction(const std::string& name, double (*func)(double), double input, double expected) {
    double result = func(input);
    std::cout << name << "(" << input << ") = " << result;
    if (std::fabs(result - expected) < 1e-6) {
        std::cout << " [PASS]";
    } else {
        std::cout << " [FAIL]";
    }
    std::cout << std::endl;
}

int main() {
    Functions::epsilon = 1e-6;

    testFunction("f_sqrt", Functions::f_sqrt, 2.0, 0.0);
    testFunction("fprime_sqrt", Functions::fprime_sqrt, 2.0, 4.0);
    testFunction("f_quartic", Functions::f_quartic, 2.0, 1.0 - Functions::epsilon);
    testFunction("fprime_quartic", Functions::fprime_quartic, 2.0, 4.0);

    return 0;
}