#include <iostream>
#include <string>
#include <cstdlib> // for std::abort

namespace foo {
    std::string pop(int n) {
        return n > 0 ? std::string(1, 'a') : std::string();
    }

    std::string push(int n) {
        return n != 0 ? std::string(1, 'a') : std::string();
    }
}

int main() {
    using namespace foo;

    if (pop(0).length() != 0) std::abort();
    if (pop(1).length() != 1) std::abort();
    if (push(0).length() != 0) std::abort();
    if (push(1).length() != 1) std::abort();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}