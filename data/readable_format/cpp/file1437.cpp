#include <iostream>
#include <cmath>

int main() {
    int64_t sum = 2; // Initialize sum to account for 2, the only even prime number.
    bool isPrime;

    for (int64_t n = 3; n < 2000000; n += 2) { // Check only odd numbers starting from 3.
        isPrime = true;
        for (int64_t i = 3; i <= static_cast<int64_t>(std::sqrt(n)); i += 2) { // Check divisibility by odd numbers only.
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            sum += n;
        }
    }

    std::cout << "solution: " << sum << std::endl;

    return 0;
}