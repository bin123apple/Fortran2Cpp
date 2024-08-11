#include <iostream>
#include <memory>

// Abstract base class
class Base {
public:
    int x;
    Base() : x(0) {}
    virtual ~Base() = default; // Ensure proper cleanup
    virtual int getval() const = 0; // Pure virtual function
};

// ChildAType class inheriting from Base
class ChildAType : public Base {
public:
    // Constructor
    ChildAType(int x) { this->x = x; }
    // Override getval
    int getval() const override {
        return x;
    }
    // Additional member functions
    static std::shared_ptr<ChildAType> alias_t(ChildAType& self) {
        return std::shared_ptr<ChildAType>(&self, [](ChildAType*){});
    }
    static std::shared_ptr<ChildAType> alias_c(const ChildAType& self) {
        return std::shared_ptr<ChildAType>(const_cast<ChildAType*>(&self), [](ChildAType*){});
    }
};

// ChildBType class inheriting from Base
class ChildBType : public Base {
public:
    // Constructor
    ChildBType(int x) { this->x = x; }
    // Override getval
    int getval() const override {
        return x * 2;
    }
};

// Unit test code
void testGetVal() {
    ChildAType a(10);
    ChildBType b(10);

    std::cout << "Testing getval() for ChildAType: ";
    if (a.getval() == 10) std::cout << "PASS" << std::endl;
    else std::cout << "FAIL" << std::endl;

    std::cout << "Testing getval() for ChildBType: ";
    if (b.getval() == 20) std::cout << "PASS" << std::endl;
    else std::cout << "FAIL" << std::endl;
}

int main() {
    testGetVal();

    // Demonstrating alias_t and alias_c with manual checks
    ChildAType a(10);
    auto aliasT = ChildAType::alias_t(a);
    auto aliasC = ChildAType::alias_c(a);

    std::cout << "Testing alias_t for ChildAType: ";
    if (aliasT->getval() == 10) std::cout << "PASS" << std::endl;
    else std::cout << "FAIL" << std::endl;

    std::cout << "Testing alias_c for ChildAType: ";
    if (aliasC->getval() == 10) std::cout << "PASS" << std::endl;
    else std::cout << "FAIL" << std::endl;

    return 0;
}