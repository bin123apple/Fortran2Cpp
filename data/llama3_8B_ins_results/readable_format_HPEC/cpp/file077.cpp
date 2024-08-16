#include <iostream>
#include <thread>
#include <chrono>

int main() {
    int i = 0;

    std::thread t1([&i]() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        i = 3;
    });

    std::thread t2([&i]() {
        i = 2;
    });

    t1.join();
    t2.join();

    if (i!= 2) {
        std::cout << i << std::endl;
    }

    return 0;
}
