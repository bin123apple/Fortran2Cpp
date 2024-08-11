#include <iostream>
#include <array>

int main() {
    std::array<int, 5> a = {1, 2, 3, 4, 5};

    for (auto& value : a) {
        if (value == 2) {
            // Operations for values equal to 2 would go here
        } else {
            // Operations for values not equal to 2 would go here (elsewhere equivalent)
        }
    }

    return 0;
}