// test_where_construct2.cpp
#include <iostream>
#include <iomanip>
#include <random>
#include <cassert>

void generateAndTest() {
    const int N = 7;
    float a[N][N], b[N][N];
    float threshold = 0.5;

    // Generate predictable values for testing
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = 0.1 * (i * N + j + 1);
            b[i][j] = 0.0;
        }
    }

    // Apply threshold condition
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] > threshold) {
                b[i][j] = a[i][j];
            }
        }
    }

    // Test
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] > threshold) {
                assert(b[i][j] == a[i][j]);
            } else {
                assert(b[i][j] == 0.0);
            }
        }
    }

    std::cout << "Test passed." << std::endl;
}

int main() {
    generateAndTest();
    return 0;
}