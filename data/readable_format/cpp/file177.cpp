#include <iostream>
#include <vector>

int main() {
    // Part equivalent to real, allocatable :: vla1 (:)
    std::vector<float> vla1;
    
    // Allocate vla1 with size 5
    vla1.resize(5);
    
    // Check if vla1 is allocated (in C++, this is somewhat redundant as std::vector manages its own memory)
    bool l = !vla1.empty();
    
    // Initialize vla1
    std::fill(vla1.begin(), vla1.end(), 1.0f);
    vla1[1] = 42.0f; // Fortran arrays are 1-based, C++ arrays are 0-based
    vla1[3] = 24.0f;
    
    // Deallocate vla1
    vla1.clear(); // or vla1.resize(0);
    l = !vla1.empty();
    
    // Part equivalent to real, target, allocatable :: vla2(:, :)
    std::vector<std::vector<float>> vla2;
    
    // Allocate vla2 with size 5x2
    vla2.resize(5, std::vector<float>(2, 2.0f));
    
    // Part equivalent to real, pointer :: pvla2 (:, :)
    float* pvla2 = nullptr; // Initialize to nullptr to mimic nullify(pvla2)
    
    // Simulate pvla2 => vla2
    // This assumes the 2D vector is stored contiguously, which is true for this allocation but not a general guarantee for std::vector of std::vector.
    pvla2 = &vla2[0][0];
    l = (pvla2 != nullptr);
    
    // Modify an element through pvla2
    pvla2[2 * 2 + 0] = 42.0f; // Equivalent to pvla2(2, 1) = 42 in Fortran, considering row-major order and 0-based indexing
    
    // Simulate pvla2 => null()
    pvla2 = nullptr;
    l = (pvla2 != nullptr);
    
    return 0;
}