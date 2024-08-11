#include <iostream>
#include <memory>
#include <cassert>

// Abstract base class
class CAbstr {
public:
    int i = 0;
    
    virtual ~CAbstr() = default;
    virtual std::unique_ptr<CAbstr> clone() const = 0;
};

// Derived class TA
class TA : public CAbstr {
public:
    std::unique_ptr<CAbstr> f;

    TA() = default;

    // Copy constructor
    TA(const TA& other) : CAbstr(other) {
        if (other.f) {
            f = other.f->clone();
        }
    }

    // Copy assignment operator
    TA& operator=(const TA& other) {
        if (this != &other) {
            CAbstr::operator=(other);
            if (other.f) {
                f = other.f->clone();
            } else {
                f = nullptr;
            }
        }
        return *this;
    }

    TA(const CAbstr& x) {
        f = x.clone();
    }

    std::unique_ptr<CAbstr> clone() const override {
        return std::make_unique<TA>(*this);
    }
};

// Derived class TB
class TB : public CAbstr {
public:
    std::unique_ptr<CAbstr> clone() const override {
        return std::make_unique<TB>(*this);
    }
};

void set(TA& y, const CAbstr& x) {
    y = TA(x);
}

void testSetFunction() {
    TA res;
    TB var;

    set(res, var);

    // Test: res should have i = 0 (default value)
    assert(res.i == 0);
    std::cout << "Test passed: res.i is 0" << std::endl;
}

int main() {
    testSetFunction();
    return 0;
}