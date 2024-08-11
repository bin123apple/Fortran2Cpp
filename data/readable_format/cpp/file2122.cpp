#include <iostream>

void foo() {
    static int i = 0; // 'static' ensures 'i' retains its value between calls.
    i = 1;
}

int main() {
    foo(); // Call the function to demonstrate its behavior
    return 0;
}