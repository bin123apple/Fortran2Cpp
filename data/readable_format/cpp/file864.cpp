#include <iostream>
#include <memory>
#include <cstdlib>

// Foo class definition
class Foo {
public:
    virtual void doit() { i = 1; }
    virtual int getit() const { return i; }
protected:
    int i{0};
};

// Foo2 class definition, derived from Foo
class Foo2 : public Foo {
public:
    void doit() override {
        i = 2;
        j = 3;
    }
    int getit() const override { return j; }
private:
    int j{0};
};

// Bar class definition
class Bar {
public:
    void doit() { a->doit(); }
    int getit() { return a->getit(); }
    template <typename T>
    void allocate() {
        a = std::make_unique<T>();
    }
private:
    std::unique_ptr<Foo> a;
};

// Main program with tests
int main() {
    Bar a;

    // Test with base class functionality
    a.allocate<Foo>();
    a.doit();
    if (a.getit() != 1) {
        std::cerr << "Test failed for base class. Expected 1, got " << a.getit() << std::endl;
        std::abort();
    }

    // Test with derived class functionality
    a.allocate<Foo2>();
    a.doit();
    if (a.getit() != 3) {
        std::cerr << "Test failed for derived class. Expected 3, got " << a.getit() << std::endl;
        std::abort();
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}