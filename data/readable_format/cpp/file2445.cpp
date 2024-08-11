#include <iostream>
#include <vector>
#include <cassert>

void check(const std::vector<int>& a, const std::vector<int>& b, int n) {
    for (int i = 0; i < n; ++i) {
        assert(a[i] == b[i]);
    }
}

void run_main_program() {
    const int n = 20;
    std::vector<int> a(n, 0), b(n, 0);

    #pragma acc parallel copy(a[0:n])
    {
        #pragma acc loop
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        b[i] = i + 1;
    }

    check(a, b, n);

    std::fill(a.begin(), a.end(), 0);

    #pragma acc parallel copyout(a[0:n])
    {
        #pragma acc loop
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        assert(a[i] == b[i]);
    }

    check(a, b, n);

    std::fill(a.begin(), a.end(), 0);

    #pragma acc parallel copyout(a[0:n]) copyin(b[0:n])
    {
        #pragma acc loop
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
    }

    check(a, b, n);

    #pragma acc parallel copy(a[0:n])
    {
        #pragma acc loop
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
    }

    check(a, b, n);

    std::fill(a.begin(), a.end(), 0);

    #pragma acc parallel copyout(a[0:n])
    {
        #pragma acc loop
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
    }

    check(a, b, n);

    std::fill(a.begin(), a.end(), 0);

    #pragma acc parallel copyout(a[0:n]) copyin(b[0:n])
    {
        #pragma acc loop
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
    }

    check(a, b, n);
}

int main() {
    run_main_program();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}