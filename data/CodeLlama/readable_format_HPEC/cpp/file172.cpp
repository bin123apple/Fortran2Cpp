#include <cmath>

// Assuming the prototype of randlc is as follows:
// double randlc(double a, double b);

void ipow46(double a, int exponent, double& result) {
    double q, r, dummy;
    int n, n2;
    result = 1.0;
    if (exponent == 0) return;
    q = a;
    r = 1.0;
    n = exponent;

    do {
        n2 = n / 2;
        if (n2 * 2 == n) {
            dummy = randlc(q, q);
            n = n2;
        } else {
            dummy = randlc(r, q);
            n = n - 1;
        }
    } while (n > 1);
    dummy = randlc(r, q);
    result = r;
}

// Example usage
#include <iostream>

int main() {
    double a = 2.0;
    int exponent = 10;
    double result;

    ipow46(a, exponent, result);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
