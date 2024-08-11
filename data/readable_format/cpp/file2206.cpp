#include <iostream>
using namespace std;

// Function that we are testing
int getNum() {
    int num = 3;
    return num;
}

// Simple test function
void testGetNum() {
    int expected = 3;
    int result = getNum();
    if (result == expected) {
        cout << "Test Passed: getNum() returned " << result << ", as expected." << endl;
    } else {
        cout << "Test Failed: getNum() returned " << result << ", expected " << expected << "." << endl;
    }
}

int main() {
    // Run the test
    testGetNum();

    // Original functionality
    cout << "Original functionality: getNum() returns " << getNum() << endl;

    return 0;
}