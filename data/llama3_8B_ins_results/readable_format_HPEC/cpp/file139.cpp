#include <iostream>
#include <mutex>

using namespace std;

struct pair {
    int a;
    int b;
    std::mutex lck;
};

void incr_a(pair& p, int& a) {
    // implement incr_a logic here
}

void incr_b(pair& p, int& b) {
    // implement incr_b logic here
}

int main() {
    pair p;
    p.a = 0;
    p.b = 0;

    std::lock_guard<std::mutex> lock(p.lck);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            lock.lock();
            incr_b(p, p.a);
            incr_a(p, p.b);
            lock.unlock();
        }

        #pragma omp section
        {
            lock.lock();
            incr_b(p, p.b);
            lock.unlock();
        }
    }

    lock.unlock();

    std::cout << p.b << std::endl;

    return 0;
}
