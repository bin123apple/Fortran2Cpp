#include <array>
#include <string>

int main() {
    std::array<std::string, 2> arr = { "abc", "foobar" };
    // Since the assignment in the original Fortran code is redundant (reassigns the same values),
    // it's not replicated in the C++ translation.
    return 0;
}