#include <iostream>
#include <cassert>

// Function declaration
char chr_achr(int ascii) {
    const int DEL = 127;
    const int NUL = 0;

    if (ascii > NUL && ascii <= DEL) {
        return static_cast<char>(ascii);
    } else {
        return static_cast<char>(NUL);
    }
}

int main() {
    // Test cases
    struct TestCase {
        int input;
        char expected;
    };

    TestCase testCases[] = {
        {0, '\0'},    // NUL character
        {65, 'A'},    // 'A'
        {127, '\x7F'},// DEL character
        {128, '\0'},  // Outside valid range, expect NUL
        {-1, '\0'}    // Negative, outside valid range, expect NUL
    };

    for (const auto& testCase : testCases) {
        char result = chr_achr(testCase.input);
        std::cout << "Testing ASCII code " << testCase.input << ": ";
        assert(result == testCase.expected);
        std::cout << "Passed, got '" << result << "'" << std::endl;
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}