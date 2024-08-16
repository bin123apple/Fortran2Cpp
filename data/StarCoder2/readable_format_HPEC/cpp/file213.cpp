#include <iostream>
#include <vector>

// Assuming DATA_TYPE is int and DATA_PRINTF_MODIFIER is "%d" for simplicity
void print_array(int n, const std::vector<int>& w) {
    for (int i = 0; i < n; ++i) {
        std::cout << w[i] << " "; // Using " " for DATA_PRINTF_MODIFIER equivalent
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl; // Additional newline at the end
}

int main() {
    // Example usage
    std::vector<int> myArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(myArray.size(), myArray);
    
    return 0;
}
