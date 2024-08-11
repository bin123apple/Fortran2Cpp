#include <iostream>
#include <cstring>
#include <cstdlib>

// Define a structure to represent the common block /block/
struct Block {
    int a[2];
    float b;
} block = {{42, 43}, 2.0};

// Define a structure to represent the common block /block2/
struct Block2 {
    char s[16]; // One extra character to null-terminate the string
} block2 = {"Hello World    "}; // Ensure the string is padded to 15 chars

void abort_program() {
    std::cerr << "Abort called!" << std::endl;
    std::exit(1);
}

void test() {
    // Access common block variables through the structures
    char c[16];
    int d = block.a[0];
    int e = block.a[1];
    float f = block.b;
    std::strcpy(c, block2.s);

    if (d != 42 || e != 43 || f != 2.0f) {
        abort_program();
    }
    if (std::strncmp(c, "Hello World    ", 15) != 0) {
        abort_program();
    }
}

int main() {
    // Call the test function
    test();
    return 0;
}