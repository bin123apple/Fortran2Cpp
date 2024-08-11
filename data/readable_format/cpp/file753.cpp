#include <cstdint>
#include <cstdlib>
#include <iostream>

extern "C" { // Ensure C linkage for compatibility

struct my_c_type_0 {
    int32_t i; // Equivalent to Fortran's integer(c_int)
    void* nested_c_address; // Equivalent to Fortran's type(c_ptr)
    int32_t array[3]; // Fixed-size array of 3 integers
};

struct my_c_type_1 {
    my_c_type_0 my_nested_type;
    void* c_address; // Equivalent to Fortran's type(c_ptr)
    int32_t j; // Equivalent to Fortran's integer(c_int)
};

// The subroutine is translated as a function with C linkage
void sub0(my_c_type_1 my_type, int32_t expected_i, void* expected_nested_c_address,
          int32_t expected_array_1, int32_t expected_array_2, int32_t expected_array_3,
          void* expected_c_address, int32_t expected_j) {
    if (my_type.my_nested_type.i != expected_i) {
        std::abort();
    }

    if (my_type.my_nested_type.nested_c_address != expected_nested_c_address) {
        std::abort();
    }

    if (my_type.my_nested_type.array[0] != expected_array_1) {
        std::abort();
    }

    if (my_type.my_nested_type.array[1] != expected_array_2) {
        std::abort();
    }

    if (my_type.my_nested_type.array[2] != expected_array_3) {
        std::abort();
    }

    if (my_type.c_address != expected_c_address) {
        std::abort();
    }

    if (my_type.j != expected_j) {
        std::abort();
    }
}

} // end extern "C"

void test_sub0() {
    my_c_type_1 test_type;
    void* dummy_c_ptr = static_cast<void*>(&test_type);

    // Initialize the test data
    test_type.my_nested_type.i = 42;
    test_type.my_nested_type.nested_c_address = dummy_c_ptr;
    test_type.my_nested_type.array[0] = 1;
    test_type.my_nested_type.array[1] = 2;
    test_type.my_nested_type.array[2] = 3;
    test_type.c_address = dummy_c_ptr;
    test_type.j = 99;

    // Call the subroutine with the expected values
    sub0(test_type, 42, dummy_c_ptr, 1, 2, 3, dummy_c_ptr, 99);

    std::cout << "C++ Test Passed" << std::endl;
}

int main() {
    test_sub0();
    return 0;
}