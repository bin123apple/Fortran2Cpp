#include <iostream>
#include <vector>

void print_array(int n, std::vector<double> outArray) {
    for (int i = 1; i <= n; i++) {
        std::cout << outArray[i - 1];
        if ((i - 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
}

int main() {
    int n = 10; // Replace with your desired value of n
    std::vector<double> outArray(n);
    // Initialize outArray with your desired values

    print_array(n, outArray);

    return 0;
}
