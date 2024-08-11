#include <iostream>
#include <vector>
#include <functional>
#include <string>

// A simple testing framework setup
class SimpleTestFramework {
public:
    using TestFunc = std::function<void()>;

    static void registerTest(const std::string& testName, TestFunc testFunc) {
        getTests().push_back({testName, testFunc});
    }

    static void runAllTests() {
        for (auto& test : getTests()) {
            std::cout << "Running test: " << test.first << std::endl;
            test.second();
        }
    }

private:
    static std::vector<std::pair<std::string, TestFunc>>& getTests() {
        static std::vector<std::pair<std::string, TestFunc>> tests;
        return tests;
    }
};

// Test registration macro
#define REGISTER_TEST(testName, testFunc) SimpleTestFramework::registerTest(testName, testFunc)

// Test functions
void test_dummyABFail() {
    std::cout << "Dummy test A B Fail" << std::endl;
    // Test implementation
}

void test_dummyABPass() {
    std::cout << "Dummy test A B Pass" << std::endl;
    // Test implementation
}

int main() {
    // Register tests
    REGISTER_TEST("test_dummyABFail", test_dummyABFail);
    REGISTER_TEST("test_dummyABPass", test_dummyABPass);

    // Run all registered tests
    SimpleTestFramework::runAllTests();

    return 0;
}