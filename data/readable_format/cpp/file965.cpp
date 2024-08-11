#include <vector>
#include <numeric> // For std::accumulate

// Define the struct T equivalent to the Fortran type T
struct T {
    std::vector<int> v; // Using vector to represent the allocatable array
};

class A {
public:
    static int n; // Equivalent to the INTEGER :: n in the module

    static void FOO() {
        T var; // Equivalent to TYPE(T) :: var
        int suma; // Equivalent to INTEGER :: suma

        // Resizing the vector to n elements. This is akin to ALLOCATE(var%v(n))
        var.v.resize(n);

        // Calculating the sum of elements in the vector.
        // This is equivalent to suma = sum(var%v(:))
        suma = std::accumulate(var.v.begin(), var.v.end(), 0);

        // In this example, 'suma' is calculated but not used further.
        // You might want to return it or use it for further computations.
    }
};

// Initialization of the static member 'n'
int A::n = 0;

int main() {
    // Example usage
    A::n = 5; // Equivalent to setting 'n' in the Fortran module
    A::FOO(); // Call the subroutine
    
    return 0;
}