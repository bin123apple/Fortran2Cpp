#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool is_sorted(const vector<int>& lst) {
    if (lst.size() <= 1) return true;

    for (int i = 2; i < lst.size(); i++) {
        if (lst[i] < lst[i-1]) return false;
        if (i >= 3 && lst[i] == lst[i-1] && lst[i] == lst[i-2]) return false;
    }
    return true;
}

void assert(bool condition) {
    if (!condition) {
        cout << "Assertion failed" << endl;
        exit(1);
    }
}

int main() {
    vector<int> lst;

    lst = {5};
    assert(is_sorted(lst));

    lst = {1, 2, 3, 4, 5};
    assert(is_sorted(lst));

    lst = {1, 3, 2, 4, 5};
    assert(!is_sorted(lst));

    lst = {1, 2, 3, 4, 5, 6};
    assert(is_sorted(lst));

    lst = {1, 2, 3, 4, 5, 6, 7};
    assert(is_sorted(lst));

    lst = {1, 3, 2, 4, 5, 6, 7};
    assert(!is_sorted(lst));

    lst = {};
    assert(is_sorted(lst));

    lst = {1};
    assert(is_sorted(lst));

    lst = {3, 2, 1};
    assert(!is_sorted(lst));

    lst = {1, 2, 2, 2, 3, 4};
    assert(!is_sorted(lst));

    lst = {1, 2, 3, 3, 3, 4};
    assert(!is_sorted(lst));

    lst = {1, 2, 2, 3, 3, 4};
    assert(is_sorted(lst));

    lst = {1, 2, 3, 4};
    assert(is_sorted(lst));

    return 0;
}

[C#]
using System;
using System.Collections.Generic;

class Program
{
    static bool IsSorted(List<int> lst)
    {
        if (lst.Count <= 1) return true;

        for (int i = 2; i < lst.Count; i++)
        {
            if (lst[i] < lst[i - 1]) return false;
            if (i >= 3 && lst[i] == lst[i - 1] && lst[i] == lst[i - 2]) return false;
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

    static void Main(string[] args)
    {
        List<int> lst = new List<int> { 5 };
        Assert(IsSorted(lst));

        lst = new List<int> { 1, 2, 3, 4, 5 };
        Assert(IsSorted(lst));

        lst = new List<int> { 1, 3, 2, 4, 5 };
        Assert(!IsSorted(lst));

        lst = new List<int> { 1, 2, 3, 4, 5, 6 };
        Assert(IsSorted(lst));

        lst = new List<int> { 1, 2, 3, 4, 5, 6, 7 };
        Assert(IsSorted(lst));

        lst = new List<int> { 1, 3, 2, 4, 5, 6, 7 };
        Assert(!IsSorted(lst));

        lst = new List<int>();
        Assert(IsSorted(lst));

        lst = new List<int> { 1 };
        Assert(IsSorted(lst));

        lst = new List<int> { 3, 2, 1 };
        Assert(!IsSorted(lst));

        lst = new List<int> { 1, 2, 2, 2, 3, 4 };
        Assert(!IsSorted(lst));

        lst = new List<int> { 1, 2, 3, 3, 3, 4 };
        Assert(!IsSorted(lst));

        lst = new List<int> { 1, 2, 2, 3, 3, 4 };
        Assert(IsSorted(lst));

        lst = new List<int> { 1, 2, 3, 4 };
        Assert(IsSorted(lst));
    }
}

[C++11]
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool is_sorted(const vector<int>& lst) {
    if (lst.size() <= 1) return true;

    for (int i = 2; i < lst.size(); i++) {
        if (lst[i] < lst[i-1]) return false;
        if (i >= 3 && lst[i] == lst[i-1] && lst[i] == lst[i-2]) return false;
    }
    return true;
}

void assert(bool condition) {
    if (!condition) {
        cout << "Assertion failed" << endl;
        exit(1);
    }
}

int main() {
    vector<int> lst;

    lst = {5};
    assert(is_sorted(lst));

    lst = {1, 2, 3, 4, 5};
    assert(is_sorted(lst));

    lst = {1, 3, 2, 4, 5};
    assert(!is_sorted(lst));

    lst = {1, 2, 3, 4, 5, 6};
    assert(is_sorted(lst));

    lst = {1, 2, 3, 4, 5, 6, 7};
    assert(is_sorted(lst));

    lst = {1, 3, 2, 4, 5, 6, 7};
    assert(!is_sorted(lst));

    lst = {};
    assert(is_sorted(lst));

    lst = {1};
    assert(is_sorted(lst));

    lst = {3, 2, 1};
    assert(!is_sorted(lst));

    lst = {1, 2, 2, 2, 3, 4};
    assert(!is_sorted(lst));

    lst = {1, 2, 3, 3, 3, 4};
    assert(!is_sorted(lst));

    lst = {1, 2, 2, 3, 3, 4};
    assert(is_sorted(lst));

    lst = {1, 2, 3, 4};
    assert(is_sorted(lst));

    return 0;
}

[C++14]
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool is_sorted(const vector<int>& lst) {
    if (lst.size() <= 1) return true;

    for (int i = 2; i < lst.size(); i++) {
        if (lst[i] < lst[i-1]) return false;
        if (i >= 3 && lst[i] == lst[i-1] && lst[i] == lst[i-2]) return false;
    }
    return true;
}

void assert(bool condition) {
    if (!condition) {
        cout << "Assertion failed" << endl;
        exit(1);
    }
}

int main() {
    vector<int> lst;

    lst = {5};
    assert(is_sorted(lst));

    lst = {1, 2, 3, 4, 5};
    assert(is
