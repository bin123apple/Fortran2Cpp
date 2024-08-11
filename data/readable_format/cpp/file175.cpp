#include <iostream>
#include <cstdint>

extern "C" {
void sub(std::int32_t* xxx, std::int32_t* yyy) {
    std::int32_t* ptr1 = xxx;
    std::int32_t* ptr2 = xxx + 4;
    std::int32_t* ptr3 = yyy;
    std::int32_t* ptr4 = yyy + 4;

    // Corrected output statements
    std::cout << "Testing pointers..." << std::endl;
    std::cout << "ptr1 should equal ptr3: " << (ptr1 == ptr3 ? "true" : "false") << std::endl;
    std::cout << "ptr2 should be 4 integers ahead of ptr1: " << (ptr2 == xxx + 4 ? "true" : "false") << std::endl;
    std::cout << "ptr4 should be 4 integers ahead of ptr3: " << (ptr4 == yyy + 4 ? "true" : "false") << std::endl;
}
}

int main() {
    std::int32_t arr1[10] = {};
    std::int32_t arr2[10] = {};

    sub(arr1, arr2);

    return 0;
}