#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string intersection(vector<int> interval1, vector<int> interval2) {
    int inter1 = max(interval1[0], interval2[0]);
    int inter2 = min(interval1[1], interval2[1]);
    int l = inter2 - inter1;

    if (l < 2) {
        return "NO";
    }

    for (int i = 2; i <= sqrt(l); i++) {
        if (l % i == 0) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    vector<int> interval1 = {1, 2};
    vector<int> interval2 = {2, 3};
    string result = intersection(interval1, interval2);
    if (result != "NO") {
        cout << "Assertion failed: intersection([1, 2], [2, 3]) == 'NO'" << endl;
        return 1;
    }

    interval1 = {-1, 1};
    interval2 = {0, 4};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        cout << "Assertion failed: intersection([-1, 1], [0, 4]) == 'NO'" << endl;
        return 1;
    }

    interval1 = {-3, -1};
    interval2 = {-5, 5};
    result = intersection(interval1, interval2);
    if (result != "YES") {
        cout << "Assertion failed: intersection([-3, -1], [-5, 5]) == 'YES'" << endl;
        return 1;
    }

    interval1 = {-2, 2};
    interval2 = {-4, 0};
    result = intersection(interval1, interval2);
    if (result != "YES") {
        cout << "Assertion failed: intersection([-2, 2], [-4, 0]) == 'YES'" << endl;
        return 1;
    }

    interval1 = {-11, 2};
    interval2 = {-1, -1};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        cout << "Assertion failed: intersection([-11, 2], [-1, -1]) == 'NO'" << endl;
        return 1;
    }

    interval1 = {1, 2};
    interval2 = {3, 5};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        cout << "Assertion failed: intersection([1, 2], [3, 5]) == 'NO'" << endl;
        return 1;
    }

    interval1 = {1, 2};
    interval2 = {1, 2};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        cout << "Assertion failed: intersection([1, 2], [1, 2]) == 'NO'" << endl;
        return 1;
    }

    interval1 = {-2, -2};
    interval2 = {-3, -2};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        cout << "Assertion failed: intersection([-2, -2], [-3, -2]) == 'NO'" << endl;
        return 1;
    }

    cout << "All tests passed." << endl;
    return 0;
}

[C#]
using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static string Intersection(int[] interval1, int[] interval2)
    {
        int inter1 = Math.Max(interval1[0], interval2[0]);
        int inter2 = Math.Min(interval1[1], interval2[1]);
        int l = inter2 - inter1;

        if (l < 2)
        {
            return "NO";
        }

        for (int i = 2; i <= (int)Math.Sqrt(l); i++)
        {
            if (l % i == 0)
            {
                return "NO";
            }
        }

        return "YES";
    }

    static void Main(string[] args)
    {
        int[] interval1 = { 1, 2 };
        int[] interval2 = { 2, 3 };
        string result = Intersection(interval1, interval2);
        if (result != "NO")
        {
            Console.WriteLine("Assertion failed: intersection([1, 2], [2, 3]) == 'NO'");
            return;
        }

        interval1 = new int[] { -1, 1 };
        interval2 = new int[] { 0, 4 };
        result = Intersection(interval1, interval2);
        if (result != "NO")
        {
            Console.WriteLine("Assertion failed: intersection([-1, 1], [0, 4]) == 'NO'");
            return;
        }

        interval1 = new int[] { -3, -1 };
        interval2 = new int[] { -5, 5 };
        result = Intersection(interval1, interval2);
        if (result != "YES")
        {
            Console.WriteLine("Assertion failed: intersection([-3, -1], [-5, 5]) == 'YES'");
            return;
        }

        interval1 = new int[] { -2, 2 };
        interval2 = new int[] { -4, 0 };
        result = Intersection(interval1, interval2);
        if (result != "YES")
        {
            Console.WriteLine("Assertion failed: intersection([-2, 2], [-4, 0]) == 'YES'");
            return;
        }

        interval1 = new int[] { -11, 2 };
        interval2 = new int[] { -1, -1 };
        result = Intersection(interval1, interval2);
        if (result != "NO")
        {
            Console.WriteLine("Assertion failed: intersection([-11, 2], [-1, -1]) == 'NO'");
            return;
        }

        interval1 = new int[] { 1, 2 };
        interval2 = new int[] { 3, 5 };
        result = Intersection(interval1, interval2);
        if (result != "NO")
        {
            Console.WriteLine("Assertion failed: intersection([1, 2], [3, 5]) == 'NO'");
            return;
        }

        interval1 = new int[] { 1, 2 };
        interval2 = new int[] { 1, 2 };
        result = Intersection(interval1, interval2);
        if (result != "NO")
        {
            Console.WriteLine("Assertion failed: intersection([1, 2], [1, 2]) == 'NO'");
            return;
        }

        interval1 = new int[] { -2, -2 };
        interval2 = new int[] { -3, -2 };
        result = Intersection(interval1, interval2);
        if (result != "NO")
        {
            Console.WriteLine("Assertion failed: intersection([-2, -2], [-3, -2]) == 'NO'");
            return;
        }

        Console.WriteLine("All tests passed.");
    }
}

[Python]
def intersection(interval1, interval2):
    inter1 = max(interval1[0], interval2[0])
    inter2 = min(interval1[1], interval2[1])
    l = inter2 - inter1

    if l < 2:
        return 'NO'

    for i in range(2, int(l ** 0.5) + 1):
        if l % i == 0:
            return 'NO'

    return 'YES'


if __name__ == '__main__':
    interval1 = [1, 2]
    interval2 = [2, 3]
    result = intersection(interval1, interval2)
    if result != 'NO':
        print('Assertion failed: intersection([1, 2], [2, 3]) == 'NO'
