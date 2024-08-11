#include <iostream>
using namespace std;

int main() {
    int n, result;

    cout << "Enter a positive integer" << endl;
    cin >> n;

    result = 1;
    while (n > 1) {
        result *= n;
        --n;
    }

    cout << "Factorial is: " << result << endl;

    return 0;
}