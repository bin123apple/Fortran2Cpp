#include <iostream>

int main() {
    bool b;
    b = (b == b); // This will always be true if b is initialized.
    b = (b != b); // This will always be false.
    return 0;
}