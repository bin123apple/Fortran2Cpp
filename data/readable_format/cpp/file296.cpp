#include <vector>
#include <iostream>

// Define namespace m
namespace m {

struct t {
    // Define structure t with potential member variables and methods
};

class t2 {
public:
    t2() : value(0) {}
    void setValue(int val) { value = val; }
    int getValue() const { return value; }
    ~t2() { fini(); }

private:
    int value;
    void fini() {
        // Finalization logic for t2
        std::cout << "t2::fini() called, value: " << value << std::endl;
    }
};

} // namespace m

// Define foo outside of namespace m to avoid ambiguity
void foo(std::vector<m::t>& x, m::t& y, std::vector<m::t2>& aa, m::t2& bb) {
    bb.setValue(42); // Example operation
}

int main() {
    std::vector<m::t> x; // Example vector of t
    m::t y; // Example object of t
    std::vector<m::t2> aa; // Example vector of t2
    m::t2 bb; // Example object of t2

    // Demonstrate foo's effect on bb
    std::cout << "Before calling foo, bb's value is: " << bb.getValue() << std::endl;
    foo(x, y, aa, bb); // Call foo
    std::cout << "After calling foo, bb's value is: " << bb.getValue() << std::endl;

    return 0;
}