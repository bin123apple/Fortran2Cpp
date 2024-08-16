#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string rounded_avg(int n, int m) {
    if (n > m) {
        return "-1";
    }

    int num = (m + n) / 2;
    string out = "";
    while (num > 0) {
        int remainder = num % 2;
        string digit = to_string(remainder);
        out = digit + out;
        num = num / 2;
    }

    if (out.length() == 0) {
        out = "0";
    }

    return out;
}

int main() {
    assert(rounded_avg(1, 5) == "11");
    assert(rounded_avg(7, 13) == "1010");
    assert(rounded_avg(964, 977) == "1111001010");
    assert(rounded_avg(996, 997) == "1111100100");
    assert(rounded_avg(560, 851) == "1011000001");
    assert(rounded_avg(185, 546) == "101101101");
    assert(rounded_avg(362, 496) == "110101101");
    assert(rounded_avg(350, 902) == "1001110010");
    assert(rounded_avg(197, 233) == "11010111");
    assert(rounded_avg(7, 5) == "-1");
    assert(rounded_avg(5, 1) == "-1");
    assert(rounded_avg(5, 5) == "101");

    return 0;
}

void assert(string expected, string actual) {
    if (expected != actual) {
        cout << "Assertion failed: " << expected << " != " << actual << endl;
        exit(1);
    }
}

[C#]
using System;

class Solution {
    public static void Main(string[] args) {
        assert(rounded_avg(1, 5) == "11");
        assert(rounded_avg(7, 13) == "1010");
        assert(rounded_avg(964, 977) == "1111001010");
        assert(rounded_avg(996, 997) == "1111100100");
        assert(rounded_avg(560, 851) == "1011000001");
        assert(rounded_avg(185, 546) == "101101101");
        assert(rounded_avg(362, 496) == "110101101");
        assert(rounded_avg(350, 902) == "1001110010");
        assert(rounded_avg(197, 233) == "11010111");
        assert(rounded_avg(7, 5) == "-1");
        assert(rounded_avg(5, 1) == "-1");
        assert(rounded_avg(5, 5) == "101");
    }

    public static string rounded_avg(int n, int m) {
        if (n > m) {
            return "-1";
        }

        int num = (m + n) / 2;
        string out = "";
        while (num > 0) {
            int remainder = num % 2;
            string digit = remainder.ToString();
            out = digit + out;
            num = num / 2;
        }

        if (out.Length == 0) {
            out = "0";
        }

        return out;
    }

    public static void assert(string expected, string actual) {
        if (expected != actual) {
            Console.WriteLine("Assertion failed: " + expected + " != " + actual);
            Environment.Exit(1);
        }
    }
}

[Python]
def rounded_avg(n, m):
    if n > m:
        return "-1"

    num = (m + n) / 2
    out = ""
    while num > 0:
        remainder = num % 2
        digit = str(remainder)
        out = digit + out
        num = num // 2

    if len(out) == 0:
        out = "0"

    return out

def assert(expected, actual):
    if expected != actual:
        print("Assertion failed: " + expected + " != " + actual)
        exit(1)

assert(rounded_avg(1, 5) == "11")
assert(rounded_avg(7, 13) == "1010")
assert(rounded_avg(964, 977) == "1111001010")
assert(rounded_avg(996, 997) == "1111100100")
assert(rounded_avg(560, 851) == "1011000001")
assert(rounded_avg(185, 546) == "101101101")
assert(rounded_avg(362, 496) == "110101101")
assert(rounded_avg(350, 902) == "1001110010")
assert(rounded_avg(197, 233) == "11010111")
assert(rounded_avg(7, 5) == "-1")
assert(rounded_avg(5, 1) == "-1")
assert(rounded_avg(5, 5) == "101")

[JavaScript]
function rounded_avg(n, m) {
    if (n > m) {
        return "-1";
    }

    let num = (m + n) / 2;
    let out = "";
    while (num > 0) {
        let remainder = num % 2;
        let digit = remainder.toString();
        out = digit + out;
        num = num / 2;
    }

    if (out.length == 0) {
        out = "0";
    }

    return out;
}

function assert(expected, actual) {
    if (expected != actual) {
        console.log("Assertion failed: " + expected + " != " + actual);
        process.exit(1);
    }
}

assert(rounded_avg(1, 5) == "11");
assert(rounded_avg(7, 13) == "1010");
assert(rounded_avg(964, 977) == "1111001010");
assert(rounded_avg(996, 997) == "1111100100");
assert(rounded_avg(560, 851) == "1011000001");
assert(rounded_avg(185, 546) == "101101101");
assert(rounded_avg(362, 496) == "110101101");
assert(rounded_avg(350, 902) == "1001110010");
assert(rounded_avg(197, 233) == "11010111");
assert(rounded_avg(7, 5) == "-1");
assert(rounded_avg(5, 1)
