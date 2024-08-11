#include <vector>
#include <array>

int main() {
    // Translating n1 and n2 to C++ - fixed-size arrays
    std::array<int, 10> n1;
    int n2[10];

    // Translating n3 and n4 to C++ - multi-dimensional fixed-size arrays
    // Using std::array for n3 equivalent
    std::array<std::array<std::array<int, 20>, 15>, 5> n3;
    // Traditional C++ multi-dimensional array for n4 equivalent
    int n4[5][15][20];

    // n5 and n6 are more complex due to custom bounds. In C++, you would typically manage this
    // manually, or use a data structure like std::vector with some arithmetic to handle indices.
    // Translating n5 and n6 using std::vector and manual index management for simplicity.

    // For n5 and n6, the size in each dimension needs to account for both negative and positive indices,
    // plus the zero index. So, the size calculation is (upper_bound - lower_bound + 1).

    // n5 and n6 equivalent with manual index translation.
    std::vector<std::vector<std::vector<int>>> n5(
        11, std::vector<std::vector<int>>(
            31, std::vector<int>(41, 0))); // Sizes: (5-(-5)+1), (15-(-15)+1), (20-(-20)+1)

    // Accessing an element from n5 or n6 in C++ requires calculating the index based on the Fortran bounds.
    // For example, to access n5(-5, -15, -20) in C++, you'd access n5[0][0][0].
    // To access n5(0,0,0), you'd access n5[5][15][20].

    return 0;
}