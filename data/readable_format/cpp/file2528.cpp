#include <iostream>
#include <vector>

// Declare your functions
void foo();
void bar();

int main() {
    bar(); // Calling bar which in turn calls foo
    return 0;
}

// Define your functions after the main function or in any order you prefer

void foo() {
    // Initialize the array `a` with 3 elements all set to 1
    std::vector<int> a(3, 1);

    // Matrix multiplication (1*reshape(a,(/3,1/))) * reshape((/1,1,1/),(/1,3/))
    std::vector<std::vector<int>> mat_a(3, std::vector<int>(1, 1));
    std::vector<std::vector<int>> mat_b(1, std::vector<int>(3, 1));

    // Resultant matrix after multiplication
    std::vector<std::vector<int>> result(3, std::vector<int>(3, 0));
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = mat_a[i][0] * mat_b[0][j];
        }
    }

    // Print the result
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void bar() {
    foo();
}