// annelid_test_complete.cpp
#include <iostream>
#include <cassert>

extern "C" int annelid_test() {
    return 42;
}

int main() {
    int result = annelid_test();
    assert(result == 42); // This will terminate the program if the assertion fails.
    std::cout << "Test passed: annelid_test() returned 42." << std::endl;
    return 0;
}