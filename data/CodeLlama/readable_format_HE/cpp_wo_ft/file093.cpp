#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sort_array(vector<int> arr) {
    vector<int> bin;
    vector<int> sorted_arr;
    int i, j, n, b, m;

    sorted_arr = arr;

    for (i = 0; i < arr.size(); i++) {
        b = 0;
        n = arr[i];
        while (n > 0) {
            b += n % 2;
            n /= 2;
        }
        bin.push_back(b);
    }

    for (i = 0; i < arr.size(); i++) {
        for (j = 1; j < arr.size(); j++) {
            if (bin[j] < bin[j-1] || (bin[j] == bin[j-1] && sorted_arr[j] < sorted_arr[j-1])) {
                m = sorted_arr[j];
                sorted_arr[j] = sorted_arr[j-1];
                sorted_arr[j-1] = m;
                m = bin[j];
                bin[j] = bin[j-1];
                bin[j-1] = m;
            }
        }
    }

    return sorted_arr;
}

int main() {
    vector<int> arr = {1, 5, 2, 3, 4};
    vector<int> expected = {1, 2, 4, 3, 5};
    vector<int> sorted_arr = sort_array(arr);

    if (sorted_arr != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    arr = {-2, -3, -4, -5, -6};
    expected = {-4, -2, -6, -5, -3};
    sorted_arr = sort_array(arr);

    if (sorted_arr != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    arr = {1, 0, 2, 3, 4};
    expected = {0, 1, 2, 4, 3};
    sorted_arr = sort_array(arr);

    if (sorted_arr != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    arr = {2, 5, 77, 4, 5, 3, 5, 7, 2, 3, 4};
    expected = {2, 2, 4, 4, 3, 3, 5, 5, 5, 7, 77};
    sorted_arr = sort_array(arr);

    if (sorted_arr != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    arr = {3, 6, 44, 12, 32, 5};
    expected = {32, 3, 5, 6, 12, 44};
    sorted_arr = sort_array(arr);

    if (sorted_arr != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    arr = {2, 4, 8, 16, 32};
    expected = {2, 4, 8, 16, 32};
    sorted_arr = sort_array(arr);

    if (sorted_arr != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    arr = {2, 4, 8, 16, 32};
    expected = {2, 4, 8, 16, 32};
    sorted_arr = sort_array(arr);

    if (sorted_arr != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    return 0;
}

[C]
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int size;
} Array;

Array sort_array(Array arr) {
    Array sorted_arr;
    int *bin;
    int i, j, n, b, m;

    sorted_arr.arr = malloc(arr.size * sizeof(int));
    sorted_arr.size = arr.size;
    bin = malloc(arr.size * sizeof(int));

    for (i = 0; i < arr.size; i++) {
        sorted_arr.arr[i] = arr.arr[i];
    }

    for (i = 0; i < arr.size; i++) {
        b = 0;
        n = arr.arr[i];
        while (n > 0) {
            b += n % 2;
            n /= 2;
        }
        bin[i] = b;
    }

    for (i = 0; i < arr.size; i++) {
        for (j = 1; j < arr.size; j++) {
            if (bin[j] < bin[j-1] || (bin[j] == bin[j-1] && sorted_arr.arr[j] < sorted_arr.arr[j-1])) {
                m = sorted_arr.arr[j];
                sorted_arr.arr[j] = sorted_arr.arr[j-1];
                sorted_arr.arr[j-1] = m;
                m = bin[j];
                bin[j] = bin[j-1];
                bin[j-1] = m;
            }
        }
    }

    return sorted_arr;
}

bool is_equal(Array a, Array b) {
    int i;

    if (a.size != b.size) {
        return false;
    }

    for (i = 0; i < a.size; i++) {
        if (a.arr[i] != b.arr[i]) {
            return false;
        }
    }

    return true;
}

void test_case(Array arr, Array expected) {
    Array sorted_arr = sort_array(arr);

    if (!is_equal(sorted_arr, expected)) {
        printf("Assertion failed
");
        exit(1);
    }
}

int main() {
    Array arr = {1, 5, 2, 3, 4};
    Array expected = {1, 2, 4, 3, 5};
    test_case(arr, expected);

    arr = {-2, -3, -4, -5, -6};
    expected = {-4, -2, -6, -5, -3};
    test_case(arr, expected);

    arr = {1, 0, 2, 3, 4};
    expected = {0, 1, 2, 4, 3};
    test_case(arr, expected);

    arr = {2, 5, 77, 4, 5, 3, 5, 7, 2, 3, 4};
    expected = {2, 2, 4, 4, 3, 3, 5, 5, 5, 7, 77};
    test_case(arr, expected);

    arr = {3, 6, 44, 12, 32, 5};
    expected = {32, 3, 5, 6, 12, 44};
    test_case(arr, expected);

    arr = {2, 4, 8, 16, 32};
    expected = {2, 4, 8, 16, 32};
    test_case(arr, expected);

    arr = {2, 4, 8, 16, 32};
    expected = {2, 4, 8, 16, 32};
    test_case(arr, expected);

    return 0;
}

[Python]
def sort_array(arr):
    bin = []
    sorted_arr =
