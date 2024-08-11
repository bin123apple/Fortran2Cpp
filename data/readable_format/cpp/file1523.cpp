#include <iostream>
#include <vector>
#include <cassert>

namespace DataShadowingCombinations {

class ShadowingCombinations {
public:
    bool UseThisSurf = false;
    int NumGenSurf = 0;
    std::vector<int> GenSurf;
    int NumBackSurf = 0;
    std::vector<int> BackSurf;
    int NumSubSurf = 0;
    std::vector<int> SubSurf;

    // Constructor, Destructor, and other member functions can be added here if needed.
};

std::vector<ShadowingCombinations> ShadowComb;

} // namespace DataShadowingCombinations

int main() {
    using namespace DataShadowingCombinations;
    
    ShadowingCombinations testComb;

    // Test initial values
    assert(testComb.UseThisSurf == false);
    std::cout << "UseThisSurf initialized correctly." << std::endl;

    assert(testComb.NumGenSurf == 0);
    std::cout << "NumGenSurf initialized correctly." << std::endl;

    // Test dynamic array functionality by assigning values
    testComb.GenSurf = {1, 2, 3};
    testComb.BackSurf = {4, 5};
    testComb.SubSurf = {6, 7, 8, 9};

    assert(testComb.GenSurf == std::vector<int>({1, 2, 3}));
    std::cout << "GenSurf works correctly." << std::endl;

    // Further tests for BackSurf and SubSurf could be added here

    return 0;
}