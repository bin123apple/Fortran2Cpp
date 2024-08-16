#include <iostream>
#include <cmath>

// Assuming randlc is a function that returns a double and takes two doubles as arguments.
// You need to define this function according to your specific implementation.
double randlc(double a, double b);

void ipow46(double a, int exponent, double& result) {
    double q, r, dummy;
    int n, n2;

    result = 1;
    if (exponent == 0) return;

    q = a;
    r = 1;
    n = exponent;

    while (n > 1) {
        n2 = n / 2;
        if (n2 * 2 == n) {
            dummy = randlc(q, q);
            n = n2;
        } else {
            dummy = randlc(r, q);
            n = n - 1;
        }
    }

    dummy = randlc(r, q);
    result = r;
}

// Example usage
int main() {
    double a = 2.0; // Example value for a
    int exponent = 3; // Example value for exponent
    double result;

    ipow46(a, exponent, result);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
