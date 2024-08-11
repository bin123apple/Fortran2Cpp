#include <iostream>
#include <vector>

// Definition of the convert2slapcol function
void convert2slapcol(const std::vector<double>& au, const std::vector<double>& ad, const std::vector<int>& jq, int nzs, int nef, std::vector<double>& aua) {
    int k = nzs + nef;

    for (int i = nef; i >= 1; --i) {
        for (int j = jq[i] - 1; j >= jq[i - 1]; --j) {
            aua[k - 1] = au[j - 1]; // Adjusting index for 0-based C++
            --k;
        }
        aua[k - 1] = ad[i - 1]; // Adjusting index for 0-based C++
        --k;
    }
}

// Unit test code for the convert2slapcol function
void test_convert2slapcol() {
    std::vector<double> au = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> ad = {10.0, 20.0, 30.0, 40.0, 50.0};
    std::vector<int> jq = {1, 2, 3, 4, 5, 6}; // Note: The last element serves as the boundary for the loop
    std::vector<double> aua(10); // Initialize with size 10

    convert2slapcol(au, ad, jq, 5, 5, aua);

    std::cout << "aua:" << std::endl;
    for (double val : aua) {
        std::cout << val << std::endl;
    }
}

int main() {
    test_convert2slapcol();
    return 0;
}