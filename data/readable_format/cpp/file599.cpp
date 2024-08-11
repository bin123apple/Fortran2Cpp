#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class TT {
public:
    static std::vector<float> two(const std::vector<int>& N) {
        std::vector<float> result(N.size());
        std::transform(N.begin(), N.end(), result.begin(), [](int n) {
            return static_cast<float>(n) * 2.0f;
        });
        return result;
    }

    static std::vector<float> twopointfive(const std::vector<int>& N) {
        std::vector<float> result(N.size());
        std::transform(N.begin(), N.end(), result.begin(), [](int n) {
            return static_cast<float>(n) * 2.5f;
        });
        return result;
    }
};

// Simple test function to verify the functionality
void testFunctionality() {
    std::vector<int> testData = {1, 2, 3, 4, 5};
    std::vector<float> expectedTwo = {2.0f, 4.0f, 6.0f, 8.0f, 10.0f};
    std::vector<float> expectedTwoPointFive = {2.5f, 5.0f, 7.5f, 10.0f, 12.5f};

    auto resultTwo = TT::two(testData);
    auto resultTwoPointFive = TT::twopointfive(testData);

    bool testTwoPassed = std::equal(resultTwo.begin(), resultTwo.end(), expectedTwo.begin(), 
                                    [](float a, float b) { return std::abs(a - b) < 0.001; });

    bool testTwoPointFivePassed = std::equal(resultTwoPointFive.begin(), resultTwoPointFive.end(), expectedTwoPointFive.begin(), 
                                             [](float a, float b) { return std::abs(a - b) < 0.001; });

    if (testTwoPassed && testTwoPointFivePassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

int main() {
    testFunctionality();
    return 0;
}