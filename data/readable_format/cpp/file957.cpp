// myModule.cpp
#include <iostream>
using namespace std;

int square(int x) {
    return x * x;
}

int increment(int x) {
    return x + 10;
}

void testSquare() {
    int result = square(4);
    cout << "Testing square function... Expected: 16, Got: " << result << endl;
}

void testIncrement() {
    int result = increment(5);
    cout << "Testing increment function... Expected: 15, Got: " << result << endl;
}

int main() {
    testSquare();
    testIncrement();
    return 0;
}