#include <iostream>
#include <vector>
#include <stdexcept> // For std::runtime_error

void test(int order, int repeat, int trail, const std::vector<int>& values);
void build(int order) {
    // This function is kept for completeness but not used in the test.
}
void run_tests();
void test_case(int order, int repeat, int trail, const std::vector<int>& values, int& errors);

int main() {
    try {
        build(42); // Assuming you want to run the original functionality as well
        run_tests(); // Run unit tests to verify functionality
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

void test(int order, int repeat, int trail, const std::vector<int>& values) {
    if (values.size() != static_cast<size_t>(order * repeat + trail)) {
        throw std::runtime_error("Size mismatch");
    }
    for (int i = 0; i < order * repeat; ++i) {
        if (values[i] != (i % repeat) + 1) {
            throw std::runtime_error("Value mismatch in the main sequence");
        }
    }
    for (int i = 0; i < trail; ++i) {
        if (values[i + order * repeat] != (i + 1) * 100) {
            throw std::runtime_error("Value mismatch in the trailing sequence");
        }
    }
}

void run_tests() {
    int errors = 0;

    // Example test case
    test_case(1, 8, 0, {1, 2, 3, 4, 5, 6, 7, 8}, errors);

    // Add more test cases similar to the first one as needed...

    if (errors == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << errors << " tests failed." << std::endl;
    }
}

void test_case(int order, int repeat, int trail, const std::vector<int>& values, int& errors) {
    try {
        test(order, repeat, trail, values);
    } catch (const std::runtime_error& e) {
        errors++;
        std::cerr << "Test case failed for order=" << order << ", repeat=" << repeat << ", trail=" << trail << ". Error: " << e.what() << std::endl;
    }
}