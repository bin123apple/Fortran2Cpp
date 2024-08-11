// main.cpp
#include <iostream>
#include <memory>
#include <vector>

struct ParticleType {
    std::shared_ptr<std::vector<int>> p;
};

int main() {
    auto t = std::make_shared<std::vector<ParticleType>>(1);
    (*t)[0].p = std::make_shared<std::vector<int>>(0);

    bool f = (*t)[0].p != nullptr;

    std::cout << (f ? "Test passed: t(i).p is associated." : "Test failed: t(i).p is not associated.") << std::endl;

    return 0;
}