#include <iostream>
#include <vector>
#include <cassert>

void per_out2(const std::vector<std::vector<double>>& input, int n, std::vector<std::vector<double>>& output, int& m) {
    int jo = 0;

    for (int j = 0; j < n; ++j) {
        if (input[2][j] != 0.0) {
            if (jo >= m) {
                std::cerr << "Output array is too small for the filtered data." << std::endl;
                return;
            }
            for (int i = 0; i < 3; ++i) {
                output[i][jo] = input[i][j];
            }
            ++jo;
        }
    }

    if (jo < m) {
        std::cerr << "Output array is larger than non-zero columns. Only " << jo << " columns are filled." << std::endl;
    }
    m = jo; // Update m to reflect the actual number of non-zero columns processed
}

int main() {
    // Test 1: All elements in the third row are non-zero
    std::vector<std::vector<double>> input1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m1 = 3;
    std::vector<std::vector<double>> output1(3, std::vector<double>(m1, 0));
    per_out2(input1, 3, output1, m1);
    assert(m1 == 3);

    // Test 2: Some elements in the third row are zero
    std::vector<std::vector<double>> input2 = {{1, 2, 3}, {4, 5, 6}, {7, 0, 0}};
    int m2 = 3; // Initially allocate more space than needed
    std::vector<std::vector<double>> output2(3, std::vector<double>(m2, 0));
    per_out2(input2, 3, output2, m2);
    assert(m2 == 1);

    // Test 3: All elements in the third row are zero
    std::vector<std::vector<double>> input3 = {{1, 2, 3}, {4, 5, 6}, {0, 0, 0}};
    int m3 = 3; // Initially allocate more space than needed
    std::vector<std::vector<double>> output3(3, std::vector<double>(m3, 0));
    per_out2(input3, 3, output3, m3);
    assert(m3 == 0);

    std::cout << "All tests passed." << std::endl;

    return 0;
}