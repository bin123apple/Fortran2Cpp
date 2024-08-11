#include <iostream>
#include <cstdint>

class GET_SLICE_NUMBER__genmod {
public:
    static std::int32_t GET_SLICE_NUMBER(std::int32_t ICHUNK, std::int32_t IXI, std::int32_t IETA, std::int32_t NPROC_XI, std::int32_t NPROC_ETA) {
        return (ICHUNK * NPROC_XI * NPROC_ETA) + (IXI * NPROC_ETA) + IETA;
    }
};

// A simplistic test framework to replace Google Test for this example
void TestSliceNumber(int testId, std::int32_t expected, std::int32_t ICHUNK, std::int32_t IXI, std::int32_t IETA, std::int32_t NPROC_XI, std::int32_t NPROC_ETA) {
    std::int32_t result = GET_SLICE_NUMBER__genmod::GET_SLICE_NUMBER(ICHUNK, IXI, IETA, NPROC_XI, NPROC_ETA);
    if (result == expected) {
        std::cout << "Test #" << testId << " passed." << std::endl;
    } else {
        std::cout << "Test #" << testId << " failed: Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    // Running test cases
    TestSliceNumber(1, 33, 1, 2, 3, 4, 5); // Example test case, adjust accordingly
    
    return 0;
}