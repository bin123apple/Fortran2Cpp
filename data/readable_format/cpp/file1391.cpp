#include <iostream>
#include <vector>

void check_arrays(const std::vector<int>& auxiliary_empty_cells, int current_empty_cells, const std::vector<int>& empty_cells, int& error_index) {
    error_index = -1; // Initialize error_index to -1
    for(int i = 0; i < current_empty_cells; ++i) {
        if(i != auxiliary_empty_cells[empty_cells[i]]) {
            error_index = empty_cells[i];
            return;
        }
    }
}

void run_test(const std::vector<int>& auxiliary_empty_cells, int current_empty_cells, const std::vector<int>& empty_cells, int expected_error_index) {
    int error_index;
    check_arrays(auxiliary_empty_cells, current_empty_cells, empty_cells, error_index);

    if (error_index == expected_error_index) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Expected error index: " << expected_error_index << ", but got: " << error_index << std::endl;
    }
}

int main() {
    // Example test case
    std::vector<int> auxiliary_empty_cells(256);
    std::vector<int> empty_cells(256);
    for(int i = 0; i < 256; ++i) {
        auxiliary_empty_cells[i] = i; // Fill auxiliary_empty_cells with indices for simplicity
        empty_cells[i] = i; // Fill empty_cells with indices for simplicity
    }

    int current_empty_cells = 5; // Example value

    run_test(auxiliary_empty_cells, current_empty_cells, empty_cells, -1); // Running the test

    return 0;
}