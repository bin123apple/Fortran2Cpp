#include <iostream>
#include <cstdint>

extern "C" void _SUM__J(int64_t* dv_result, int64_t* dv_array, int64_t dv_dim, bool* dv_mask) {
    *dv_result = 0; // Initialize result to 0.
    for (int i = 0; i < dv_dim; ++i) {
        if (dv_mask[i]) {
            *dv_result += dv_array[i];
        }
    }
}

void test_sum_j() {
    int64_t result = 0;
    int64_t array[5] = {1, 2, 3, 4, 5};
    bool mask[5] = {true, false, true, false, true};

    _SUM__J(&result, array, 5, mask);

    std::cout << "Sum of masked elements: " << result << std::endl;
    // Expected output: Sum of masked elements: 9
}

int main() {
    test_sum_j();
    return 0;
}