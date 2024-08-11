#include <iostream>
using namespace std;

// Function to calculate the square of a number
int square(int x) {
    return x * x;
}

int main() {
    int test_number = 4;
    int squared_number;

    // Calculate the square
    squared_number = square(test_number);

    // Print the result
    cout << "The square of " << test_number << " is " << squared_number << endl;

    return 0;
}