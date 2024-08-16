#include <iostream>
#include <vector>

using namespace std;

void rolling_max(vector<int> &numbers, vector<int> &out) {
    int max = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > max) max = numbers[i];
        out[i] = max;
    }
}

bool is_same(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    vector<int> numbers;
    vector<int> result;
    vector<int> expected;

    // Test case 1
    numbers.clear();
    numbers.push_back(0);
    expected.clear();
    expected.push_back(0);
    rolling_max(numbers, result);
    if (!is_same(result, expected)) {
        cout << "Test case 1 failed" << endl;
        return 1;
    }

    // Test case 2
    numbers.clear();
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    expected.clear();
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);
    expected.push_back(4);
    rolling_max(numbers, result);
    if (!is_same(result, expected)) {
        cout << "Test case 2 failed" << endl;
        return 1;
    }

    // Test case 3
    numbers.clear();
    numbers.push_back(4);
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(1);
    expected.clear();
    expected.push_back(4);
    expected.push_back(4);
    expected.push_back(4);
    expected.push_back(4);
    rolling_max(numbers, result);
    if (!is_same(result, expected)) {
        cout << "Test case 3 failed" << endl;
        return 1;
    }

    // Test case 4
    numbers.clear();
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(100);
    numbers.push_back(3);
    expected.clear();
    expected.push_back(3);
    expected.push_back(3);
    expected.push_back(3);
    expected.push_back(100);
    expected.push_back(100);
    rolling_max(numbers, result);
    if (!is_same(result, expected)) {
        cout << "Test case 4 failed" << endl;
        return 1;
    }

    return 0;
} [/C++]

[C#]
using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Test case 1
        List<int> numbers = new List<int> { 0 };
        List<int> expected = new List<int> { 0 };
        List<int> result = new List<int>();
        rolling_max(numbers, result);
        if (!is_same(result, expected))
        {
            Console.WriteLine("Test case 1 failed");
            return;
        }

        // Test case 2
        numbers = new List<int> { 1, 2, 3, 4 };
        expected = new List<int> { 1, 2, 3, 4 };
        result = new List<int>();
        rolling_max(numbers, result);
        if (!is_same(result, expected))
        {
            Console.WriteLine("Test case 2 failed");
            return;
        }

        // Test case 3
        numbers = new List<int> { 4, 3, 2, 1 };
        expected = new List<int> { 4, 4, 4, 4 };
        result = new List<int>();
        rolling_max(numbers, result);
        if (!is_same(result, expected))
        {
            Console.WriteLine("Test case 3 failed");
            return;
        }

        // Test case 4
        numbers = new List<int> { 3, 2, 3, 100, 3 };
        expected = new List<int> { 3, 3, 3, 100, 100 };
        result = new List<int>();
        rolling_max(numbers, result);
        if (!is_same(result, expected))
        {
            Console.WriteLine("Test case 4 failed");
            return;
        }
    }

    static void rolling_max(List<int> numbers, List<int> out)
    {
        int max = 0;
        for (int i = 0; i < numbers.Count; i++)
        {
            if (numbers[i] > max) max = numbers[i];
            out.Add(max);
        }
    }

    static bool is_same(List<int> a, List<int> b)
    {
        if (a.Count != b.Count) return false;
        for (int i = 0; i < a.Count; i++)
        {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
} [/C#]

[C++11]
#include <iostream>
#include <vector>

using namespace std;

void rolling_max(vector<int> &numbers, vector<int> &out) {
    int max = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > max) max = numbers[i];
        out[i] = max;
    }
}

bool is_same(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    vector<int> numbers;
    vector<int> result;
    vector<int> expected;

    // Test case 1
    numbers.clear();
    numbers.push_back(0);
    expected.clear();
    expected.push_back(0);
    rolling_max(numbers, result);
    if (!is_same(result, expected)) {
        cout << "Test case 1 failed" << endl;
        return 1;
    }

    // Test case 2
    numbers.clear();
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    expected.clear();
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);
    expected.push_back(4);
    rolling_max(numbers, result);
    if (!is_same(result, expected)) {
        cout << "Test case 2 failed" << endl;
        return 1;
    }

    // Test case 3
    numbers.clear();
    numbers.push_back(4);
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(1);
    expected.clear();
    expected.push_back(4);
    expected.push_back(4);
    expected.push_back(4);
    expected.push_back(4);
    rolling_max(numbers, result);
    if (!is_same(result, expected)) {
        cout << "Test case 3 failed" << endl;
        return 1;
    }

    // Test case 4
    numbers.clear();
    numbers.push_back(3);
    numbers.push_back(2);
