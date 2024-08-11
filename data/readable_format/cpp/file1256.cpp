#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int n = 5;
    vector<int> array(n);
    int total = 0;

    // Initialize the array
    for(int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }

    // Calculate the sum of the array elements
    for(int i = 0; i < n; ++i) {
        total += array[i];
    }

    cout << "Sum of array elements is: " << total << endl;
    return 0;
}