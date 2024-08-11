#include <iostream>
#include <cstdint>
#include <type_traits>

// Mimicking Fortran's selected_int_kind with template specialization
template<int P>
struct selected_int_kind {};

template<>
struct selected_int_kind<8> {
    using type = int32_t;
};

template<>
struct selected_int_kind<10> {
    using type = int64_t;
};

int main() {
    using s4 = selected_int_kind<8>::type; // Mimics integer(kind=s4)
    using s8 = selected_int_kind<10>::type; // Mimics integer(kind=s8)
    using k4 = int32_t; // Closest C++ equivalent to kind(1)
    using k8 = int64_t; // Closest C++ equivalent to kind(1_8)
    using r8 = double; // Closest C++ equivalent to kind(1.0D0)
    
    s4 i_s4[2];
    s8 i_s8[2];
    k4 i_k4[2];
    k8 i_k8[2];
    r8 i_r8[2];

    // Type checks (mimicking the kind checks in Fortran)
    if (!std::is_same<decltype(i_s4[0]), int32_t>::value) {
        std::cout << "invalid s4" << std::endl;
    }
    if (!std::is_same<decltype(i_s8[0]), int64_t>::value) {
        std::cout << "invalid s8" << std::endl;
    }
    if (!std::is_same<decltype(i_k4[0]), int32_t>::value) {
        std::cout << "invalid k4" << std::endl;
    }
    if (!std::is_same<decltype(i_k8[0]), int64_t>::value) {
        std::cout << "invalid k8" << std::endl;
    }
    if (!std::is_same<decltype(i_r8[0]), double>::value) {
        std::cout << "invalid r8" << std::endl;
    }

    return 0;
}