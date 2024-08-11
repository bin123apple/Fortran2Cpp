#include <iostream>
#include <vector>
#include <stdexcept>

class Foo {
public:
    std::vector<int> a;
    std::vector<int> b;
};

class Bar {
public:
    Foo foo; // Composition to access `a` and `b` from Foo

    void mysub(int n, const std::vector<float>& parray1) {
        if ((n == 1) && parray1.size() != 10) {
            std::cerr << "Error: Expected size 10 for n=1" << std::endl;
            exit(1);
        }
        if ((n == 2) && parray1.size() != 42) {
            std::cerr << "Error: Expected size 42 for n=2" << std::endl;
            exit(2);
        }
    }
};

int main() {
    Foo foo;
    Bar bar;
    std::vector<float> z(100, 0.0f);

    foo.a = {1, 6};
    foo.b = {10, 47};

    // Adjusted to match the Fortran test calls
    std::vector<float> sub_z1(z.begin(), z.begin() + 10); // Extract first 10 elements
    std::vector<float> sub_z2(z.begin(), z.begin() + 42); // Extract first 42 elements

    try {
        bar.mysub(1, sub_z1);
        bar.mysub(2, sub_z2);
    } catch(const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}