#include <iostream>
#include <thread>

void foo() {
    int x = 0, y = 2;

    // 1st Child Task
    std::thread t1([&x]() {
        x++;
    });
    t1.join();

    // 2nd child task
    int temp = y - x;
    y = temp;

    // 1st taskwait
    // No equivalent in C++ as OpenMP taskwait is not supported

    // Print x
    std::cout << "x = " << x << std::endl;

    // 2nd taskwait
    // No equivalent in C++ as OpenMP taskwait is not supported

    // Print y
    std::cout << "y = " << y << std::endl;
}

int main() {
    foo();
    return 0;
}
