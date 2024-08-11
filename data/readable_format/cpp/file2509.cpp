#include <iostream>
#include <cstdlib>

int main() {
    int j = 0;
    for (int i = 1; i <= 3; ++i) {
        if (i == 2) continue;
        j = j + 1;
    }
    if (j != 2) {
        std::exit(1);
    }
    return 0;
}