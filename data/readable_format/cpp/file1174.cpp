#include <iostream>
#include <vector>
#include <cassert>

// Function declarations

template <typename T>
void times2scalar(T& value);

template <typename T>
void times2array(std::vector<T>& array);

template <typename T>
void times2boo(const T& value, int& resi, float& resr);

// Function definitions

template <typename T>
void times2scalar(T& value) {
    value *= 2;
}

template <typename T>
void times2array(std::vector<T>& array) {
    for (auto& elem : array) {
        elem *= 2;
    }
}

template <>
void times2boo(const int& value, int& resi, float& resr) {
    resi = value * 2;
    resr = 0; // Setting to 0 as it's not used in this specialization
}

template <>
void times2boo(const float& value, int& resi, float& resr) {
    resi = 0; // Setting to 0 as it's not used in this specialization
    resr = value * 2.0f;
}

// Unit test functions

void test_times2scalar() {
    int x = 2;
    float y = 3.0f;
    
    times2scalar(x);
    assert(x == 4);

    times2scalar(y);
    assert(y == 6.0f);

    std::cout << "test_times2scalar passed." << std::endl;
}

void test_times2array() {
    std::vector<int> a = {1, 2, 3};
    std::vector<float> b = {1.0f, 2.0f, 3.0f};

    times2array(a);
    assert(a[0] == 2 && a[1] == 4 && a[2] == 6);

    times2array(b);
    assert(b[0] == 2.0f && b[1] == 4.0f && b[2] == 6.0f);

    std::cout << "test_times2array passed." << std::endl;
}

void test_times2boo() {
    int x = 2, rx;
    float y = 3.0f, ry;

    times2boo(x, rx, ry);
    assert(rx == 4);

    times2boo(y, rx, ry);
    assert(ry == 6.0f);

    std::cout << "test_times2boo passed." << std::endl;
}

int main() {
    test_times2scalar();
    test_times2array();
    test_times2boo();

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}