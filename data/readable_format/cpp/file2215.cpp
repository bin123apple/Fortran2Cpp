#include <iostream>
#include <vector>

int main() {
    const int N = 256;
    std::vector<double> a(N, 0.0);

    // OpenACC parallel loop
    #pragma acc parallel loop
    for (int i = 0; i < 1; ++i) {
        // Loop body (empty in this case)
    }

    // OpenACC parallel loop
    #pragma acc parallel loop
    for (int i = 0; i < 1; ++i) {
        // Loop body (empty in this case)
    }

    // OpenACC parallel loop
    #pragma acc parallel loop
    for (int i = 0; i < 1; ++i) {
        // Loop body (empty in this case)
    }

    // OpenACC kernels loop
    #pragma acc kernels
    for (int i = 0; i < 1; ++i) {
        // Loop body (empty in this case)
    }

    // OpenACC serial loop
    #pragma acc serial loop
    for (int i = 0; i < 1; ++i) {
        // Loop body (empty in this case)
    }

    // OpenACC parallel loop
    #pragma acc parallel loop
    for (int i = 0; i < N; ++i) {
        a[i] = 3.14;
    }

    // OpenACC kernels loop
    #pragma acc kernels
    for (int i = 0; i < N; ++i) {
        a[i] = 3.14;
    }

    // OpenACC serial loop
    #pragma acc serial loop
    for (int i = 0; i < N; ++i) {
        a[i] = 3.14;
    }

    // OpenACC parallel loop
    #pragma acc parallel loop
    for (int i = 0; i < N; ++i) {
        a[i] = 3.14;
    }

    // OpenACC kernels loop
    #pragma acc kernels
    for (int i = 0; i < N; ++i) {
        a[i] = 3.14;
    }

    // OpenACC serial loop
    #pragma acc serial loop
    for (int i = 0; i < N; ++i) {
        a[i] = 3.14;
    }

    // OpenACC parallel loop
    #pragma acc parallel loop
    for (int i = 0; i < 1; ++i) {
        // Loop body (empty in this case)
    }

    // OpenACC kernels loop
    #pragma acc kernels
    for (int i = 0; i < 1; ++i) {
        // Loop body (empty in this case)
    }

    // OpenACC serial loop
    #pragma acc serial loop
    for (int i = 0; i < 1; ++i) {
        // Loop body (empty in this case)
    }

    // OpenACC parallel loop with tiling
    #pragma acc parallel
    {
        #pragma acc loop tile(2, 2)
        for (int i = 0; i < N; ++i) {
            a[i] = 3.14;
        }
    }

    // OpenACC parallel loop with tiling
    #pragma acc parallel loop tile(2, 2)
    for (int i = 0; i < N; ++i) {
        a[i] = 3.14;
    }

    return 0;
}