#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

class Dimensions {
private:
    std::vector<int> dimensionList;
    int indexOfSpecialDimension = 0;

public:
    // Constructor from list of dimensions and a special index
    Dimensions(const std::vector<int>& dimList, int specialIndex)
        : dimensionList(dimList), indexOfSpecialDimension(specialIndex) {}

    void printDimensions() const {
        std::cout << "Dimensions: ";
        for (const auto& dim : dimensionList) {
            std::cout << dim << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> getOrderedDimensions() const {
        std::vector<int> sortedDimensions = dimensionList;
        std::sort(sortedDimensions.begin(), sortedDimensions.end());
        return sortedDimensions;
    }

    std::vector<int> getUnorderedDimensions() const {
        return dimensionList;
    }

    int getNumberOfDimensions() const {
        return dimensionList.size();
    }

    void deleteDimensions() {
        dimensionList.clear();
        indexOfSpecialDimension = 0;
    }

    // Additional methods could be added here as needed.
};

// Simple test function to verify the functionality of the Dimensions class
void runTests() {
    std::cout << "Starting tests..." << std::endl;

    std::vector<int> testDims = {4, 1, 3, 2};
    Dimensions myDims(testDims, 2);

    // Test 1: Number of Dimensions
    if (myDims.getNumberOfDimensions() != 4) {
        std::cout << "Test 1 Failed: Incorrect number of dimensions." << std::endl;
    } else {
        std::cout << "Test 1 Passed." << std::endl;
    }

    // Test 2: Ordered Dimensions
    auto orderedDims = myDims.getOrderedDimensions();
    std::vector<int> expectedOrderedDims = {1, 2, 3, 4};
    if (orderedDims != expectedOrderedDims) {
        std::cout << "Test 2 Failed: Ordered dimensions incorrect." << std::endl;
    } else {
        std::cout << "Test 2 Passed." << std::endl;
    }

    // Test 3: Deletion of Dimensions
    myDims.deleteDimensions();
    if (myDims.getNumberOfDimensions() != 0) {
        std::cout << "Test 3 Failed: Deletion failed." << std::endl;
    } else {
        std::cout << "Test 3 Passed." << std::endl;
    }

    std::cout << "Tests completed." << std::endl;
}

int main() {
    runTests();
    return 0;
}