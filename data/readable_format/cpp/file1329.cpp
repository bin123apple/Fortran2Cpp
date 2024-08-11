#include <iostream>
#include <cmath>
#include <cstdint>

bool concealed_sqr(int64_t tmp) {
    bool result = tmp % 10 == 0;
    int64_t i = tmp / 100;
    int64_t a = 9;

    while (i > 0 && result) {
        result = (i % 10 == a);
        i = i / 100;
        a--;
    }

    return result;
}

void perform_tests() {
    std::cout << "Testing concealed_sqr function:" << std::endl;
    std::cout << "Test with 1929394959697989990: " << concealed_sqr(1929394959697989990) << std::endl;
    std::cout << "Test with 1020304050607080900: " << !concealed_sqr(1020304050607080900) << std::endl;
}

int main() {
    perform_tests();
    return 0;
}