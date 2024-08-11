#include <iostream>
#include <vector>

extern "C" {
    void sub0(int32_t* assumed_array, size_t size);
    void sub1(int32_t* deferred_array);
}

// Definitions of sub0 and sub1 for demonstration
extern "C" void sub0(int32_t* assumed_array, size_t size) {
    std::cout << "sub0: ";
    for (size_t i = 0; i < size; ++i) {
        std::cout << assumed_array[i] << " ";
    }
    std::cout << std::endl; // Ensure correct C++ syntax
}

extern "C" void sub1(int32_t* deferred_array) {
    // Assuming the caller communicates the size some other way
    // For demonstration, just printing the first three elements
    std::cout << "sub1: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << deferred_array[i] << " ";
    }
    std::cout << std::endl; // Ensure correct C++ syntax
}

int main() {
    // Test for sub0: Assuming size is known
    std::vector<int32_t> assumed_array = {1, 2, 3, 4, 5};
    sub0(assumed_array.data(), assumed_array.size());

    // Test for sub1: Deferred size array
    int32_t deferred_array[] = {10, 20, 30};
    sub1(deferred_array);

    return 0;
}