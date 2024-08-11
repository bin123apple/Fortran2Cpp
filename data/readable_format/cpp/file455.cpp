#include <iostream>
#include <vector>

// Equivalent to the Fortran type (container_t)
struct Container {
    int entry = -1;
};

// Custom 'pack' function to mimic Fortran's pack behavior
std::vector<Container> pack(const std::vector<Container>& a, const std::vector<bool>& mask) {
    std::vector<Container> result;
    for (size_t i = 0; i < a.size(); ++i) {
        if (mask[i]) {
            result.push_back(a[i]);
        }
    }
    return result;
}

int main() {
    // Equivalent to the Fortran arrays a1 and a2, but using vectors
    std::vector<Container> a1(1), a2(1); // Initialize with size 1

    a2[0].entry = 1; // Equivalent to a2(1)%entry = 1

    // The mask is always true in your example, so we create a vector of true values
    std::vector<bool> mask(a2.size(), true);

    // Using the pack function to filter a2 and assign it to a1
    a1 = pack(a2, mask);

    // Equivalent to the Fortran STOP statement, but using return in C++
    if (a1[0].entry != 1) {
        return 1;
    }

    return 0; // Success
}