#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Assuming the substring operation is encapsulated in this function
void performSubstringOperation(std::vector<std::string>& strings, std::vector<std::string>& substrings) {
    for (int i = 0; i < 2; ++i) {
        substrings[i] = strings[i].substr(1, 5); // Take 5 characters starting from index 1
    }
}

// A simple test function to verify our operation
void testPerformSubstringOperation() {
    std::vector<std::string> strings = {"abcdefghij", "klmnopqrst"};
    std::vector<std::string> substrings(10, std::string(5, ' ')); // 10 strings of length 5

    performSubstringOperation(strings, substrings);

    // Using assert to validate our expectations
    assert(substrings[0] == "bcdef" && "Substring operation failed for element 0.");
    assert(substrings[1] == "lmnop" && "Substring operation failed for element 1.");

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    // You can call your main program logic here

    // Running tests
    testPerformSubstringOperation();

    return 0;
}