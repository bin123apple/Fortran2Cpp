#include <iostream>
#include <array>

int main() {
    std::array<std::array<std::array<int, 3>, 3>, 3> a = {{
        {{
            {{1, 2, 3}},
            {{4, 5, 6}},
            {{7, 8, 9}}
        }},
        {{
            {{10, 11, 12}},
            {{13, 14, 15}},
            {{16, 17, 18}}
        }},
        {{
            {{19, 20, 21}},
            {{22, 23, 24}},
            {{25, 26, 27}}
        }}
    }};

    // Adjusting to match Fortran's column-major order access pattern
    for (int k = 0; k < 3; ++k) { // Third dimension
        for (int j = 0; j < 3; ++j) { // Second dimension
            for (int i = 0; i < 3; ++i) { // First dimension
                std::cout << "a(" << i+1 << "," << j+1 << "," << k+1 << ") = " << a[k][j][i] << std::endl;
            }
        }
    }
    
    return 0;
}