#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr

struct t1 {
    int c1;
    t1(int val) : c1(val) {} // Constructor to initialize c1
};

struct t2 {
    std::unique_ptr<t1> c2; // Use unique_ptr for automatic memory management
    t2(t1* ptr) : c2(ptr) {} // Constructor to initialize c2

    // Explicitly define the move constructor because of the unique_ptr member
    t2(t2&& other) noexcept : c2(std::move(other.c2)) {}
    // Delete the copy constructor to prevent copying
    t2(const t2&) = delete;
    // Define the assignment operator as deleted to prevent copying
    t2& operator=(const t2&) = delete;
};

void assert_condition(bool condition, const char* message) {
    if (!condition) {
        std::cerr << message << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void test_initialization_and_modification() {
    std::vector<t2> v; // Create an empty vector
    // Manually fill the vector
    for (int i = 0; i < 4; ++i) {
        v.push_back(t2(new t1(3)));
    }

    v[1].c2->c1 = 7;
    v[2].c2->c1 = 11;
    v[3].c2->c1 = 13;

    assert_condition(v[0].c2->c1 == 3, "Test failed for v[0].c2->c1 == 3");
    assert_condition(v[1].c2->c1 == 7, "Test failed for v[1].c2->c1 == 7");
    assert_condition(v[2].c2->c1 == 11, "Test failed for v[2].c2->c1 == 11");
    assert_condition(v[3].c2->c1 == 13, "Test failed for v[3].c2->c1 == 13");
}

int main() {
    test_initialization_and_modification();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}