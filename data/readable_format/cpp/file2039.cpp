#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <random>

int main() {
    const int N = 1000;
    std::vector<int> random_array(N);
    int ans_val, val, result;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    result = 0;
    for (int i = 0; i < N; ++i) {
        random_array[i] = static_cast<int>(distribution(generator) * 10000);
    }

    ans_val = 0;
    for (int i = 0; i < N; ++i) {
        ans_val = std::max(ans_val, random_array[i]);
    }

    val = 0;
    for (int i = 0; i < N; ++i) {
        val = std::max(val, random_array[i]);
    }

    if (val != ans_val) {
        result = -1;
    }

    if (result == 0) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
        std::exit(1);
    }

    return 0;
}