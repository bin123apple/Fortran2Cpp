#include <iostream>
#include <atomic>
#include <thread>

int main() {
    int x = 0;
    int y = 0;
    int thrd = 0;
    int tmp = 0;

    std::atomic<int> x_atomic(x);
    std::atomic<int> y_atomic(0);

    std::thread t1([&]() {
        thrd = 0;
        if (thrd == 0) {
            std::lock_guard<std::mutex> lock;
            x_atomic = 10;

            y_atomic.store(1, std::memory_order_relaxed);
        } else {
            while (tmp == 0) {
                tmp = x_atomic.load(std::memory_order_acquire);
            }
            std::cout << "x = " << x_atomic.load() << std::endl;
        }
    });

    t1.join();

    return 0;
}
