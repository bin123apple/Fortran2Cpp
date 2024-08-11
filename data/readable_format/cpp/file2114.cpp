#include <iostream>
using namespace std;

int add(int number1, int number2) {
    return number1 + number2;
}

int main() {
    int sum = add(5, 7);
    cout << "The sum is: " << sum << endl;
    return 0;
}