#include <iostream>
#include <vector>

int main() {
    std::vector<int> d(400, 0); // Create a vector with 400 elements initialized to 0
    d[0] = 1; // Set the first element to 1
    int c = 0; // Carry
    int n = 1; // Number of significant digits in the array

    // Double the number 1000 times
    for (int j = 0; j < 1000; ++j) {
        for (int i = 0; i < n; ++i) {
            d[i] = d[i] * 2 + c;
            c = 0;
            if (d[i] >= 10) {
                d[i] -= 10;
                c = 1;
            }
        }
        if (c > 0) { // If there's a carry after the last digit, increase the number of significant digits
            d[n] = c;
            ++n;
            c = 0; // Reset carry for the next iteration
        }
    }

    // Calculate the sum of the digits
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += d[i];
    }

    // Print the result
    std::cout << "Solution: " << sum << std::endl;

    return 0;
}