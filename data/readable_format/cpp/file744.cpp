#include <iostream>
#include <vector>

namespace mytypes {
    int get_i() {
        return 13;
    }
}

// Simple test function to verify get_i returns the expected value
void test_get_i() {
    int expected = 13;
    int result = mytypes::get_i();
    if (result == expected) {
        std::cout << "Test get_i passed." << std::endl;
    } else {
        std::cout << "Test get_i failed. Expected " << expected << ", got " << result << std::endl;
    }
}

// Test function to verify the size of the vector created with get_i
void test_vector_size() {
    std::vector<int> x(mytypes::get_i());
    size_t expected = 13;
    if (x.size() == expected) {
        std::cout << "Test vector_size passed." << std::endl;
    } else {
        std::cout << "Test vector_size failed. Expected " << expected << ", got " << x.size() << std::endl;
    }
}

int main() {
    // Run the tests
    test_get_i();
    test_vector_size();

    return 0;
}