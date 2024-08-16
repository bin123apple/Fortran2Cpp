#include <iostream>
#include <thread>
#include <mutex>

int a, b, c, d;

std::mutex mtx;

void taskT1() {
    c = 1;
}

void taskT2() {
    a = 2;
}

void taskT3() {
    b = 3;
}

void taskT4() {
    std::lock_guard<std::mutex> lock(mtx);
    c = c + a;
}

void taskT5() {
    std::lock_guard<std::mutex> lock(mtx);
    c = c + b;
}

void taskT6() {
    d = c;
}

int main() {
    std::thread t1(taskT1);
    std::thread t2(taskT2);
    std::thread t3(taskT3);
    std::thread t4(taskT4);
    std::thread t5(taskT5);
    std::thread t6(taskT6);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    std::cout << d << std::endl;

    return 0;
}
