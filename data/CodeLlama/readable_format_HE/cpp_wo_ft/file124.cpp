#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string solve(string s) {
    string out;
    int nletter = 0;

    for (int i = 0; i < s.length(); i++) {
        char w = s[i];
        if (isupper(w)) {
            w = tolower(w);
        } else if (islower(w)) {
            w = toupper(w);
        } else {
            nletter++;
        }
        out += w;
    }

    if (nletter == s.length()) {
        reverse(out.begin(), out.end());
    }

    return out;
}

int main() {
    string s, result;

    // Test cases
    s = "AsDf";
    result = solve(s);
    if (result != "aSdF") {
        cout << "Assertion failed: solve('AsDf') == 'aSdF'" << endl;
        return 1;
    }

    s = "1234";
    result = solve(s);
    if (result != "4321") {
        cout << "Assertion failed: solve('1234') == '4321'" << endl;
        return 1;
    }

    s = "ab";
    result = solve(s);
    if (result != "AB") {
        cout << "Assertion failed: solve('ab') == 'AB'" << endl;
        return 1;
    }

    s = "#a@C";
    result = solve(s);
    if (result != "#A@c") {
        cout << "Assertion failed: solve('#a@C') == '#A@c'" << endl;
        return 1;
    }

    s = "#AsdfW^45";
    result = solve(s);
    if (result != "#aSDFw^45") {
        cout << "Assertion failed: solve('#AsdfW^45') == '#aSDFw^45'" << endl;
        return 1;
    }

    s = "#6@2";
    result = solve(s);
    if (result != "2@6#") {
        cout << "Assertion failed: solve('#6@2') == '2@6#'" << endl;
        return 1;
    }

    s = "#$a^D";
    result = solve(s);
    if (result != "#$A^d") {
        cout << "Assertion failed: solve('#$a^D') == '#$A^d'" << endl;
        return 1;
    }

    s = "#ccc";
    result = solve(s);
    if (result != "#CCC") {
        cout << "Assertion failed: solve('#ccc') == '#CCC'" << endl;
        return 1;
    }

    cout << "All tests passed." << endl;

    return 0;
}

[C#]
using System;

class Solution {
    public static string solve(string s) {
        string out = "";
        int nletter = 0;

        for (int i = 0; i < s.Length; i++) {
            char w = s[i];
            if (Char.IsUpper(w)) {
                w = Char.ToLower(w);
            } else if (Char.IsLower(w)) {
                w = Char.ToUpper(w);
            } else {
                nletter++;
            }
            out += w;
        }

        if (nletter == s.Length) {
            out = new string(out.Reverse());
        }

        return out;
    }

    static void Main(string[] args) {
        string s, result;

        // Test cases
        s = "AsDf";
        result = solve(s);
        if (result != "aSdF") {
            Console.WriteLine("Assertion failed: solve('AsDf') == 'aSdF'");
            return;
        }

        s = "1234";
        result = solve(s);
        if (result != "4321") {
            Console.WriteLine("Assertion failed: solve('1234') == '4321'");
            return;
        }

        s = "ab";
        result = solve(s);
        if (result != "AB") {
            Console.WriteLine("Assertion failed: solve('ab') == 'AB'");
            return;
        }

        s = "#a@C";
        result = solve(s);
        if (result != "#A@c") {
            Console.WriteLine("Assertion failed: solve('#a@C') == '#A@c'");
            return;
        }

        s = "#AsdfW^45";
        result = solve(s);
        if (result != "#aSDFw^45") {
            Console.WriteLine("Assertion failed: solve('#AsdfW^45') == '#aSDFw^45'");
            return;
        }

        s = "#6@2";
        result = solve(s);
        if (result != "2@6#") {
            Console.WriteLine("Assertion failed: solve('#6@2') == '2@6#'");
            return;
        }

        s = "#$a^D";
        result = solve(s);
        if (result != "#$A^d") {
            Console.WriteLine("Assertion failed: solve('#$a^D') == '#$A^d'");
            return;
        }

        s = "#ccc";
        result = solve(s);
        if (result != "#CCC") {
            Console.WriteLine("Assertion failed: solve('#ccc') == '#CCC'");
            return;
        }

        Console.WriteLine("All tests passed.");
    }
}

[Python]
def solve(s):
    out = ""
    nletter = 0

    for w in s:
        if w.isupper():
            w = w.lower()
        elif w.islower():
            w = w.upper()
        else:
            nletter += 1
        out += w

    if nletter == len(s):
        out = out[::-1]

    return out


if __name__ == "__main__":
    s = "AsDf"
    result = solve(s)
    if result != "aSdF":
        print("Assertion failed: solve('AsDf') == 'aSdF'")
        exit(1)

    s = "1234"
    result = solve(s)
    if result != "4321":
        print("Assertion failed: solve('1234') == '4321'")
        exit(1)

    s = "ab"
    result = solve(s)
    if result != "AB":
        print("Assertion failed: solve('ab') == 'AB'")
        exit(1)

    s = "#a@C"
    result = solve(s)
    if result != "#A@c":
        print("Assertion failed: solve('#a@C') == '#A@c'")
        exit(1)

    s = "#AsdfW^45"
    result = solve(s)
    if result != "#aSDFw^45":
        print("Assertion failed: solve('#AsdfW^45') == '#aSDFw^45'")
        exit(1)

    s = "#6@2"
    result = solve(s)
    if result != "2@6#":
        print("Assertion failed: solve('#6@2') == '2@6#'")
        exit(1)

    s = "#$a^D"
    result = solve(s)
    if result != "#$A^d":
        print("Assertion failed: solve('#$a^D') == '#$A^d'")
        exit(1)

    s = "#ccc"
    result = solve(s)
    if result != "#CCC":
        print("Assertion failed: solve('#ccc') == '#CCC'")
        exit(1)

    print("All tests passed.")

[Java]
import java.util.Scanner;

class Solution {
    public static
