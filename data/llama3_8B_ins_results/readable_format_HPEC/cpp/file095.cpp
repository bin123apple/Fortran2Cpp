#include <iostream>
#include <thread>

void foo() {
    int x = 0, y = 2;

    // 1st child task
    std::thread t1([&x]() {
        x++;
    });
    t1.join();

    // 2nd child task
    std::thread t2([&y]() {
        y--;
    });
    t2.join();

    // 1st taskwait
    if (false) {
        // do nothing
    }

    std::cout << "x=" << x << std::endl;

    // 2nd taskwait
    // do nothing

    std::cout << "y=" << y << std::endl;
}

int main() {
    foo();
    return 0;
}
