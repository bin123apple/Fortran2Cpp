#include <iostream>
#include <cstdlib> // For std::abort()

extern "C" {

struct my_c_type_0 {
    int i;
    void* nested_c_address;
    int array[3];
};

struct my_c_type_1 {
    my_c_type_0 my_nested_type;
    void* c_address;
    int j;
};

void check_values(my_c_type_1& my_type, int expected_i, void* expected_nested_c_address,
                  int expected_array_1, int expected_array_2, int expected_array_3,
                  void* expected_c_address, int expected_j) {
    if (my_type.my_nested_type.i != expected_i) std::abort();
    if (my_type.my_nested_type.array[0] != expected_array_1) std::abort();
    if (my_type.my_nested_type.array[1] != expected_array_2) std::abort();
    if (my_type.my_nested_type.array[2] != expected_array_3) std::abort();
    if (my_type.j != expected_j) std::abort();

    std::cout << "C++ test passed successfully." << std::endl;
}

} // extern "C"

int main() {
    my_c_type_1 test_instance{};
    int expected_values[3] = {1, 2, 3};

    test_instance.my_nested_type.i = 1;
    test_instance.my_nested_type.nested_c_address = nullptr;
    std::copy(std::begin(expected_values), std::end(expected_values), std::begin(test_instance.my_nested_type.array));
    test_instance.c_address = nullptr;
    test_instance.j = 4;

    check_values(test_instance, 1, nullptr, 1, 2, 3, nullptr, 4);

    return 0;
}