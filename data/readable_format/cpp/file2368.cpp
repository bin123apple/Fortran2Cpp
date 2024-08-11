#include <iostream>
#include <memory>

class T {
public:
    virtual ~T() = default;
};

void one() {
    auto p1 = std::make_shared<T>();
    std::shared_ptr<T> p2 = p1;
    std::cout << "one: p2 points to p1" << std::endl;
}

void two() {
    auto p1 = std::make_shared<T>();
    std::shared_ptr<T> p2 = p1;
    std::cout << "two: p2 points to allocated p1" << std::endl;
}

void three() {
    auto p1 = std::make_shared<T>();
    std::shared_ptr<T> p2 = p1;
    std::cout << "three: p2 points to allocated p1" << std::endl;
}

void four() {
    auto p1 = std::make_shared<T>();
    std::shared_ptr<T> p2 = p1;
    std::cout << "four: p2 points to allocated p1" << std::endl;
}

int main() {
    one();
    two();
    three();
    four();
    return 0;
}