#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class KPoints {
public:
    int nkpoints;
    std::vector<std::vector<float>> special_k;
    std::vector<std::vector<float>> special_k_orig;
    std::vector<float> weight_k;
    std::vector<float> weight_k_orig;
    std::vector<std::vector<float>> scale_k;

    std::string kptpreference;

    void allocateSpecialK(int dim1, int dim2) {
        special_k.resize(dim1, std::vector<float>(dim2));
    }

    // Other member functions...
};

void testKPoints() {
    KPoints kp;
    kp.nkpoints = 5;
    assert(kp.nkpoints == 5);

    kp.allocateSpecialK(3, 2);
    assert(kp.special_k.size() == 3);
    assert(kp.special_k[0].size() == 2);

    // Fill in the special_k values
    for (size_t i = 0; i < kp.special_k.size(); ++i) {
        for (size_t j = 0; j < kp.special_k[i].size(); ++j) {
            kp.special_k[i][j] = (i + 1) * (j + 1) * 0.5;
            assert(kp.special_k[i][j] == (i + 1) * (j + 1) * 0.5);
        }
    }

    kp.kptpreference = "High symmetry path";
    assert(kp.kptpreference == "High symmetry path");

    std::cout << "All tests passed." << std::endl;
}

int main() {
    testKPoints();
    return 0;
}