#include <array>

struct T {
    std::array<int, 2> A{{1, 2}}; // Using std::array for fixed-size array, initialized with 1 and 2
};

struct S {
    int B{1}; // Directly initializing B with 1
};