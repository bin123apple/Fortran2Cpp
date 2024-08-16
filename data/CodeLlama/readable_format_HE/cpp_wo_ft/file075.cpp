#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sort_array(vector<int> array) {
    int n = array.size();
    if (n == 0) {
        return vector<int>();
    }

    vector<int> out = array;

    // Bubble sort implementation
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (out[j] > out[j + 1]) {
                int temp = out[j];
                out[j] = out[j + 1];
                out[j + 1] = temp;
            }
        }
    }

    if (out[0] + out[n - 1] % 2 == 1) {
        return out;
    } else {
        reverse(out.begin(), out.end());
        return out;
    }
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

void test_cases() {
    assert(issame(sort_array({0}), {0}));
    assert(issame(sort_array({5}), {5}));
    assert(issame(sort_array({2, 4, 3, 0, 1, 5}), {0, 1, 2, 3, 4, 5}));
    assert(issame(sort_array({2, 4, 3, 0, 1, 5, 6}), {6, 5, 4, 3, 2, 1, 0}));
    assert(issame(sort_array({2, 1}), {1, 2}));
    assert(issame(sort_array({15, 42, 87, 32, 11, 0}), {0, 11, 15, 32, 42, 87}));
    assert(issame(sort_array({21, 14, 23, 11}), {23, 21, 14, 11}));
}

int main() {
    test_cases();
}
[/C++]

[C]
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void assert(bool condition) {
    if (!condition) {
        printf("Assertion failed
");
        exit(1);
    }
}

bool issame(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

int *sort_array(int *array, int n) {
    int *out = malloc(sizeof(int) * n);
    memcpy(out, array, sizeof(int) * n);

    // Bubble sort implementation
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (out[j] > out[j + 1]) {
                int temp = out[j];
                out[j] = out[j + 1];
                out[j + 1] = temp;
            }
        }
    }

    if (out[0] + out[n - 1] % 2 == 1) {
        return out;
    } else {
        for (int i = 0; i < n / 2; i++) {
            int temp = out[i];
            out[i] = out[n - i - 1];
            out[n - i - 1] = temp;
        }
        return out;
    }
}

void test_cases() {
    assert(issame(sort_array((int[]){0}, 1), (int[]){0}, 1));
    assert(issame(sort_array((int[]){5}, 1), (int[]){5}, 1));
    assert(issame(sort_array((int[]){2, 4, 3, 0, 1, 5}, 6), (int[]){0, 1, 2, 3, 4, 5}, 6));
    assert(issame(sort_array((int[]){2, 4, 3, 0, 1, 5, 6}, 7), (int[]){6, 5, 4, 3, 2, 1, 0}, 7));
    assert(issame(sort_array((int[]){2, 1}, 2), (int[]){1, 2}, 2));
    assert(issame(sort_array((int[]){15, 42, 87, 32, 11, 0}, 6), (int[]){0, 11, 15, 32, 42, 87}, 6));
    assert(issame(sort_array((int[]){21, 14, 23, 11}, 4), (int[]){23, 21, 14, 11}, 4));
}

int main() {
    test_cases();
}
[/C]

[Python]
def sort_array(array):
    n = len(array)
    if n == 0:
        return []

    out = array.copy()

    # Bubble sort implementation
    for i in range(n - 1):
        for j in range(n - i - 1):
            if out[j] > out[j + 1]:
                out[j], out[j + 1] = out[j + 1], out[j]

    if out[0] + out[n - 1] % 2 == 1:
        return out
    else:
        return out[::-1]

def issame(a, b):
    return a == b

def test_cases():
    assert issame(sort_array([0]), [0])
    assert issame(sort_array([5]), [5])
    assert issame(sort_array([2, 4, 3, 0, 1, 5]), [0, 1, 2, 3, 4, 5])
    assert issame(sort_array([2, 4, 3, 0, 1, 5, 6]), [6, 5, 4, 3, 2, 1, 0])
    assert issame(sort_array([2, 1]), [1, 2])
    assert issame(sort_array([15, 42, 87, 32, 11, 0]), [0, 11, 15, 32, 42, 87])
    assert issame(sort_array([21, 14, 23, 11]), [23, 21, 14, 11])

if __name__ == "__main__":
    test_cases()
[/Python]

[Java]
import java.util.Arrays;

class Main {
    public static void assert(boolean condition) {
        if (!condition) {
            System.out.println("Assertion failed");
            System.exit(1);
        }
    }

    public static boolean issame(int[] a, int[] b) {
        if (a.length != b.length) {
            return false;
        }

        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[
