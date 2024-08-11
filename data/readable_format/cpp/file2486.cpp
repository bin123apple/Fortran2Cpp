#include <iostream>
#include <array>
#include <algorithm>

constexpr size_t ARRAY_SIZE = 10;

// Function to initialize the array
std::array<float, ARRAY_SIZE> initialize_array() {
    std::array<float, ARRAY_SIZE> arr;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = static_cast<float>(i + 1);
    }
    return arr;
}

// Function S_REAL_SUM_I
float S_REAL_SUM_I(float A) {
    return 2.0f * A;
}

// Function S_REAL_SUM_2
float S_REAL_SUM_2(int A) {
    return 2.0f * A;
}

// Subroutine SA0054
void SA0054(std::array<float, ARRAY_SIZE>& RDA) {
    std::transform(RDA.begin(), RDA.end(), RDA.begin(), S_REAL_SUM_I); // RDA = S_REAL_SUM_I (RDA)
    for (auto& val : RDA) {
        val += S_REAL_SUM_2(static_cast<int>(val));
    }
}

void test_sa0054() {
    // Initialize the RDA array
    std::array<float, ARRAY_SIZE> RDA = initialize_array();

    // Call the SA0054 subroutine
    SA0054(RDA);

    // Initialize expected values
    std::array<int, ARRAY_SIZE> expected_values;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        expected_values[i] = 6 * (i + 1);
    }

    // Check if the result matches the expected values
    bool condition = std::any_of(RDA.begin(), RDA.end(), [&expected_values](float val) {
        return std::find(expected_values.begin(), expected_values.end(), static_cast<int>(val)) == expected_values.end();
    });

    if (condition) {
        std::cerr << "Test failed: RDA = ";
        for (const auto& val : RDA) {
            std::cerr << val << " ";
        }
        std::cerr << std::endl;
    } else {
        std::cout << "Test passed!" << std::endl;
    }
}

int main() {
    test_sa0054();
    return 0;
}