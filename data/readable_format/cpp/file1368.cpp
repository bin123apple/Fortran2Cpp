#include <iostream>
#include <vector>
#include <cassert>

class T1 {
public:
    int i;

    // Overload the assignment operator to mimic Fortran's procedure.
    T1& operator=(const T1& rhs) {
        i = rhs.i;
        return *this;
    }
};

std::vector<T1> return_t1(const std::vector<T1>& arg) {
    // Directly return a copy of the argument vector.
    return arg;
}

std::vector<T1>& return_t1_p(std::vector<T1>& arg) {
    // Return the reference of the input vector to mimic Fortran pointer behavior.
    // This function now takes a non-const reference, to allow returning a modifiable reference.
    return arg;
}

int main() {
    std::vector<T1> v1(3), v2;

    // Test 1: Assignment and return_t1 function
    for (int i = 0; i < 3; ++i) {
        v1[i].i = i + 1;
    }
    v2 = return_t1(v1);
    for (size_t i = 0; i < v2.size(); ++i) {
        assert(v2[i].i == v1[i].i);
    }
    std::cout << "Test 1 Passed" << std::endl;

    // Test 2: Assignment and return_t1_p function
    for (int i = 0; i < 3; ++i) {
        v1[i].i = i + 4;
    }
    std::vector<T1>& v2_ref = return_t1_p(v1);
    for (size_t i = 0; i < v2_ref.size(); ++i) {
        assert(v2_ref[i].i == v1[i].i);
    }
    std::cout << "Test 2 Passed" << std::endl;

    return 0;
}