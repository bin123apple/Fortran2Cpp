#include <iostream>
#include <vector>
#include <algorithm>

int checkConditions(const std::vector<int>& K, const std::vector<int>& J) {
    bool condition1Met = false;
    for (size_t i = 0; i < K.size(); ++i) {
        if (J[i] < 3 && std::max_element(K.begin(), K.end()) - K.begin() + 1 != 1) {
            condition1Met = true;
            break;
        }
    }

    if (condition1Met) {
        return 1;
    }

    if (std::any_of(J.begin(), J.end(), [](int val) { return val != 2; })) {
        return 2;
    }

    return 0; // No conditions met
}

int main() {
    std::vector<int> K = {1, 1, 1};
    std::vector<int> J = {2, 2, 2};
    
    int result = checkConditions(K, J);
    std::cout << "Result: " << result << std::endl;

    return 0;
}