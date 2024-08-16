#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

struct pair {
    int a;
    int b;
    mutex lck;
};

void incr_a(pair& p, int& a) {
    lock_guard<mutex> lock(p.lck);
    p.a++;
}

void incr_b(pair& p, int& b) {
    lock_guard<mutex> lock(p.lck);
    p.b++;
}

int main() {
    pair p;
    p.a = 0;
    p.b = 0;

    thread t1([&p]() {
        lock_guard<mutex> lock(p.lck);
        incr_b(p, p.a);
        incr_a(p, p.b);
        lock_guard<mutex> lock(p.lck);
    });

    thread t2([&p]() {
        lock_guard<mutex> lock(p.lck);
        incr_b(p, p.b);
    });

    t1.join();
    t2.join();

    cout << p.b << endl;

    return 0;
}
