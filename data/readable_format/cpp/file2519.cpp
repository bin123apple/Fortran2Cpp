#include <iostream>

int main() {
    int i = 1;
    if (i > 0) {
        i = 2;
    } else if (i > 10) {
        i = 3;
    } else {
        i = 4;
    }
    return 0;
}