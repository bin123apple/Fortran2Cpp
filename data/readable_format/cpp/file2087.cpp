#include <iostream>
#include <memory>

class T {
public:
    T() = default;
    virtual ~T() = default;
};

class Mod {
public:
    void s1(T& x) {
        std::cout << "s1 called" << std::endl;
    }

    template<typename AnyType>
    void s2(std::unique_ptr<AnyType>& x) {
        std::cout << "s2 called with integer" << std::endl;
    }
};

int main() {
    Mod myMod;
    T myT;

    myMod.s1(myT); // Test s1

    auto myInt = std::make_unique<int>(5);
    myMod.s2(myInt); // Test s2 with an int

    std::cout << "Tests completed successfully." << std::endl;

    return 0;
}