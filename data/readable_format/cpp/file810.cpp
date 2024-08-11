#include <iostream>
#include <vector>
#include <cassert>

// Declaration of foo1 function
std::vector<int> foo1() {
    std::vector<int> output;
    for(int k = 1; k <= 2; ++k) {
        for(int i = 3; i <= 4; ++i) {
            output.push_back(i + k);
        }
    }
    return output;
}

// A simple test function for foo1
void testFoo1() {
    std::vector<int> expected{4, 5, 5, 6};
    std::vector<int> result = foo1();
    
    // Simple assertion to check if the result matches the expected output
    assert(result.size() == expected.size() && "Result vector size does not match expected size.");
    for(size_t i = 0; i < expected.size(); ++i) {
        assert(result[i] == expected[i] && "Value mismatch between result and expected vectors.");
    }
    
    std::cout << "All tests passed." << std::endl;
}

int main() {
    // Running the test
    testFoo1();
    return 0;
}