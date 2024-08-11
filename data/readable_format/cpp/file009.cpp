// test.cpp
#include <iostream>
#include <cassert>
using namespace std;

void test(int block[], int array[]) {
    for (int i = array[0] - 1; i < array[1]; i += 2) {
        block[i] = i + 1;
    }

    for (int i = array[1] - 1; i >= array[0] - 1; i -= 2) {
        block[i] += (i + 1);
    }
}

void runTests() {
    // Test Case 1
    int block1[9] = {0};
    int array1[2] = {1, 8};
    test(block1, array1);
    cout << "Test Case 1 Results:" << endl;
    for (int i = 0; i < 9; ++i) {
        cout << "block[" << i << "] = " << block1[i] << endl;
    }

    // Test Case 2
    int block2[9] = {0};
    int array2[2] = {2, 9};
    test(block2, array2);
    cout << "Test Case 2 Results:" << endl;
    for (int i = 0; i < 9; ++i) {
        cout << "block[" << i << "] = " << block2[i] << endl;
    }
}

int main() {
    runTests();
    return 0;
}