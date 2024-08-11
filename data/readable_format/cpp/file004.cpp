#include <iostream>
#include <vector>
#include <cassert>

class BitCalculator {
private:
    static bool initialized;
    static std::vector<int> NP;

public:
    static int ITBIT(int N, int I) {
        if (!initialized) {
            initialize();
        }
        
        if (I > 0 && I <= 25) {
            return (N % NP[I + 1]) / NP[I];
        } else {
            return 0;
        }
    }

private:
    static void initialize() {
        NP.assign(27, 0); // Resize and initialize NP with 0s. Adjusted size to 27 to use 1-based indexing
        NP[1] = 1;
        for (int J = 2; J <= 26; ++J) {
            NP[J] = 2 * NP[J - 1];
        }
        initialized = true;
    }
};

// Static members initialization
bool BitCalculator::initialized = false;
std::vector<int> BitCalculator::NP;

void testITBIT() {
    std::cout << "Testing ITBIT..." << std::endl;

    assert(BitCalculator::ITBIT(10, 2) == 1);
    std::cout << "Test 1 passed." << std::endl;

    assert(BitCalculator::ITBIT(4, 2) == 0);
    std::cout << "Test 2 passed." << std::endl;

    assert(BitCalculator::ITBIT(1, 1) == 1);
    std::cout << "Test 3 passed." << std::endl;
}

int main() {
    testITBIT();
    return 0;
}