#include <iostream>
#include <type_traits>

// Equivalent to 'type :: t1'
struct t1 {
    int i;
};

// Equivalent to 'type :: ts'
struct ts {
    int j;
};

// Helper template for a 'SAME_TYPE_AS' equivalent
template<typename T, typename U>
constexpr bool same_type_as = std::is_same<T, U>::value;

// Helper template for a 'EXTENDS_TYPE_OF' equivalent (demonstrative purposes)
template<typename T, typename U>
constexpr bool extends_type_of = std::is_base_of<U, T>::value;

int main() {
    t1 x1;
    ts x2;
    int i;
    
    // Using 'same_type_as' to mimic 'SAME_TYPE_AS'
    std::cout << std::boolalpha << same_type_as<decltype(i), decltype(x1)> << std::endl;  // false
    std::cout << same_type_as<decltype(x1), decltype(x2)> << std::endl;  // false

    // Using 'extends_type_of' to mimic 'EXTENDS_TYPE_OF' (for demonstration)
    std::cout << extends_type_of<decltype(i), decltype(x1)> << std::endl;  // false
    std::cout << extends_type_of<decltype(x1), decltype(x2)> << std::endl;  // false

    return 0;
}