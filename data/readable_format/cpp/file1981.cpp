#include <iostream>
#include <string>
#include <cstdlib>

void perform_test(const std::string& str, bool expected) {
    bool result = (str.size() == 44 && str == "Print rather a lot of ampersands &&&&&&&&&&&");
    std::cout << "Test passed: " << std::boolalpha << (result == expected) << std::endl;
}

int main() {
    // Test case 1: Expected to pass
    std::string str = "Print rather a lot of ampersands &&&&&"
                      "&&&&&"
                      "&&&&&";
    perform_test(str, true);

    // Test case 2: Expected to fail (intentionally showing the expected behavior)
    str = "This string is definitely not the right length.";
    perform_test(str, false);

    return 0;
}