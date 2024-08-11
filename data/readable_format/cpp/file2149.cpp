#include <iostream>
#include <string>
#include <array>
#include <algorithm>

class A {
public:
    int b;
    std::string c;

    A(int b = 0, std::string c = "") : b(b), c(c) {
        if (c.size() > 8) {
            c.resize(8);
        }
    }

    // Assignment operators
    A& operator=(const A& other) {
        b = other.c.length();
        c = other.c;
        return *this;
    }

    A& operator=(const std::string& str) {
        b += 1;
        c = str;
        return *this;
    }

    // Inequality operator
    bool operator!=(const A& other) const {
        return b != other.b || c != other.c;
    }
};

// Global variables
std::array<A, 4> x = { A(0, "one"), A(0, "two"), A(0, "three"), A(0, "four") };
std::array<A, 4> y;
std::array<bool, 4> l1 = { true, false, false, true };

// Functions
A foo(const A& m) {
    return A(0, m.c);
}

void test_where_char1() {
    for (size_t i = 0; i < y.size(); ++i) {
        if (l1[i]) {
            y[i] = A(0, "null");
        } else {
            y[i] = x[i];
        }
    }
}

void test_where_char2() {
    for (auto& elem : y) {
        if (elem.c != "null") {
            elem = A(99, "non-null");
        }
    }
}

bool any_not_equal(const std::array<A, 4>& arr, const std::array<A, 4>& compare) {
    return std::any_of(arr.begin(), arr.end(), [&compare, &arr](const A& elem) {
        size_t idx = &elem - &arr[0];
        return elem != compare[idx];
    });
}

int main() {
    y = x;

    test_where_char1();
    test_where_char2();

    std::array<A, 4> compare = { A(4, "null"), A(8, "non-null"), A(8, "non-null"), A(4, "null") };
    if (any_not_equal(y, compare)) {
        std::cerr << "STOP 1" << std::endl;
        return 1;
    }

    return 0;
}