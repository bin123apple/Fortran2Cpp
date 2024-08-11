// square_array.cpp
#include <iostream>
using namespace std;

void squareArray(float arr[], int n) {
    for(int i = 0; i < n; ++i) {
        arr[i] = arr[i] * arr[i];
    }
}

int main() {
    float testArray[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int n = sizeof(testArray) / sizeof(testArray[0]);

    squareArray(testArray, n);

    for(int i = 0; i < n; ++i) {
        cout << "testArray[" << i << "] = " << testArray[i] << endl;
    }

    return 0;
}