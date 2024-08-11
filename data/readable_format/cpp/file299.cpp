#include <iostream>
#include <cassert>

void f() {
    {
        int k;
        // The scope of k is limited to this block
    }
    // k is not accessible here
}

int main() {
    f();
    std::cout << "Test passed." << std::endl; // Correctly using std::endl for newline
    return 0;
}