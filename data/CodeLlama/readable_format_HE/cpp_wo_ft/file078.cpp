#include <cmath>
#include <cstdlib>
#include <iostream>

bool any_int(double a, double b, double c) {
    if (std::floor(a) != a) {
        return false;
    }
    if (std::floor(b) != b) {
        return false;
    }
    if (std::floor(c) != c) {
        return false;
    }
    if (a + b == c || a + c == b || b + c == a) {
        return true;
    }
    return false;
}

int main() {
    bool result;

    result = any_int(2.0, 3.0, 1.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(2, 3, 1) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(2.5, 2.0, 3.0);
    if (result) {
        std::cerr << "Assertion failed: any_int(2.5, 2, 3) == false" << std::endl;
        std::exit(1);
    }

    result = any_int(1.5, 5.0, 3.5);
    if (result) {
        std::cerr << "Assertion failed: any_int(1.5, 5, 3.5) == false" << std::endl;
        std::exit(1);
    }

    result = any_int(2.0, 6.0, 2.0);
    if (result) {
        std::cerr << "Assertion failed: any_int(2, 6, 2) == false" << std::endl;
        std::exit(1);
    }

    result = any_int(4.0, 2.0, 2.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(4, 2, 2) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(2.2, 2.2, 2.2);
    if (result) {
        std::cerr << "Assertion failed: any_int(2.2, 2.2, 2.2) == false" << std::endl;
        std::exit(1);
    }

    result = any_int(-4.0, 6.0, 2.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(-4, 6, 2) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(2.0, 1.0, 1.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(2, 1, 1) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(3.0, 4.0, 7.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(3, 4, 7) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(3.01, 4.0, 7.0);
    if (result) {
        std::cerr << "Assertion failed: any_int(3.01, 4, 7) == false" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}

[C]
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool any_int(double a, double b, double c) {
    if (floor(a) != a) {
        return false;
    }
    if (floor(b) != b) {
        return false;
    }
    if (floor(c) != c) {
        return false;
    }
    if (a + b == c || a + c == b || b + c == a) {
        return true;
    }
    return false;
}

int main() {
    bool result;

    result = any_int(2.0, 3.0, 1.0);
    if (!result) {
        fprintf(stderr, "Assertion failed: any_int(2, 3, 1) == true
");
        exit(1);
    }

    result = any_int(2.5, 2.0, 3.0);
    if (result) {
        fprintf(stderr, "Assertion failed: any_int(2.5, 2, 3) == false
");
        exit(1);
    }

    result = any_int(1.5, 5.0, 3.5);
    if (result) {
        fprintf(stderr, "Assertion failed: any_int(1.5, 5, 3.5) == false
");
        exit(1);
    }

    result = any_int(2.0, 6.0, 2.0);
    if (result) {
        fprintf(stderr, "Assertion failed: any_int(2, 6, 2) == false
");
        exit(1);
    }

    result = any_int(4.0, 2.0, 2.0);
    if (!result) {
        fprintf(stderr, "Assertion failed: any_int(4, 2, 2) == true
");
        exit(1);
    }

    result = any_int(2.2, 2.2, 2.2);
    if (result) {
        fprintf(stderr, "Assertion failed: any_int(2.2, 2.2, 2.2) == false
");
        exit(1);
    }

    result = any_int(-4.0, 6.0, 2.0);
    if (!result) {
        fprintf(stderr, "Assertion failed: any_int(-4, 6, 2) == true
");
        exit(1);
    }

    result = any_int(2.0, 1.0, 1.0);
    if (!result) {
        fprintf(stderr, "Assertion failed: any_int(2, 1, 1) == true
");
        exit(1);
    }

    result = any_int(3.0, 4.0, 7.0);
    if (!result) {
        fprintf(stderr, "Assertion failed: any_int(3, 4, 7) == true
");
        exit(1);
    }

    result = any_int(3.01, 4.0, 7.0);
    if (result) {
        fprintf(stderr, "Assertion failed: any_int(3.01, 4, 7) == false
");
        exit(1);
    }

    printf("All tests passed.
");
    return 0;
}

[Python]
def any_int(a, b, c):
    if a != int(a):
        return False
    if b != int(b):
        return False
    if c != int(c):
        return False
    return (a + b == c or a + c == b or b + c == a)

if not any_int(2.0, 3.0, 1.0):
    print("Assertion failed: any_int(2, 3, 1) == true")
    exit(1)

if any_int(2.5, 2.0, 3.0):
    print("Assertion failed: any_int(2.5, 2, 3) == false")
    exit(1)

if any_int(1.5, 5.0, 3.5):
    print("Assertion failed: any_int(1.5, 5, 3.5) == false
