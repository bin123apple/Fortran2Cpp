#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstdlib> // For abort()

struct dt {
    std::string* scalar = nullptr;
    std::vector<std::string> array;
};

int main() {
    dt a;
    std::string scalar_t = "abcd";
    std::array<std::string, 2> array_t = {"abcd", "efgh"};

    // Allocate and assign
    a.scalar = new std::string(scalar_t);
    if (*a.scalar != "abcd") std::abort();
    a.array = std::vector<std::string>(array_t.begin(), array_t.end());
    if (a.array[0] != "abcd" || a.array[1] != "efgh") std::abort();
    delete a.scalar;

    // Direct pointer assignment
    a.scalar = &scalar_t;
    if (*a.scalar != "abcd") std::abort();
    // For array, we simply use the reference to the std::array, though this is not a direct Fortran equivalent
    // as C++ doesn't support direct array pointer assignments in the same way.
    // However, for educational purposes, we demonstrate a workaround using vectors.
    std::vector<std::string*> array_ptrs;
    for(auto& elem: array_t) {
        array_ptrs.push_back(&elem);
    }
    if (*array_ptrs[0] != "abcd" || *array_ptrs[1] != "efgh") std::abort();

    // No need to explicitly deallocate the scalar pointer here as it points to a stack-allocated string.
    return 0;
}