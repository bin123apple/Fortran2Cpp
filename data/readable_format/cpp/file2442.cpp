#include <iostream>
#include <typeinfo>

void foo(void* a, size_t size) {
    int i;
    if (size != sizeof(i)) {
        std::cerr << "Size mismatch, stopping program." << std::endl;
        exit(1);
    }
}

int main() {
    int z = 0;
    foo(&z, sizeof(z));
    return 0;
}