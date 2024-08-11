#include <iostream>
#include <stdexcept>

struct t {
    int x;
};

class SimpleIncrementer {
public:
    static void increment(t& x) {
        for (int i = 1; i <= 1000; ++i) {
            x.x += 1;
        }
    }
};

// Simple unit test mechanism
class SimpleUnitTest {
public:
    static void runTest() {
        t testData;
        testData.x = 0;
        SimpleIncrementer::increment(testData);
        if (testData.x != 1000) {
            std::cerr << "Test failed: Expected 1000, got " << testData.x << std::endl;
            throw std::runtime_error("Test failed.");
        }
        std::cout << "Test passed: Value is " << testData.x << std::endl;
    }
};

int main() {
    try {
        SimpleUnitTest::runTest();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred during unit tests: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}