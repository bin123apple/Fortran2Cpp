#include <string>
#include <vector>

class Foo {
public:
    // Constructor to replace the subroutine
    Foo(int n) {
        // In C++, we need to explicitly allocate the string/array
        // to mimic the behavior of using "character(len=id(n)) :: a" in Fortran
        // Here, std::string is used to represent a character array.
        a = std::string(id(n), ' '); // Initialize a string of length id(n) with spaces
    }

    // Pure function id (equivalent to Fortran's pure function)
    // Marked as const to indicate it doesn't modify any class member
    int id(int a) const {
        return a; // This function just returns its input, same as the Fortran version
    }

private:
    std::string a; // Using string to represent character array
};

int main() {
    int n = 5;
    Foo foo(n); // Equivalent to calling subroutine foo with argument n

    return 0;
}