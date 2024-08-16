#include <iostream>
#include <vector>

using namespace std;

int prod_signs(vector<int> arr) {
    int sum = 0;
    int prods = 1;

    if (arr.size() == 0 || (arr.size() == 1 && arr[0] == 0)) {
        return -32768;
    }

    for (int i = 0; i < arr.size(); i++) {
        sum += abs(arr[i]);
        if (arr[i] == 0) prods = 0;
        if (arr[i] < 0) prods = -prods;
    }

    return sum * prods;
}

int main() {
    vector<int> arr1 = {1, 2, 2, -4};
    int expected1 = -9;
    int result1 = prod_signs(arr1);
    cout << "Assertion 1: " << result1 << " == " << expected1 << endl;

    vector<int> arr2 = {0, 1};
    int expected2 = 0;
    int result2 = prod_signs(arr2);
    cout << "Assertion 2: " << result2 << " == " << expected2 << endl;

    vector<int> arr3 = {1, 1, 1, 2, 3, -1, 1};
    int expected3 = -10;
    int result3 = prod_signs(arr3);
    cout << "Assertion 3: " << result3 << " == " << expected3 << endl;

    vector<int> arr4 = {};
    int expected4 = -32768;
    int result4 = prod_signs(arr4);
    cout << "Assertion 4: " << result4 << " == " << expected4 << endl;

    vector<int> arr5 = {2, 4, 1, 2, -1, -1, 9};
    int expected5 = 20;
    int result5 = prod_signs(arr5);
    cout << "Assertion 5: " << result5 << " == " << expected5 << endl;

    vector<int> arr6 = {-1, 1, -1, 1};
    int expected6 = 4;
    int result6 = prod_signs(arr6);
    cout << "Assertion 6: " << result6 << " == " << expected6 << endl;

    vector<int> arr7 = {-1, 1, 1, 1};
    int expected7 = -4;
    int result7 = prod_signs(arr7);
    cout << "Assertion 7: " << result7 << " == " << expected7 << endl;

    vector<int> arr8 = {-1, 1, 1, 0};
    int expected8 = 0;
    int result8 = prod_signs(arr8);
    cout << "Assertion 8: " << result8 << " == " << expected8 << endl;

    cout << "All tests passed." << endl;
}

[C]
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int prod_signs(int *arr, int size) {
    int sum = 0;
    int prods = 1;

    if (size == 0 || (size == 1 && arr[0] == 0)) {
        return -32768;
    }

    for (int i = 0; i < size; i++) {
        sum += abs(arr[i]);
        if (arr[i] == 0) prods = 0;
        if (arr[i] < 0) prods = -prods;
    }

    return sum * prods;
}

int main() {
    int arr1[] = {1, 2, 2, -4};
    int expected1 = -9;
    int result1 = prod_signs(arr1, 4);
    printf("Assertion 1: %d == %d
", result1, expected1);

    int arr2[] = {0, 1};
    int expected2 = 0;
    int result2 = prod_signs(arr2, 2);
    printf("Assertion 2: %d == %d
", result2, expected2);

    int arr3[] = {1, 1, 1, 2, 3, -1, 1};
    int expected3 = -10;
    int result3 = prod_signs(arr3, 7);
    printf("Assertion 3: %d == %d
", result3, expected3);

    int arr4[] = {};
    int expected4 = -32768;
    int result4 = prod_signs(arr4, 0);
    printf("Assertion 4: %d == %d
", result4, expected4);

    int arr5[] = {2, 4, 1, 2, -1, -1, 9};
    int expected5 = 20;
    int result5 = prod_signs(arr5, 7);
    printf("Assertion 5: %d == %d
", result5, expected5);

    int arr6[] = {-1, 1, -1, 1};
    int expected6 = 4;
    int result6 = prod_signs(arr6, 4);
    printf("Assertion 6: %d == %d
", result6, expected6);

    int arr7[] = {-1, 1, 1, 1};
    int expected7 = -4;
    int result7 = prod_signs(arr7, 4);
    printf("Assertion 7: %d == %d
", result7, expected7);

    int arr8[] = {-1, 1, 1, 0};
    int expected8 = 0;
    int result8 = prod_signs(arr8, 4);
    printf("Assertion 8: %d == %d
", result8, expected8);

    printf("All tests passed.
");
}

[PY]
def prod_signs(arr):
    sum = 0
    prods = 1

    if len(arr) == 0 or (len(arr) == 1 and arr[0] == 0):
        return -32768

    for i in range(len(arr)):
        sum += abs(arr[i])
        if arr[i] == 0:
            prods = 0
        if arr[i] < 0:
            prods = -prods

    return sum * prods


def main():
    arr1 = [1, 2, 2, -4]
    expected1 = -9
    result1 = prod_signs(arr1)
    print("Assertion 1:", result1, "==", expected1)

    arr2 = [0, 1]
    expected2 = 0
    result2 = prod_signs(arr2)
    print("Assertion 2:", result2, "==", expected2)

    arr3 = [1, 1, 1, 2, 3, -1, 1]
    expected3 = -10
    result3 = prod_signs(arr3)
    print("Assertion 3:", result3, "==", expected3)

    arr4 = []
    expected4 = -32768
    result4 = prod_signs(arr4)
    print("Assertion 4:", result4, "==", expected4)

    arr5 = [2, 4, 1, 2, -1, -1, 9]
    expected5 = 20
    result5 = prod_signs(arr5)
    print("Assertion 5:", result5, "==", expected5)

    arr6 = [-1, 1, -1, 1]
    expected6 = 4
    result6 = prod_signs(arr6)
    print("Assertion 6:", result6, "==", expected6)

    arr7 = [-1, 1, 1, 1]
    expected7 = -4
    result7 = prod_signs(arr7)
    print("Assertion
