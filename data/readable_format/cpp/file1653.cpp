#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 4> i = {1, 1, 1, 1};
    std::array<int, 4> z = {1, 1, -1, -1};

    // Applying the condition: where elements in z are less than 0, set them to 1
    std::transform(z.begin(), z.end(), z.begin(), [](int elem) {
        return elem < 0 ? 1 : elem;
    });

    // Checking if any element in z is not equal to its counterpart in i
    if (!std::equal(z.begin(), z.end(), i.begin())) {
        std::exit(1); // Stops the program with exit code 1 if any element in z is not equal to i
    }

    return 0; // Normal program termination
}