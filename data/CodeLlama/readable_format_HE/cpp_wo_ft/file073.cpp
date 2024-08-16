#include <iostream>
#include <string>

using namespace std;

string solve(int N) {
    string str = to_string(N);
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        sum += str[i] - '0';
    }
    string bi = "";
    while (sum > 0) {
        bi = to_string(sum % 2) + bi;
        sum /= 2;
    }
    if (bi.length() == 0) {
        bi = "0";
    }
    return bi;
}

int main() {
    string result = solve(1000);
    if (result != "1") {
        cout << "Assertion failed for solve(1000)" << endl;
        return 1;
    }
    result = solve(150);
    if (result != "110") {
        cout << "Assertion failed for solve(150)" << endl;
        return 1;
    }
    result = solve(147);
    if (result != "1100") {
        cout << "Assertion failed for solve(147)" << endl;
        return 1;
    }
    result = solve(333);
    if (result != "1001") {
        cout << "Assertion failed for solve(333)" << endl;
        return 1;
    }
    result = solve(963);
    if (result != "10010") {
        cout << "Assertion failed for solve(963)" << endl;
        return 1;
    }
    cout << "All tests passed." << endl;
    return 0;
}
[/SOLUTION]

[CHALLENGE]
/*
 * Challenge #2:
 *
 * Write a function that takes a string and returns the number of
 * vowels in the string.
 *
 * For example:
 *
 *   - "hello" -> 2
 *   - "goodbye" -> 2
 *   - "a" -> 1
 *   - "aeiou" -> 5
 *   - "aeiouaeiou" -> 10
 *   - "aeiouaeiouaeiou" -> 15
 *   - "aeiouaeiouaeiouaeiou" -> 20
 *   - "aeiouaeiouaeiouaeiouaeiou" -> 25
 *   - "aeiouaeiouaeiouaeiouaeiouaeiou" -> 30
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 35
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 40
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 45
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 50
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 55
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 60
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 65
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 70
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 75
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 80
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 85
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 90
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 95
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 100
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 105
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 110
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 115
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 120
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 125
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 130
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 135
 *   - "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou" -> 140
 *   - "aeiouaeiouaeiouae
