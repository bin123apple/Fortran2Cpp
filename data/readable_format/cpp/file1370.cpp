#include <iostream>

// Assuming this is a simplified version of your translated function for demonstration.
void fm013_test(int ICZERO, int& IVDELE) {
    if (ICZERO == 0) {
        IVDELE += 1;
    }
}

// A simple manual test function to verify the behavior of fm013_test
void test_fm013(int ICZERO, int expected) {
    int IVDELE = 0;
    fm013_test(ICZERO, IVDELE);
    if (IVDELE == expected) {
        std::cout << "Test passed: ICZERO = " << ICZERO << ", IVDELE = " << IVDELE << std::endl;
    } else {
        std::cout << "Test FAILED: ICZERO = " << ICZERO << ". Expected IVDELE = " << expected << ", got IVDELE = " << IVDELE << std::endl;
    }
}

int main() {
    // Running our manual test with expected outcomes
    test_fm013(0, 1); // Expecting IVDELE to be incremented since ICZERO is 0
    test_fm013(1, 0); // Expecting IVDELE to remain unchanged since ICZERO is not 0

    return 0;
}