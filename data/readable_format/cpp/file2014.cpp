#include <iostream>

// Forward declaration with default values, assuming the purpose is similar
void hoge(int l1 = 1, int k = 0); 

// Main function, corresponding to 'sub' entry, assuming 'l2' was intended to be used
void sub(int l2, int k) {
    hoge(l2, k); // Assuming the intention was to pass 'l2' as 'l1' in 'hoge'
}

// Function corresponding to 'hoge' entry
void hoge(int l1, int k) {
    int m = 1;
    if (l1 >= 1 && l1 <= 4) {
        m = l1;
    }
    // Assuming 'm' is to be used, this example just prints it
    std::cout << "m = " << m << std::endl;
}

int main() {
    sub(2, 0); // Example usage
    return 0;
}