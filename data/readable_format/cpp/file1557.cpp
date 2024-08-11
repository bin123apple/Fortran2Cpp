#include <iostream>
#include <array>
#include <algorithm>
#include <cstring>
#include <cstdlib>

void foo(std::array<std::string, 4>& chr1, std::array<std::string, 4>& chr2) {
    chr2 = chr1;
}

int main() {
    std::array<std::string, 4> c1, c2;
    int m = 4;

    // Mimic Fortran array constructor with explicit values
    std::fill(c2.begin(), c2.end(), "abcd");
    foo(c2, c2);
    if (std::any_of(c2.begin(), c2.end(), [](const std::string& s){ return s != "abcd"; })) {
        std::abort();
    }

    c1 = {"abcd", "efgh", "ijkl", "mnop"};
    foo(c1, c1);

    std::reverse_copy(c1.begin(), c1.end(), c2.begin());
    foo(c2, c2);
    if (!std::equal(c2.rbegin(), c2.rend(), c1.begin())) {
        std::abort();
    }

    for (int i = 0; i < 4; ++i) {
        c2[i] = c1[i].substr(i/2, 2) + "  ";
    }
    foo(c2, c2);
    if (c2 != std::array<std::string, 4>{"ab  ", "fg  ", "jk  ", "op  "}) {
        std::abort();
    }

    for (int i = 0; i < 4; ++i) {
        c1[i] = std::string(1, char(65 + i)) + std::string(1, char(69 + i)) +
                std::string(1, char(73 + i)) + std::string(1, char(77 + i));
    }
    foo(c1, c1);
    if (c1 != std::array<std::string, 4>{"AEIM", "BFJN", "CGKO", "DHLP"}) {
        std::abort();
    }

    return 0;
}