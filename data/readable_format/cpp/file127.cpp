#include <iostream>
#include <cassert>
#include <string>
#include <bitset>

std::string numberToString(int num, int base) {
    if (base == 10) {
        return std::to_string(num);
    } else if (base == 2) {
        return std::bitset<20>(num).to_string().erase(0, std::bitset<20>(num).to_string().find_first_not_of('0'));
    } else {
        throw std::invalid_argument("Unsupported base");
    }
}

bool isPalindromic(const std::string& str) {
    size_t n = str.size();
    for (size_t i = 0; i < n / 2; ++i) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

void runTests() {
    // Test numberToString with base 10
    assert(numberToString(123, 10) == "123");
    std::cout << "Test passed: numberToString(123, 10)" << std::endl;

    // Test numberToString with base 2
    assert(numberToString(5, 2) == "101");
    std::cout << "Test passed: numberToString(5, 2)" << std::endl;

    // Test isPalindromic
    assert(isPalindromic("12321") == true);
    std::cout << "Test passed: isPalindromic('12321')" << std::endl;
}

void solve() {
    int sum = 0;
    for (int i = 1; i <= 1000000; ++i) {
        std::string n_10 = numberToString(i, 10);
        std::string n_2 = numberToString(i, 2);
        if (isPalindromic(n_10) && isPalindromic(n_2)) {
            sum += i;
            std::cout << n_10 << ", " << n_2 << std::endl;
        }
    }
    std::cout << "result = " << sum << std::endl;
}

int main() {
    runTests();
    solve();
    return 0;
}