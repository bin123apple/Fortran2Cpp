#include <iostream>

namespace datin_I {
    void datin() {
        std::cout << "datin function called" << std::endl;
    }
}

int main() {
    std::cout << "Testing datin function..." << std::endl;
    datin_I::datin();
    return 0;
}