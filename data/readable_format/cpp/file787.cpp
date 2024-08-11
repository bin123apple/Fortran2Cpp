#include <iostream>
#include <vector>
#include <cassert>

void PARALLEL_INIT(int& rank, int& npe) {
    rank = 0;
    npe = 1;
}

void PARALLEL_SUM(const std::vector<double>& input, std::vector<double>& output, int n) {
    output.resize(n);
    for (int i = 0; i < n; ++i) {
        output[i] = input[i];
    }
}

void PARALLEL_FINALIZE() {
    // This function is intentionally left blank to match the original Fortran code.
}

// Test functions
void test_PARALLEL_INIT() {
    int rank, npe;
    PARALLEL_INIT(rank, npe);
    assert(rank == 0 && npe == 1);
    std::cout << "PARALLEL_INIT test passed." << std::endl;
}

void test_PARALLEL_SUM() {
    std::vector<double> input = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> output;
    PARALLEL_SUM(input, output, input.size());
    assert(output.size() == input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        assert(input[i] == output[i]);
    }
    std::cout << "PARALLEL_SUM test passed." << std::endl;
}

void test_PARALLEL_FINALIZE() {
    // PARALLEL_FINALIZE does nothing, but we can check it runs without error.
    PARALLEL_FINALIZE();
    std::cout << "PARALLEL_FINALIZE called successfully." << std::endl;
}

int main() {
    test_PARALLEL_INIT();
    test_PARALLEL_SUM();
    test_PARALLEL_FINALIZE();
    return 0;
}