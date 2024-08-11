// sum_array.cpp
#include <iostream>
#include <vector>

int sum_array(const std::vector<int>& arr) {
    int total = 0;
    for (int num : arr) {
        total += num;
    }
    return total;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int total = sum_array(numbers);
    std::cout << "Sum is: " << total << std::endl;
    return 0;
}