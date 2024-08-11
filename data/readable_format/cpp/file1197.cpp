#include <iostream>
#include <cassert>

// Definition of the getindx function
void getindx(int n, double min, double siz, double loc, int& index, bool& inflag) {
    // Calculate index
    index = static_cast<int>((loc - min) / siz + 1.5);

    // Check bounds and set inflag accordingly
    if (index < 1) {
        index = 1;
        inflag = false;
    } else if (index > n) {
        index = n;
        inflag = false;
    } else {
        inflag = true;
    }
}

// Main function containing unit tests
int main() {
    int n, index;
    double min, siz, loc;
    bool inflag;

    // Test Case 1: loc is within range, should set inflag to true
    n = 10;
    min = 0.0;
    siz = 1.0;
    loc = 5.0;
    getindx(n, min, siz, loc, index, inflag);
    assert(index == 6 && inflag == true);
    std::cout << "Test 1 passed." << std::endl;

    // Test Case 2: loc is below range, should adjust index to 1 and set inflag to false
    loc = -1.0;
    getindx(n, min, siz, loc, index, inflag);
    assert(index == 1 && inflag == false);
    std::cout << "Test 2 passed." << std::endl;

    // Test Case 3: loc is above range, should adjust index to n and set inflag to false
    loc = 11.0;
    getindx(n, min, siz, loc, index, inflag);
    assert(index == n && inflag == false);
    std::cout << "Test 3 passed." << std::endl;

    // Add more tests as needed

    return 0;
}