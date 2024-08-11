#include <iostream>

class MyClass {
public:
    int* data = nullptr;
    int currentSize = 0;

    MyClass() = default;

    ~MyClass() {
        delete[] data;
    }

    void resetArray() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
        currentSize = 0;
    }

    bool isDataNullptr() const {
        return data == nullptr;
    }

    int getCurrentSize() const {
        return currentSize;
    }
};

void testResetArray() {
    MyClass testObj;
    // Simulate allocating and setting up the array
    testObj.data = new int[10];  // Assuming we'd fill it with data here
    testObj.currentSize = 10;

    testObj.resetArray();

    // Check if data is correctly deallocated and currentSize reset
    if (testObj.isDataNullptr() && testObj.getCurrentSize() == 0) {
        std::cout << "Test Passed: Data is null and currentSize is 0." << std::endl;
    } else {
        std::cout << "Test Failed: Data is not null or currentSize is not 0." << std::endl;
    }
}

int main() {
    testResetArray();
    return 0;
}