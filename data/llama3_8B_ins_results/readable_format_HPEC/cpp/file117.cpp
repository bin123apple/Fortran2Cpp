#include <iostream>
#include <thread>
#include <mutex>

int i = 0;
std::mutex mtx;

void task1() {
    std::lock_guard<std::mutex> lock(mtx);
    i = 1;
}

void task2() {
    std::lock_guard<std::mutex> lock(mtx);
    i = 2;
}

int main() {
    std::thread t1(task1);
    t1.join();

    std::thread t2(task2);
    t2.join();

    if (i!= 2) {
        std::cout << "i is not equal to 2" << std::endl;
    }

    return 0;
}
