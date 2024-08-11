#include <iostream>
#include <vector>
#include <omp.h>

void do_test(int &rg, int &rw, int &rv, int &rc) {
    const int n = 10;
    std::vector<int> array(n);

    for(int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }

    rg = 0;
    #pragma omp parallel for reduction(+:rg)
    for(int i = 0; i < n; ++i) {
        rg += array[i];
    }

    rw = 0;
    #pragma omp parallel for reduction(+:rw)
    for(int i = 0; i < n; ++i) {
        rw += array[i];
    }

    rv = 0;
    #pragma omp parallel for reduction(+:rv)
    for(int i = 0; i < n; ++i) {
        rv += array[i];
    }

    rc = 0;
    #pragma omp parallel for reduction(+:rc)
    for(int i = 0; i < n; ++i) {
        rc += array[i];
    }
}

bool run_test() {
    int rg, rw, rv, rc;
    const int expected_result = 55; // sum of numbers from 1 to 10

    do_test(rg, rw, rv, rc);

    bool rg_pass = rg == expected_result;
    bool rw_pass = rw == expected_result;
    bool rv_pass = rv == expected_result;
    bool rc_pass = rc == expected_result;

    if (!rg_pass) std::cout << "rg test failed." << std::endl;
    if (!rw_pass) std::cout << "rw test failed." << std::endl;
    if (!rv_pass) std::cout << "rv test failed." << std::endl;
    if (!rc_pass) std::cout << "rc test failed." << std::endl;

    return rg_pass && rw_pass && rv_pass && rc_pass;
}

int main() {
    if(run_test()) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "One or more tests failed." << std::endl;
    }
    return 0;
}