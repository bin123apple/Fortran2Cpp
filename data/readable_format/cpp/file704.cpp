#include <iostream>
#include <array>
#include <cstdint>

void perform_operations(int32_t& a, int16_t& b, float& c, double& d, std::array<int, 10>& e, float& f, int& result) {
    a = 1;
    b = 2;
    c = 3.0f;
    d = 4.0;
    e.fill(5);
    f = 6.0f;
    
    a = a + 4;
    b = 4 - b;
    c = c * 2;
    d = 2 / d;
    
    if (a != 5 || b != 2 || c != 6.0f || d != 0.5) {
        result = 1;
        return;
    }

    d = 1.2;
    a = a + static_cast<int32_t>(c) + static_cast<int32_t>(d);
    b = b - (static_cast<int16_t>(a) + static_cast<int16_t>(c) + static_cast<int16_t>(d));

    if (a != 12 || b != -17) {
        result = 2;
        return;
    }

    a = static_cast<int32_t>(c) + static_cast<int32_t>(d) + a;
    b = static_cast<int16_t>(a) + static_cast<int16_t>(c) + static_cast<int16_t>(d) - b;

    if (a != 19 || b != 43) {
        result = 3;
        return;
    }

    b = (static_cast<int16_t>(a) + static_cast<int16_t>(c) + static_cast<int16_t>(d)) - b;
    a = 32;
    a = static_cast<int32_t>(a / 3);

    if (a != 10 || b != -16) {
        result = 4;
        return;
    }

    result = 0;
}

int main() {
    int32_t a;
    int16_t b;
    float c, f;
    double d;
    std::array<int, 10> e;
    int result;
    
    perform_operations(a, b, c, d, e, f, result);
    std::cout << "Operation Result: " << result << std::endl;
    return 0;
}