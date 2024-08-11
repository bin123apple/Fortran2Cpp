#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

const int N = 10000000;

void quicksort(std::vector<double>& a, int lo, int hi) {
    int i = lo, j = hi;
    double pivot = a[(lo + hi) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (lo < j) quicksort(a, lo, j);
    if (i < hi) quicksort(a, i, hi);
}

int main() {
    std::vector<double> d(N);

    // Seed for random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Fill the vector with random numbers
    for (int i = 0; i < N; ++i) {
        d[i] = dis(gen);
    }

    // Getting start time
    auto t0 = std::chrono::high_resolution_clock::now();

    // Perform quicksort
    quicksort(d, 0, N - 1);

    // Getting end time
    auto t1 = std::chrono::high_resolution_clock::now();

    // Calculating the duration in milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();

    std::cout << "size = " << N << ", msec = " << duration << std::endl;

    return 0;
}