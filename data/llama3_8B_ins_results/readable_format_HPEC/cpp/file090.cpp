#include <iostream>
#include <thread>
#include <mutex>

int main() {
    int a = 0, b = 0, c = 0, d = 0;

    std::mutex mtx;

    // Task T1
    std::thread t1([&c]() { c = 1; });

    // Task T2
    std::thread t2([&a]() { a = 2; });

    // Task T3
    std::thread t3([&b]() { b = 3; });

    // Wait for tasks T1-T3 to complete
    t1.join();
    t2.join();
    t3.join();

    // Task T4
    std::thread t4([&a, &c, &mtx]() {
        std::lock_guard<std::mutex> lock(mtx);
        c += a;
    });

    // Task T5
    std::thread t5([&b, &c, &mtx]() {
        std::lock_guard<std::mutex> lock(mtx);
        c += b;
    });

    // Wait for tasks T4-T5 to complete
    t4.join();
    t5.join();

    // Task T6
    std::thread t6([&c]() { d = c; });

    // Wait for task T6 to complete
    t6.join();

    std::cout << d << std::endl;

    return 0;
}
