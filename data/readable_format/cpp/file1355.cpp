#include <iostream>
#include <vector>

// Declaration and definition of the class in the same file
class COMPUTE_STACEY_CM_BACKWARD__genmod {
public:
    void COMPUTE_STACEY_CM_BACKWARD(const std::vector<float>& inputArray, std::vector<float>& outputArray) {
        size_t size = inputArray.size();
        outputArray.resize(size - 1);
        for (size_t i = 1; i < size; ++i) {
            outputArray[i - 1] = inputArray[i] - inputArray[i - 1];
        }
    }
};

// A simple function to manually test the COMPUTE_STACEY_CM_BACKWARD method
void test_COMPUTE_STACEY_CM_BACKWARD() {
    COMPUTE_STACEY_CM_BACKWARD__genmod obj;
    std::vector<float> input = {1, 2, 4, 7, 11};
    std::vector<float> output;

    obj.COMPUTE_STACEY_CM_BACKWARD(input, output);

    std::cout << "Computed backward differences:" << std::endl;
    for (float val : output) {
        std::cout << val << std::endl;
    }
}

// Main function to run the test
int main() {
    test_COMPUTE_STACEY_CM_BACKWARD();
    return 0;
}