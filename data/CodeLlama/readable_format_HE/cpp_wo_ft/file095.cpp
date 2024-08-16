#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubble_sort(vector<int> &arr) {
    int i, j, temp;
    for (i = 0; i < arr.size() - 1; i++) {
        for (j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

vector<int> maximum(vector<int> arr, int k) {
    vector<int> sorted_arr = arr;
    bubble_sort(sorted_arr);
    vector<int> out(k);
    for (int i = 0; i < k; i++) {
        out[i] = sorted_arr[arr.size() - k + i];
    }
    return out;
}

bool issame(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

void assert(bool condition) {
    if (!condition) {
        cout << "Assertion failed" << endl;
        exit(1);
    }
}

void run_tests() {
    assert(issame(maximum({-3, -4, 5}, 3), {-4, -3, 5}));
    assert(issame(maximum({4, -4, 4}, 2), {4, 4}));
    assert(issame(maximum({-3, 2, 1, 2, -1, -2, 1}, 1), {2}));
    assert(issame(maximum({123, -123, 20, 0, 1, 2, -3}, 3), {2, 20, 123}));
    assert(issame(maximum({-123, 20, 0, 1, 2, -3}, 4), {0, 1, 2, 20}));
    assert(issame(maximum({5, 15, 0, 3, -13, -8, 0}, 7), {-13, -8, 0, 0, 3, 5, 15}));
    assert(issame(maximum({-1, 0, 2, 5, 3, -10}, 2), {3, 5}));
    assert(issame(maximum({1, 0, 5, -7}, 1), {5}));
    assert(issame(maximum({4, -4}, 2), {-4, 4}));
    assert(issame(maximum({-10, 10}, 2), {-10, 10}));
    // Handle the empty array case separately
    assert(issame(maximum({1, 2, 3, -23, 243, -400, 0}, 0), {}));
}

int main() {
    run_tests();
    return 0;
} [/C++]

[C#]
using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void BubbleSort(List<int> arr)
    {
        int i, j, temp;
        for (i = 0; i < arr.Count - 1; i++)
        {
            for (j = 0; j < arr.Count - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    static List<int> Maximum(List<int> arr, int k)
    {
        List<int> sorted_arr = arr;
        BubbleSort(sorted_arr);
        List<int> out = new List<int>();
        for (int i = 0; i < k; i++)
        {
            out.Add(sorted_arr[arr.Count - k + i]);
        }
        return out;
    }

    static bool IsSame(List<int> a, List<int> b)
    {
        if (a.Count != b.Count)
        {
            return false;
        }

        for (int i = 0; i < a.Count; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }

        return true;
    }

    static void Assert(bool condition)
    {
        if (!condition)
        {
            Console.WriteLine("Assertion failed");
            Environment.Exit(1);
        }
    }

    static void RunTests()
    {
        Assert(IsSame(Maximum(new List<int> { -3, -4, 5 }, 3), new List<int> { -4, -3, 5 }));
        Assert(IsSame(Maximum(new List<int> { 4, -4, 4 }, 2), new List<int> { 4, 4 }));
        Assert(IsSame(Maximum(new List<int> { -3, 2, 1, 2, -1, -2, 1 }, 1), new List<int> { 2 }));
        Assert(IsSame(Maximum(new List<int> { 123, -123, 20, 0, 1, 2, -3 }, 3), new List<int> { 2, 20, 123 }));
        Assert(IsSame(Maximum(new List<int> { -123, 20, 0, 1, 2, -3 }, 4), new List<int> { 0, 1, 2, 20 }));
        Assert(IsSame(Maximum(new List<int> { 5, 15, 0, 3, -13, -8, 0 }, 7), new List<int> { -13, -8, 0, 0, 3, 5, 15 }));
        Assert(IsSame(Maximum(new List<int> { -1, 0, 2, 5, 3, -10 }, 2), new List<int> { 3, 5 }));
        Assert(IsSame(Maximum(new List<int> { 1, 0, 5, -7 }, 1), new List<int> { 5 }));
        Assert(IsSame(Maximum(new List<int> { 4, -4 }, 2), new List<int> { -4, 4 }));
        Assert(IsSame(Maximum(new List<int> { -10, 10 }, 2), new List<int> { -10, 10 }));
        // Handle the empty array case separately
        Assert(IsSame(Maximum(new List<int> { 1, 2, 3, -23, 243, -400, 0 }, 0), new List<int>()));
    }

    static void Main(string[] args)
    {
        RunTests();
    }
} [/C#]

[Java]
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Program {
    static void bubbleSort(List<Integer> arr) {
        int i, j, temp;
        for (i = 0; i < arr.size() - 1; i++) {
            for (j = 0; j < arr.size() - i - 1; j++) {
                if (arr.get(j) > arr.get(j + 1)) {
                    temp = arr.get(j);
                    arr.set(j
