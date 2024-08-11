#include <iostream>
#include <complex>
#include <cstring>

// Assuming the struct two has been defined as shown in the previous answers
struct two {
    int* ivla1 = nullptr;
    int** ivla2 = nullptr;
    ~two() {
        delete[] ivla1;
        for (int i = 0; ivla2 && ivla2[i]; ++i) {
            delete[] ivla2[i];
        }
        delete[] ivla2;
    }
};

class PointersTest {
public:
    int intv;
    two twov;

    PointersTest() {
        initialize_program();
    }

    void initialize_program() {
        // Initialize intv
        intv = 10;
        intv += 1; // Increment intv as per the original Fortran code

        // Allocate and initialize twov.ivla1
        twov.ivla1 = new int[3]{11, 12, 13};

        // Allocate and initialize twov.ivla2
        twov.ivla2 = new int*[2];
        twov.ivla2[0] = new int[2]{211, 212};
        twov.ivla2[1] = new int[2]{221, 222};
    }

    void run_tests() {
        // Test 1: Verify intv
        if (intv == 11) {
            std::cout << "Test 1 Passed: intv incremented correctly." << std::endl;
        } else {
            std::cerr << "Test 1 Failed: intv not incremented correctly." << std::endl;
        }

        // Test 2: Verify dynamic allocation and values in twov
        bool test2Passed = true;
        int expectedIvla1[] = {11, 12, 13};
        int expectedIvla2[2][2] = {{211, 212}, {221, 222}};

        for (int i = 0; i < 3; ++i) {
            if (twov.ivla1[i] != expectedIvla1[i]) {
                test2Passed = false;
                break;
            }
        }

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (twov.ivla2[i][j] != expectedIvla2[i][j]) {
                    test2Passed = false;
                    break;
                }
            }
        }

        if (test2Passed) {
            std::cout << "Test 2 Passed: Dynamic arrays in twov allocated and assigned correctly." << std::endl;
        } else {
            std::cerr << "Test 2 Failed: Error in dynamic arrays of twov." << std::endl;
        }
    }

    ~PointersTest() {
        // Destructor to handle cleanup
    }
};

int main() {
    PointersTest testObj;
    testObj.run_tests();

    return 0;
}