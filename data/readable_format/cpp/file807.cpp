#include <iostream>
#include <array>

int main() {
    const int n = 5;
    std::array<int, n> arr = {1, 2, 3, 4, 5};
    int sum = 0;

    for(int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    std::cout << "Sum = " << sum << std::endl;
    return 0;
}