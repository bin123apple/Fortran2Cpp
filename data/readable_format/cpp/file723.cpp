#include <iostream>
#include <memory> // for std::unique_ptr
#include <algorithm> // for std::copy
#include <numeric> // for std::iota
#include <vector>

class PsbBaseSparseMat {
public:
    std::vector<int> irp;

    // Constructor for dynamic allocation
    PsbBaseSparseMat(int size = 0) : irp(size) {}

    // Copy constructor
    PsbBaseSparseMat(const PsbBaseSparseMat& other) : irp(other.irp) {}
    
    // Assignment operator
    PsbBaseSparseMat& operator=(const PsbBaseSparseMat& other) {
        if (this != &other) { // self-assignment check
            this->irp = other.irp;
        }
        return *this;
    }
};

int main() {
    PsbBaseSparseMat acsr(4);
    // Initializing array elements
    acsr.irp = {1, 3, 4, 5};

    // Demonstrating use of the array
    for (int i : acsr.irp) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    // Dynamic allocation using smart pointers for automatic memory management
    std::unique_ptr<PsbBaseSparseMat> a(new PsbBaseSparseMat(acsr));

    for (int i : a->irp) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    // Moving irp from acsr to a (demonstrated by copying and then clearing acsr.irp for simplicity)
    a->irp = std::move(acsr.irp);
    acsr.irp.clear(); // Not strictly necessary but shows the intent to move

    for (int i : a->irp) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    // Check if the array a->irp is exactly as expected
    std::vector<int> expectedValues = {1, 3, 4, 5};
    if (!std::equal(a->irp.begin(), a->irp.end(), expectedValues.begin())) {
        std::cerr << "Error: Unexpected array values." << std::endl;
        return 1; // Equivalent to STOP 1 in Fortran
    }

    return 0;
}