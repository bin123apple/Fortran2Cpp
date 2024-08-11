#include <iostream>
#include <memory> // For std::shared_ptr
#include <cassert> // For assert

namespace mpoint {

struct mytype {
    int i;
    mytype(int val) : i(val) {}
};

std::shared_ptr<mytype> get(const mytype& a) {
    return std::make_shared<mytype>(a);
}

std::shared_ptr<mytype> get2(const mytype& a) {
    return std::make_shared<mytype>(a);
}

} // end namespace mpoint

void test_get_function() {
    using namespace mpoint;
    mytype x(42);
    auto y = get(x);
    assert(y->i == 42); // Test passes if y->i is 42
    std::cout << "Test get function passed." << std::endl;
}

void test_get2_function() {
    using namespace mpoint;
    mytype x(112);
    auto y = get2(x);
    assert(y->i == 112); // Test passes if y->i is 112
    std::cout << "Test get2 function passed." << std::endl;
}

int main() {
    test_get_function();
    test_get2_function();
    return 0;
}