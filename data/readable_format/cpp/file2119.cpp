#include <iostream>
#include <array>
#include <cstdlib>

void fun_task(int& x, std::array<int, 10>& y) {
    x = x + 1;
    y[0] = y[0] + 1;
}

void fun_task_2(const int& x, const std::array<int, 10>& y) {
    if (x != 42) {
        std::cerr << "Error: x is not 42" << std::endl;
        std::exit(1);
    }

    if (y[0] != 10042) {
        std::cerr << "Error: y[0] is not 10042" << std::endl;
        std::exit(2);
    }
}

int main() {
    int i = 41;
    std::array<int, 10> j = {10041, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    fun_task(i, j);
    fun_task_2(i, j);

    return 0;
}