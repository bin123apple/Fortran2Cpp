// sum_array.cpp
#include <iostream>
#include <vector>
using namespace std;

int sumArray(const vector<int>& arr) {
    int total = 0;
    for (int num : arr) {
        total += num;
    }
    return total;
}

// Test code
int main() {
    vector<int> testArray = {1, 2, 3, 4, 5};
    cout << sumArray(testArray) << endl;
    return 0;
}