#include <iostream>
#include <vector>
#include <algorithm>

void bubbleSort(std::vector<double>& array) {
    for (size_t i = 0; i < array.size() - 1; ++i) {
        for (size_t j = 0; j < array.size() - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

double computeMedian(const std::vector<double>& array) {
    size_t n = array.size();
    if (n % 2 == 0) {
        return (array[n / 2 - 1] + array[n / 2]) / 2.0;
    } else {
        return array[n / 2];
    }
}

double computeQuantile(const std::vector<double>& array, double q) {
    int idx = static_cast<int>(q * (array.size() + 1)) - 1;
    idx = std::max(0, std::min(idx, static_cast<int>(array.size()) - 1));
    return array[idx];
}

int main() {
    std::vector<double> data = {17.2, 18.1, 16.5, 18.3, 12.6};

    bubbleSort(data);
    std::cout << "Sorted dataset: ";
    for (const auto& d : data) std::cout << d << " ";
    std::cout << std::endl;

    double median = computeMedian(data);
    double upperq = computeQuantile(data, 0.75);
    double lowerq = computeQuantile(data, 0.25);

    std::cout << "The median is " << median << std::endl;
    std::cout << "The upper quartile is " << upperq << std::endl;
    std::cout << "The lower quartile is " << lowerq << std::endl;

    return 0;
}