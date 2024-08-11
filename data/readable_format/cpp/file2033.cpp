#include <iostream>

class MoColumn {
public:
    void computeColumn(int& result) {
        result = 5; // Example functionality
    }
};

// A simple test function for MoColumn
void testComputeColumn() {
    MoColumn column;
    int result = 0;
    column.computeColumn(result);

    if (result == 5) {
        std::cout << "Test passed: result = " << result << std::endl;
    } else {
        std::cout << "Test failed: result = " << result << std::endl;
    }
}

int main() {
    testComputeColumn();
    return 0;
}