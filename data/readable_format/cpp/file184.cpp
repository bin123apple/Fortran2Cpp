#include <iostream>
#include <vector>
#include <cmath>

// Equivalent to the Fortran module 'foo'
namespace foo {
    // Equivalent to the Fortran subroutine 'bar'
    void bar(const std::vector<std::vector<float>>& a, float& x) {
        x = 0;
        for(size_t j = 0; j < a[0].size(); ++j) {
            for(size_t i = 0; i < a.size(); ++i) {
                x += std::pow(a[i][j], 2);
            }
        }
    }
}

int main() {
    // Declaring and initializing the 2D vector 'a' equivalent to the Fortran array
    std::vector<std::vector<float>> a = {
        {1.0, 2.0, 3.0},
        {-1.0, -2.0, -3.0}
    };
    
    float x = 0;
    
    // Simulating the heavy computational task
    for(int i = 0; i < 2000000; ++i) {
        foo::bar(a, x);
    }
    
    std::cout << x << std::endl;
    
    return 0;
}