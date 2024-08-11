#include <iostream>
#include <cassert>

// Define the TestImplementation class directly in this file
class TestImplementation {
public:
    TestImplementation(int initialValue = 0) : i(initialValue) {}  // Constructor with optional initial value

    // Getter for 'i'
    int getI() const {
        return i;
    }
    
    // Setter for 'i'
    void setI(int value) {
        i = value;
    }
    
private:
    int i; // Private member variable to store the value
};

// Main function to perform the tests
int main() {
    TestImplementation testObj(5);  // Initialize the object with a value of 5
    
    // Test the initial value of 'i'
    assert(testObj.getI() == 5);  // Check if the initial value is correctly set to 5

    // Test setting and getting 'i'
    testObj.setI(10);
    assert(testObj.getI() == 10);  // Verify the value of 'i' after setting it to 10

    std::cout << "All tests passed." << std::endl;

    return 0;
}