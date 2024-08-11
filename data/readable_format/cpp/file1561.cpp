#include <iostream>
#include <cassert>

int main() {
    char c = 'A'; // Assign 'A' to c
    std::cout << "Test character assignment and retrieval: ";
    std::cout << "Expected: A, Got: " << c << std::endl;
    assert(c == 'A'); // Simple check to ensure c is 'A'
    return 0;
}