#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

void main_logic() {
    std::vector<std::vector<int>> a(2, std::vector<int>(6));
    std::vector<std::vector<int>> i(3, std::vector<int>(2));

    std::iota(a[0].begin(), a[0].end(), 1);
    std::transform(a[0].begin(), a[0].end(), a[1].begin(), [](int j) { return -10 * j; });

    i[0] = {1, 4};
    i[1] = {3, 5};
    i[2] = {5, 6};

    std::vector<int> ai_flat;
    for (int k = 0; k < 3; ++k) {
        int index = i[k][0] - 1; // Adjusting from 1-based to 0-based indexing
        ai_flat.push_back(a[0][index]);
        ai_flat.push_back(a[1][index]);
    }

    std::vector<int> expected = {1, -10, 3, -30, 5, -50};
    if (ai_flat != expected) {
        std::cerr << "Assertion failed: ai_flat != expected" << std::endl;
        std::exit(1);
    }

    std::cout << "C++ tests passed." << std::endl;
}

int main() {
    main_logic();
    return 0;
}