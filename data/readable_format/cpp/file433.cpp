#include <iostream>
#include <string>

// Function to check the value of 'a' and return a corresponding message
std::string checkValue(int a) {
    if (a == 10) {
        a = a + 1; // This line modifies 'a', but since we don't use 'a' afterwards, it has no effect on the output.
        return "a incremented";
    } else if (a == 20) {
        return "Value of a is 20";
    } else if (a == 30) {
        return "Value of a is 30";
    } else {
        return "None of the values is matching";
    }
}

// Manual test function
void runTests() {
    std::cout << "Running tests..." << std::endl;

    // Test 1: a == 10 (expected to increment a, but since it's a local copy, it won't affect the test directly)
    std::cout << "Test 1: ";
    if (checkValue(10) == "a incremented") {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    // Test 2: a == 20
    std::cout << "Test 2: ";
    if (checkValue(20) == "Value of a is 20") {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    // Test 3: a == 30
    std::cout << "Test 3: ";
    if (checkValue(30) == "Value of a is 30") {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    // Test 4: a != 10, 20, 30
    std::cout << "Test 4: ";
    if (checkValue(100) == "None of the values is matching") {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }
}

int main() {
    // You can call your function here if you want to
    // For example, checkValue(100) and print its return value
    std::cout << "The checkValue function called with 'a' as 100: " << checkValue(100) << std::endl;

    // Run tests
    runTests();

    return 0;
}