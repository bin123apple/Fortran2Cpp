#include <iostream>
#include <cmath>

// Function declaration is optional here since definition comes before its use
void drotg(double &da, double &db, double &c, double &s) {
    const double one = 1.0;
    const double zero = 0.0;
    double roe, scale, r, z;

    roe = db;
    if (std::abs(da) > std::abs(db)) {
        roe = da;
    }

    scale = std::abs(da) + std::abs(db);

    if (scale == zero) {
        c = one;
        s = zero;
        r = zero;
    } else {
        r = scale * std::sqrt((da / scale) * (da / scale) + (db / scale) * (db / scale));
        r = std::copysign(one, roe) * r;
        c = da / r;
        s = db / r;
    }

    z = s;
    if (std::abs(c) > zero && std::abs(c) <= one) {
        z = one / c;
    }

    da = r;
    db = z;
}

int main() {
    double da, db, c, s;

    // Test 1
    da = 3.0;
    db = 4.0;
    drotg(da, db, c, s);
    std::cout << "Test 1: " << da << " " << db << " " << c << " " << s << std::endl;

    // Test 2
    da = 0.0;
    db = 0.0;
    drotg(da, db, c, s);
    std::cout << "Test 2: " << da << " " << db << " " << c << " " << s << std::endl;

    // Test 3
    da = -3.0;
    db = 4.0;
    drotg(da, db, c, s);
    std::cout << "Test 3: " << da << " " << db << " " << c << " " << s << std::endl;

    return 0;
}