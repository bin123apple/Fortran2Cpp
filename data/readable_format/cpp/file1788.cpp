#include <iostream>
#include <memory>

class t {
public:
    int i;
    // Adding a virtual destructor to ensure proper cleanup of derived classes
    virtual ~t() = default;
};

class t2 : public t {
public:
    int j;
};

int main() {
    // Using a smart pointer for automatic memory management
    std::unique_ptr<t> a = std::make_unique<t2>();

    // Static casting is safe here because we know 'a' points to an object of type 't2'
    auto a_t2 = static_cast<t2*>(a.get());
    a_t2->i = 1;
    a_t2->j = 2;

    std::cout << a->i << std::endl;
    if (a->i != 1) {
        std::exit(1);
    }

    // No need for type selection like in Fortran; we already know the dynamic type
    std::cout << a_t2->j << std::endl;
    if (a_t2->j != 2) {
        std::exit(2);
    }

    return 0;
}