#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pluck(vector<int> arr) {
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0 && (result.size() == 0 || arr[i] < result[0])) {
            result.clear();
            result.push_back(arr[i]);
            result.push_back(i-1);
        }
    }
    return result;
}

int main() {
    vector<int> arr;
    vector<int> result;

    // Test cases
    arr = {4, 2, 3};
    result = pluck(arr);
    assert(result == vector<int>({2, 1}));

    arr = {1, 2, 3};
    result = pluck(arr);
    assert(result == vector<int>({2, 1}));

    arr = {};
    result = pluck(arr);
    assert(result == vector<int>());

    arr = {5, 0, 3, 0, 4, 2};
    result = pluck(arr);
    assert(result == vector<int>({0, 1}));

    arr = {1, 2, 3, 0, 5, 3};
    result = pluck(arr);
    assert(result == vector<int>({0, 3}));

    arr = {5, 4, 8, 4, 8};
    result = pluck(arr);
    assert(result == vector<int>({4, 1}));

    arr = {7, 6, 7, 1};
    result = pluck(arr);
    assert(result == vector<int>({6, 1}));

    arr = {7, 9, 7, 1};
    result = pluck(arr);
    assert(result == vector<int>());

    return 0;
}

[C#]
using System;
using System.Linq;

class Program
{
    static void Main()
    {
        // Test cases
        var arr = new[] {4, 2, 3};
        var result = Pluck(arr);
        Assert(result, new[] {2, 1});

        arr = new[] {1, 2, 3};
        result = Pluck(arr);
        Assert(result, new[] {2, 1});

        arr = new int[] {};
        result = Pluck(arr);
        Assert(result, new int[] {});

        arr = new[] {5, 0, 3, 0, 4, 2};
        result = Pluck(arr);
        Assert(result, new[] {0, 1});

        arr = new[] {1, 2, 3, 0, 5, 3};
        result = Pluck(arr);
        Assert(result, new[] {0, 3});

        arr = new[] {5, 4, 8, 4, 8};
        result = Pluck(arr);
        Assert(result, new[] {4, 1});

        arr = new[] {7, 6, 7, 1};
        result = Pluck(arr);
        Assert(result, new[] {6, 1});

        arr = new[] {7, 9, 7, 1};
        result = Pluck(arr);
        Assert(result, new int[] {});
    }

    static void Assert(int[] result, int[] expected)
    {
        if (result.Length != expected.Length)
        {
            Console.WriteLine("Assertion failed");
            Environment.Exit(1);
        }

        for (int i = 0; i < result.Length; i++)
        {
            if (result[i] != expected[i])
            {
                Console.WriteLine("Assertion failed");
                Environment.Exit(1);
            }
        }
    }

    static int[] Pluck(int[] arr)
    {
        var result = new int[] {};

        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] % 2 == 0 && (result.Length == 0 || arr[i] < result[0]))
            {
                result = new[] {arr[i], i - 1};
            }
        }

        return result;
    }
}

[Python]
def pluck(arr):
    result = []
    for i in range(len(arr)):
        if arr[i] % 2 == 0 and (len(result) == 0 or arr[i] < result[0]):
            result = [arr[i], i-1]
    return result

def main():
    # Test cases
    arr = [4, 2, 3]
    result = pluck(arr)
    assert result == [2, 1]

    arr = [1, 2, 3]
    result = pluck(arr)
    assert result == [2, 1]

    arr = []
    result = pluck(arr)
    assert result == []

    arr = [5, 0, 3, 0, 4, 2]
    result = pluck(arr)
    assert result == [0, 1]

    arr = [1, 2, 3, 0, 5, 3]
    result = pluck(arr)
    assert result == [0, 3]

    arr = [5, 4, 8, 4, 8]
    result = pluck(arr)
    assert result == [4, 1]

    arr = [7, 6, 7, 1]
    result = pluck(arr)
    assert result == [6, 1]

    arr = [7, 9, 7, 1]
    result = pluck(arr)
    assert result == []

if __name__ == "__main__":
    main()

[JavaScript]
function pluck(arr) {
    var result = [];
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] % 2 == 0 && (result.length == 0 || arr[i] < result[0])) {
            result = [arr[i], i-1];
        }
    }
    return result;
}

function main() {
    // Test cases
    var arr = [4, 2, 3];
    var result = pluck(arr);
    console.assert(result.toString() == [2, 1].toString());

    arr = [1, 2, 3];
    result = pluck(arr);
    console.assert(result.toString() == [2, 1].toString());

    arr = [];
    result = pluck(arr);
    console.assert(result.toString() == [].toString());

    arr = [5, 0, 3, 0, 4, 2];
    result = pluck(arr);
    console.assert(result.toString() == [0, 1].toString());

    arr = [1, 2, 3, 0, 5, 3];
    result = pluck(arr);
    console.assert(result.toString() == [0, 3].toString());

    arr = [5, 4, 8, 4, 8];
    result = pluck(arr);
    console.assert(result.toString() == [4, 1].toString());

    arr = [7, 6, 7, 1];
    result = pluck(arr);
    console.assert(result.toString() == [6, 1].toString());

    arr = [7, 9, 7, 1];
    result = pluck(arr);
    console.assert(result.toString() == [].toString());
}

main();

[PHP]
function pluck($arr) {
    $result = [];
    for ($i = 0; $i < count($arr); $i++) {
        if ($arr[$i] % 2 == 0 && (count($result) == 0 || $arr[$i] < $result[0])) {
