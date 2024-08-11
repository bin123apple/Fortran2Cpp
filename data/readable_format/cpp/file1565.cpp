#include <iostream>
#include <cmath>
#include <cassert>

class proc_component_example {
public:
    class t {
    public:
        float a;
        void (*proc)(const t&, int);
    };

    static int calls;

    static void print_me(const t& arg, int lun) {
        std::cout << arg.a << std::endl;
        calls++;
    }

    static void print_my_square(const t& arg, int lun) {
        std::cout << std::pow(arg.a, 2) << std::endl;
        calls++;
    }
};

int proc_component_example::calls = 0;

// Test functions
void test_print_me() {
    proc_component_example::t x;
    x.a = 2.71828f;
    x.proc = proc_component_example::print_me;
    x.proc(x, 1); // Passing 1 as a dummy value for lun
    assert(proc_component_example::calls == 1);
    std::cout << "test_print_me passed." << std::endl;
}

void test_print_my_square() {
    proc_component_example::t x;
    proc_component_example::calls = 0; // Reset call count
    x.a = 2.71828f;
    x.proc = proc_component_example::print_my_square;
    x.proc(x, 1); // Passing 1 as a dummy value for lun
    assert(proc_component_example::calls == 1);
    std::cout << "test_print_my_square passed." << std::endl;
}

int main() {
    test_print_me();
    test_print_my_square();

    std::cout << "All tests passed." << std::endl;
    return 0;
}