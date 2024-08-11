#include <iostream>
#include <cstdlib>

// Forward declarations for the functions
void sub(int y);
void sub2(void* arg);
void abortIfNotEqual(int lhs, int rhs);

// Global variable
int sum = 0;

// Base type t
struct t {
    int i = 0;
    void (*ppc)(int) = nullptr;
    void (*proc)(void*) = nullptr;
};

// Extended type t2
struct t2 : public t {
    void (*proc2)(int) = nullptr;
};

void sub(int y) {
    sum += y;
}

void sub2(void* arg) {
    t* obj = static_cast<t*>(arg);
    obj->i += sum;
}

void abortIfNotEqual(int lhs, int rhs) {
    if (lhs != rhs) {
        std::cerr << "Assertion failed";
        std::exit(1);
    }
}

void test() {
    t test_x;
    t2 test_x2;

    // Reset global sum for testing
    sum = 0;

    // Test setting and calling procedure pointers
    test_x.i = 10;
    test_x.ppc = sub;
    test_x.ppc(5);
    abortIfNotEqual(sum, 5);

    // Test type extension and additional procedure pointer
    test_x2.proc2 = sub;
    test_x2.proc2(5);
    abortIfNotEqual(sum, 10);

    // Test procedure that modifies the object state
    test_x.proc = reinterpret_cast<void (*)(void*)>(sub2);
    test_x.proc(static_cast<void*>(&test_x));
    abortIfNotEqual(test_x.i, 20); // sum was 10 before the call, and i was 10

    std::cout << "All C++ tests passed." << std::endl;
}

int main() {
    test();
    return 0;
}