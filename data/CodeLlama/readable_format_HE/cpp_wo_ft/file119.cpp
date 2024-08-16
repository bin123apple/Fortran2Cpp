#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> even_odd_count(int num) {
    string w = to_string(abs(num));
    int n1 = 0, n2 = 0;

    for (char c : w) {
        if (c % 2 == 1) {
            n1++;
        } else {
            n2++;
        }
    }

    return {n2, n1};
}

int main() {
    vector<int> result, expected;

    // Test cases
    result = even_odd_count(7);
    expected = {0, 1};
    assert(result == expected);

    result = even_odd_count(-78);
    expected = {1, 1};
    assert(result == expected);

    result = even_odd_count(3452);
    expected = {2, 2};
    assert(result == expected);

    result = even_odd_count(346211);
    expected = {3, 3};
    assert(result == expected);

    result = even_odd_count(-345821);
    expected = {3, 3};
    assert(result == expected);

    result = even_odd_count(-2);
    expected = {1, 0};
    assert(result == expected);

    result = even_odd_count(-45347);
    expected = {2, 3};
    assert(result == expected);

    result = even_odd_count(0);
    expected = {1, 0};
    assert(result == expected);

    return 0;
}

void assert(vector<int> result, vector<int> expected) {
    if (result != expected) {
        cout << "Assertion failed" << endl;
        exit(1);
    }
}

[C#]
using System;
using System.Linq;

class Program
{
    static void Main()
    {
        // Test cases
        Assert(EvenOddCount(7), new int[] { 0, 1 });
        Assert(EvenOddCount(-78), new int[] { 1, 1 });
        Assert(EvenOddCount(3452), new int[] { 2, 2 });
        Assert(EvenOddCount(346211), new int[] { 3, 3 });
        Assert(EvenOddCount(-345821), new int[] { 3, 3 });
        Assert(EvenOddCount(-2), new int[] { 1, 0 });
        Assert(EvenOddCount(-45347), new int[] { 2, 3 });
        Assert(EvenOddCount(0), new int[] { 1, 0 });
    }

    static int[] EvenOddCount(int num)
    {
        string w = Math.Abs(num).ToString();
        int n1 = 0, n2 = 0;

        foreach (char c in w)
        {
            if (c % 2 == 1)
            {
                n1++;
            }
            else
            {
                n2++;
            }
        }

        return new int[] { n2, n1 };
    }

    static void Assert(int[] result, int[] expected)
    {
        if (!result.SequenceEqual(expected))
        {
            Console.WriteLine("Assertion failed");
            Environment.Exit(1);
        }
    }
}

[Python]
def even_odd_count(num):
    w = str(abs(num))
    n1 = 0
    n2 = 0

    for c in w:
        if c % 2 == 1:
            n1 += 1
        else:
            n2 += 1

    return n2, n1

def main():
    # Test cases
    assert even_odd_count(7) == (0, 1)
    assert even_odd_count(-78) == (1, 1)
    assert even_odd_count(3452) == (2, 2)
    assert even_odd_count(346211) == (3, 3)
    assert even_odd_count(-345821) == (3, 3)
    assert even_odd_count(-2) == (1, 0)
    assert even_odd_count(-45347) == (2, 3)
    assert even_odd_count(0) == (1, 0)

def assert(result, expected):
    if result != expected:
        print("Assertion failed")
        exit(1)

if __name__ == "__main__":
    main()

[Java]
import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        // Test cases
        assert(evenOddCount(7), new int[] { 0, 1 });
        assert(evenOddCount(-78), new int[] { 1, 1 });
        assert(evenOddCount(3452), new int[] { 2, 2 });
        assert(evenOddCount(346211), new int[] { 3, 3 });
        assert(evenOddCount(-345821), new int[] { 3, 3 });
        assert(evenOddCount(-2), new int[] { 1, 0 });
        assert(evenOddCount(-45347), new int[] { 2, 3 });
        assert(evenOddCount(0), new int[] { 1, 0 });
    }

    public static int[] evenOddCount(int num) {
        String w = Integer.toString(Math.abs(num));
        int n1 = 0, n2 = 0;

        for (char c : w.toCharArray()) {
            if (c % 2 == 1) {
                n1++;
            } else {
                n2++;
            }
        }

        return new int[] { n2, n1 };
    }

    public static void assert(int[] result, int[] expected) {
        if (!Arrays.equals(result, expected)) {
            System.out.println("Assertion failed");
            System.exit(1);
        }
    }
}

[JavaScript]
function evenOddCount(num) {
    const w = Math.abs(num).toString();
    let n1 = 0, n2 = 0;

    for (const c of w) {
        if (c % 2 == 1) {
            n1++;
        } else {
            n2++;
        }
    }

    return [n2, n1];
}

function main() {
    // Test cases
    assert(evenOddCount(7), [0, 1]);
    assert(evenOddCount(-78), [1, 1]);
    assert(evenOddCount(3452), [2, 2]);
    assert(evenOddCount(346211), [3, 3]);
    assert(evenOddCount(-345821), [3, 3]);
    assert(evenOddCount(-2), [1, 0]);
    assert(evenOddCount(-45347), [2, 3]);
    assert(evenOddCount(0), [1, 0]);
}

function assert(result, expected) {
    if (result.length != expected.length) {
        console.log("Assertion failed");
        process.exit(1);
    }

    for (let i = 0; i < result.length; i++) {
        if (result[i] != expected[i]) {
            console.log("Assertion failed");
            process.exit(1);
        }
    }
}

if (import.meta.main) {
    main();
}

[PHP]
function evenOddCount(int $num): array
{
    $w = abs($num);
    $n1 = 0;
    $n2 = 0;

    while ($w > 0) {
        $c = $w % 10;
        if ($c
