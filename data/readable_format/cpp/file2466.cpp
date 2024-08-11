#include <iostream>
#include <cassert>
#include <cmath> // Include for fabs

void ds2hms(double secs, int &hh, int &mm, double &ss) {
    const double s2h = 1.0 / 3600.0;
    const double s2m = 1.0 / 60.0;

    double s = secs;
    int h = static_cast<int>(s * s2h);
    s -= 3600 * h;
    int m = static_cast<int>(s * s2m);
    s -= 60 * m;

    hh = h;
    mm = m;
    ss = s;
}

void test_ds2hms() {
    int hh, mm;
    double ss;

    // Test case 1
    ds2hms(3661.0, hh, mm, ss);
    assert(hh == 1);
    assert(mm == 1);
    assert(fabs(ss - 1.0) < 1e-9); // Using fabs for floating-point comparison

    // Test case 2
    ds2hms(7322.0, hh, mm, ss);
    assert(hh == 2);
    assert(mm == 2);
    assert(fabs(ss - 2.0) < 1e-9);

    // Test case 3
    ds2hms(59.0, hh, mm, ss);
    assert(hh == 0);
    assert(mm == 0);
    assert(fabs(ss - 59.0) < 1e-9);

    // Test case 4
    ds2hms(3600.0, hh, mm, ss);
    assert(hh == 1);
    assert(mm == 0);
    assert(fabs(ss) < 1e-9); // Adjusted for clarity

    // Test case 5
    ds2hms(0.0, hh, mm, ss);
    assert(hh == 0);
    assert(mm == 0);
    assert(fabs(ss) < 1e-9); // Adjusted for clarity

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_ds2hms();
    return 0;
}