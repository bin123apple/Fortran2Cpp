#include <iostream>

void LGEMMX(int m, int n, int k, bool alpha, bool* a, int inc1a, int inc2a,
            bool* b, int inc1b, int inc2b, bool beta, bool* c, int inc1c, int inc2c) {
    for (int i = 0; i < m; ++i) {
        c[i] = a[i] && b[i];
    }
}

int main() {
    int m = 3;
    bool a[] = {false, true, true};
    bool b[] = {false, true, true};
    bool c[3];
    
    LGEMMX(m, 0, 0, true, a, 1, 1, b, 1, 1, false, c, 1, 1);

    std::cout << "C++ Stdout: ";
    for (int i = 0; i < m; ++i) {
        std::cout << (c[i] ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    return 0;
}