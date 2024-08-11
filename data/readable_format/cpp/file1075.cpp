#include <iostream>
#include <array>

int main() {
    std::array<std::array<bool, 2>, 2> l1 = {{{false, true}, {true, false}}};
    std::array<std::array<int, 2>, 2> it = {{{1, 2}, {3, 4}}};

    // Replace the Fortran forall construct with nested for loops
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (l1[i][j]) {
                it[i][j] = 0;
            }
        }
    }

    // Check if 'it' matches the specific pattern
    std::array<std::array<int, 2>, 2> target = {{{1, 0}, {0, 4}}};
    bool match = true;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (it[i][j] != target[i][j]) {
                match = false;
                break;
            }
        }
        if (!match) break;
    }

    if (!match) {
        std::cerr << "Mismatch detected, stopping program." << std::endl;
        return 1;
    }

    return 0;
}