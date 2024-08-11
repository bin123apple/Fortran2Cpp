#include <iostream>
#include <vector>
#include <string>

// side2 function definition
void side2(const std::vector<float>& a_in, const std::vector<float>& sd_a_in, int nx, float badData, int maxSearchRadius,
           int maxValuesPerSide, int ix, int& pointsFound, std::vector<int>& ixFound) {
    pointsFound = 0;
    for (int ixSearch = ix + 1; ixSearch <= ix + maxSearchRadius && ixSearch <= nx; ++ixSearch) {
        if (a_in[ixSearch - 1] != badData && sd_a_in[ixSearch - 1] != badData) { // Adjusting index for 0-based
            pointsFound++;
            if (pointsFound <= maxValuesPerSide) {
                ixFound.push_back(ixSearch); // Adjusting for 1-based indexing expectation in output
            }
            if (pointsFound >= maxValuesPerSide) {
                return;
            }
        }
    }
}

// Test function
void testSide2(const std::vector<float>& a_in, const std::vector<float>& sd_a_in,
               float badData, int maxSearchRadius, int maxValuesPerSide, int ix,
               const std::vector<int>& expectedIndices, const std::string& testName) {
    int pointsFound;
    std::vector<int> ixFound;
    side2(a_in, sd_a_in, a_in.size(), badData, maxSearchRadius, maxValuesPerSide, ix, pointsFound, ixFound);

    std::cout << testName << ": ";
    if (ixFound == expectedIndices && pointsFound == expectedIndices.size()) {
        std::cout << "PASS";
    } else {
        std::cout << "FAIL";
    }
    std::cout << std::endl; // Use std::endl for a newline after outputting the result
}

int main() {
    // Test 1: No elements match the condition
    testSide2({-999, -999, -999, -999}, {-999, -999, -999, -999}, -999, 4, 2, 0, {}, "Test 1: All BADDATA");

    // Test 2: Some elements match the condition, less than MAX_VALUES_PER_SIDE
    testSide2({-999, 1, -999, 2, -999}, {-999, 1, -999, 2, -999}, -999, 4, 2, 0, {2, 4}, "Test 2: Some match, less than MAX_VALUES_PER_SIDE");

    // Test 3: Elements match the condition, exactly MAX_VALUES_PER_SIDE are found
    testSide2({-999, 1, 2, -999, 3}, {-999, 1, 2, -999, 3}, -999, 4, 2, 0, {2, 3}, "Test 3: Exactly MAX_VALUES_PER_SIDE found");

    // Test 4: Elements match the condition, more than MAX_VALUES_PER_SIDE could be found
    testSide2({-999, 1, 2, 3, 4}, {-999, 1, 2, 3, 4}, -999, 4, 2, 0, {2, 3}, "Test 4: More than MAX_VALUES_PER_SIDE found");

    return 0;
}