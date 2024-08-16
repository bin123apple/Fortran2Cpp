#include <iostream>
#include <vector>

int smallest_change(const std::vector<int>& arr) {
    int out = 0;
    for (int i = 0; i < arr.size() / 2; i++) {
        if (arr[i] != arr[arr.size() - 1 - i]) {
            out++;
        }
    }
    return out;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 5, 4, 7, 9, 6};
    if (smallest_change(arr1) != 4) {
        std::cout << "Assertion failed: smallest_change([1, 2, 3, 5, 4, 7, 9, 6]) == 4" << std::endl;
        return 1;
    }

    std::vector<int> arr2 = {1, 2, 3, 4, 3, 2, 2};
    if (smallest_change(arr2) != 1) {
        std::cout << "Assertion failed: smallest_change([1, 2, 3, 4, 3, 2, 2]) == 1" << std::endl;
        return 1;
    }

    std::vector<int> arr3 = {1, 4, 2};
    if (smallest_change(arr3) != 1) {
        std::cout << "Assertion failed: smallest_change([1, 4, 2]) == 1" << std::endl;
        return 1;
    }

    std::vector<int> arr4 = {1, 4, 4, 2};
    if (smallest_change(arr4) != 1) {
        std::cout << "Assertion failed: smallest_change([1, 4, 4, 2]) == 1" << std::endl;
        return 1;
    }

    std::vector<int> arr5 = {1, 2, 3, 2, 1};
    if (smallest_change(arr5) != 0) {
        std::cout << "Assertion failed: smallest_change([1, 2, 3, 2, 1]) == 0" << std::endl;
        return 1;
    }

    std::vector<int> arr6 = {3, 1, 1, 3};
    if (smallest_change(arr6) != 0) {
        std::cout << "Assertion failed: smallest_change([3, 1, 1, 3]) == 0" << std::endl;
        return 1;
    }

    std::vector<int> arr7 = {1};
    if (smallest_change(arr7) != 0) {
        std::cout << "Assertion failed: smallest_change([1]) == 0" << std::endl;
        return 1;
    }

    std::vector<int> arr8 = {0, 1};
    if (smallest_change(arr8) != 1) {
        std::cout << "Assertion failed: smallest_change([0, 1]) == 1" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}

[C]
#include <stdio.h>
#include <stdlib.h>

int smallest_change(int* arr, int arr_size) {
    int out = 0;
    for (int i = 0; i < arr_size / 2; i++) {
        if (arr[i] != arr[arr_size - 1 - i]) {
            out++;
        }
    }
    return out;
}

int main() {
    int arr1[] = {1, 2, 3, 5, 4, 7, 9, 6};
    if (smallest_change(arr1, 8) != 4) {
        printf("Assertion failed: smallest_change([1, 2, 3, 5, 4, 7, 9, 6]) == 4
");
        return 1;
    }

    int arr2[] = {1, 2, 3, 4, 3, 2, 2};
    if (smallest_change(arr2, 7) != 1) {
        printf("Assertion failed: smallest_change([1, 2, 3, 4, 3, 2, 2]) == 1
");
        return 1;
    }

    int arr3[] = {1, 4, 2};
    if (smallest_change(arr3, 3) != 1) {
        printf("Assertion failed: smallest_change([1, 4, 2]) == 1
");
        return 1;
    }

    int arr4[] = {1, 4, 4, 2};
    if (smallest_change(arr4, 4) != 1) {
        printf("Assertion failed: smallest_change([1, 4, 4, 2]) == 1
");
        return 1;
    }

    int arr5[] = {1, 2, 3, 2, 1};
    if (smallest_change(arr5, 5) != 0) {
        printf("Assertion failed: smallest_change([1, 2, 3, 2, 1]) == 0
");
        return 1;
    }

    int arr6[] = {3, 1, 1, 3};
    if (smallest_change(arr6, 4) != 0) {
        printf("Assertion failed: smallest_change([3, 1, 1, 3]) == 0
");
        return 1;
    }

    int arr7[] = {1};
    if (smallest_change(arr7, 1) != 0) {
        printf("Assertion failed: smallest_change([1]) == 0
");
        return 1;
    }

    int arr8[] = {0, 1};
    if (smallest_change(arr8, 2) != 1) {
        printf("Assertion failed: smallest_change([0, 1]) == 1
");
        return 1;
    }

    printf("All tests passed.
");
    return 0;
}

[Python]
def smallest_change(arr):
    out = 0
    for i in range(len(arr) // 2):
        if arr[i] != arr[len(arr) - 1 - i]:
            out += 1
    return out


def main():
    arr1 = [1, 2, 3, 5, 4, 7, 9, 6]
    if smallest_change(arr1) != 4:
        print("Assertion failed: smallest_change([1, 2, 3, 5, 4, 7, 9, 6]) == 4")
        return 1

    arr2 = [1, 2, 3, 4, 3, 2, 2]
    if smallest_change(arr2) != 1:
        print("Assertion failed: smallest_change([1, 2, 3, 4, 3, 2, 2]) == 1")
        return 1

    arr3 = [1, 4, 2]
    if smallest_change(arr3) != 1:
        print("Assertion failed: smallest_change([1, 4, 2]) == 1")
        return 1

    arr4 = [1, 4, 4, 2]
    if smallest_change(arr4) != 1:
        print("Assertion failed: smallest_change([1, 4, 4, 2]) == 1")
        return 1

    arr5 = [1, 2, 3, 2, 1]
    if smallest_change(arr5) != 0:
        print("Assertion failed: smallest_change([1, 2, 3, 2, 1]) == 0")
        return 1

    arr6 = [3, 1, 1, 3]
    if smallest_
