#include <iostream>
#include <atomic>

int main() {
    std::atomic<int> a(0);

    #pragma omp parallel
    {
        #pragma omp atomic
        a++;
    }

    std::cout << "a = " << a << std::endl;

    return 0;
}
