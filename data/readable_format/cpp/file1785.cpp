#include <array>

void foo(std::array<int, 4>& a) {
    for (int& element : a) {
        if (element != 0) {
            element = 1;
        }
    }
}