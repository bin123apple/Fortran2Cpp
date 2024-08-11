#include <iostream>
#include <cstdlib>
#include <cstring>

bool isHelloWorld(const char* c) {
    return strcmp(c, "Hello, world!") == 0;
}

int main() {
    if (!isHelloWorld("Hello, world!")) {
        std::abort();
    }

    // This will not trigger in the main program but is here to illustrate failure
    if (!isHelloWorld("Goodbye, world!")) {
        std::abort();
    }

    return 0;
}