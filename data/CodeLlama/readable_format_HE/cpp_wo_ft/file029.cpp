#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> input = {5, 3, 5, 2, 3, 3, 9, 0, 123};
    std::vector<int> expected = {0, 2, 3, 5, 9, 123};
    std::vector<int> result;
    bool is_same;

    // Call the unique function
    unique(input, result);

    // Check if the result is the same as expected
    is_same = issame(result, expected);
    if (!is_same) {
        std::cout << "Assertion failed: result is not as expected" << std::endl;
        return 1;
    }

    return 0;
}

void unique(const std::vector<int>& l, std::vector<int>& out) {
    std::vector<int> temp;
    int count = 0;

    // Remove duplicates
    for (int i = 0; i < l.size(); i++) {
        if (std::find(temp.begin(), temp.end(), l[i]) == temp.end()) {
            count++;
            temp.push_back(l[i]);
        }
    }

    // Allocate output array with the correct size
    out.resize(count);
    out = temp;

    // Sort the output array
    std::sort(out.begin(), out.end());
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
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

[C]
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

bool issame(int *a, int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

int *unique(int *l, int size, int *out_size) {
    int *temp = malloc(sizeof(int) * size);
    int count = 0;

    // Remove duplicates
    for (int i = 0; i < size; i++) {
        if (!contains(temp, count, l[i])) {
            count++;
            temp[count - 1] = l[i];
        }
    }

    // Allocate output array with the correct size
    *out_size = count;
    int *out = malloc(sizeof(int) * count);
    memcpy(out, temp, sizeof(int) * count);

    // Sort the output array
    qsort(out, count, sizeof(int), compare_int);

    return out;
}

bool contains(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }

    return false;
}

int main() {
    int input[] = {5, 3, 5, 2, 3, 3, 9, 0, 123};
    int expected[] = {0, 2, 3, 5, 9, 123};
    int *result;
    int result_size;
    bool is_same;

    // Call the unique function
    result = unique(input, sizeof(input) / sizeof(int), &result_size);

    // Check if the result is the same as expected
    is_same = issame(result, expected, result_size);
    if (!is_same) {
        printf("Assertion failed: result is not as expected
");
        return 1;
    }

    return 0;
}

[Python]
def unique(l):
    temp = []
    count = 0

    # Remove duplicates
    for i in l:
        if i not in temp:
            count += 1
            temp.append(i)

    # Allocate output array with the correct size
    out = [0] * count
    for i in range(count):
        out[i] = temp[i]

    # Sort the output array
    out.sort()
    return out

def issame(a, b):
    if len(a) != len(b):
        return False

    for i in range(len(a)):
        if a[i] != b[i]:
            return False

    return True

def main():
    input = [5, 3, 5, 2, 3, 3, 9, 0, 123]
    expected = [0, 2, 3, 5, 9, 123]
    result = unique(input)

    # Check if the result is the same as expected
    is_same = issame(result, expected)
    if not is_same:
        print("Assertion failed: result is not as expected")
        exit(1)

if __name__ == "__main__":
    main()

[Java]
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] input = new int[] {5, 3, 5, 2, 3, 3, 9, 0, 123};
        int[] expected = new int[] {0, 2, 3, 5, 9, 123};
        int[] result = unique(input);

        // Check if the result is the same as expected
        if (!issame(result, expected)) {
            System.out.println("Assertion failed: result is not as expected");
            System.exit(1);
        }
    }

    public static int[] unique(int[] l) {
        int[] temp = new int[l.length];
        int count = 0;

        // Remove duplicates
        for (int i = 0; i < l.length; i++) {
            if (!contains(temp, count, l[i])) {
                count++;
                temp[count - 1] = l[i];
            }
        }

        // Allocate output array with the correct size
        int[] out = new int[count];
        for (int i = 0; i < count; i++) {
            out[i] = temp[i];
        }

        // Sort the output array
        Arrays.sort(out);
        return out;
    }

    public static boolean contains(int[] arr, int size, int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return true;
            }
        }

        return false;
    }

    public static boolean issame(int[] a, int[] b) {
        if (a.length != b.length) {
            return false;
        }

        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }
}

[JavaScript]
function unique(l) {
    let temp = [];
    let count = 0;

    // Remove duplicates
    for (let i = 0; i < l.length; i++) {
        if (!contains(temp, count, l[i])) {
            count++;
            temp.push(l[i]);
        }
    }

    // Allocate output array with the correct size
    let out = new Array(count);
    for (let i = 0; i < count; i++) {
        out[i] = temp[i];
    }

    // Sort the output array
    out.sort((a, b) => a - b);
