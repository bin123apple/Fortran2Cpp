#include <iostream>

class GreetMod {
public:
    void greet_world() const {
        std::cout << "Greet World" << std::endl;
    }
};

int main() {
    GreetMod gm;
    gm.greet_world();
    return 0;
}