#include <iostream>
#include <vector>
#include <string>

using namespace std;

string exchange(vector<int> lst1, vector<int> lst2) {
    int num = 0;
    for (int i = 0; i < lst1.size(); i++) {
        if (lst1[i] % 2 == 0) num++;
    }
    for (int i = 0; i < lst2.size(); i++) {
        if (lst2[i] % 2 == 0) num++;
    }

    if (num >= lst1.size()) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    vector<int> lst1 = {1, 2, 3, 4};
    vector<int> lst2 = {1, 2, 3, 4};
    cout << exchange(lst1, lst2) << endl;

    lst1 = {1, 2, 3, 4};
    lst2 = {1, 5, 3, 4};
    cout << exchange(lst1, lst2) << endl;

    lst1 = {1, 2, 3, 4};
    lst2 = {2, 1, 4, 3};
    cout << exchange(lst1, lst2) << endl;

    lst1 = {5, 7, 3};
    lst2 = {2, 6, 4};
    cout << exchange(lst1, lst2) << endl;

    lst1 = {5, 7, 3};
    lst2 = {2, 6, 3};
    cout << exchange(lst1, lst2) << endl;

    lst1 = {3, 2, 6, 1, 8, 9};
    lst2 = {3, 5, 5, 1, 1, 1};
    cout << exchange(lst1, lst2) << endl;

    lst1 = {100, 200};
    lst2 = {200, 200};
    cout << exchange(lst1, lst2) << endl;

    return 0;
}

[C]
#include <stdio.h>
#include <stdlib.h>

int is_even(int num) {
    return num % 2 == 0;
}

int count_even(int *arr, int size) {
    int i, count = 0;
    for (i = 0; i < size; i++) {
        if (is_even(arr[i])) count++;
    }
    return count;
}

int is_possible(int *arr1, int size1, int *arr2, int size2) {
    int count = count_even(arr1, size1) + count_even(arr2, size2);
    return count >= size1;
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {1, 2, 3, 4};
    printf("%s
", is_possible(arr1, 4, arr2, 4) ? "YES" : "NO");

    arr1 = (int[]){1, 2, 3, 4};
    arr2 = (int[]){1, 5, 3, 4};
    printf("%s
", is_possible(arr1, 4, arr2, 4) ? "YES" : "NO");

    arr1 = (int[]){1, 2, 3, 4};
    arr2 = (int[]){2, 1, 4, 3};
    printf("%s
", is_possible(arr1, 4, arr2, 4) ? "YES" : "NO");

    arr1 = (int[]){5, 7, 3};
    arr2 = (int[]){2, 6, 4};
    printf("%s
", is_possible(arr1, 3, arr2, 3) ? "YES" : "NO");

    arr1 = (int[]){5, 7, 3};
    arr2 = (int[]){2, 6, 3};
    printf("%s
", is_possible(arr1, 3, arr2, 3) ? "YES" : "NO");

    arr1 = (int[]){3, 2, 6, 1, 8, 9};
    arr2 = (int[]){3, 5, 5, 1, 1, 1};
    printf("%s
", is_possible(arr1, 6, arr2, 6) ? "YES" : "NO");

    arr1 = (int[]){100, 200};
    arr2 = (int[]){200, 200};
    printf("%s
", is_possible(arr1, 2, arr2, 2) ? "YES" : "NO");

    return 0;
}

[Python]
def is_even(num):
    return num % 2 == 0

def count_even(arr):
    count = 0
    for num in arr:
        if is_even(num):
            count += 1
    return count

def is_possible(arr1, arr2):
    count = count_even(arr1) + count_even(arr2)
    return count >= len(arr1)

print(is_possible([1, 2, 3, 4], [1, 2, 3, 4]))
print(is_possible([1, 2, 3, 4], [1, 5, 3, 4]))
print(is_possible([1, 2, 3, 4], [2, 1, 4, 3]))
print(is_possible([5, 7, 3], [2, 6, 4]))
print(is_possible([5, 7, 3], [2, 6, 3]))
print(is_possible([3, 2, 6, 1, 8, 9], [3, 5, 5, 1, 1, 1]))
print(is_possible([100, 200], [200, 200]))

[Java]
import java.util.stream.IntStream;

class Main {
    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4};
        int[] arr2 = {1, 2, 3, 4};
        System.out.println(is_possible(arr1, arr2) ? "YES" : "NO");

        arr1 = new int[] {1, 2, 3, 4};
        arr2 = new int[] {1, 5, 3, 4};
        System.out.println(is_possible(arr1, arr2) ? "YES" : "NO");

        arr1 = new int[] {1, 2, 3, 4};
        arr2 = new int[] {2, 1, 4, 3};
        System.out.println(is_possible(arr1, arr2) ? "YES" : "NO");

        arr1 = new int[] {5, 7, 3};
        arr2 = new int[] {2, 6, 4};
        System.out.println(is_possible(arr1, arr2) ? "YES" : "NO");

        arr1 = new int[] {5, 7, 3};
        arr2 = new int[] {2, 6, 3};
        System.out.println(is_possible(arr1, arr2) ? "YES" : "NO");

        arr1 = new int[] {3, 2, 6, 1, 8, 9};
        arr2 = new int[] {3, 5, 5, 1, 1, 1};
        System.out.println(is_possible(arr1, arr2) ? "YES" : "NO");

        arr1 = new int[] {100, 200};
        arr2 = new int[] {200, 200};
        System.out.println(is_possible(arr1, arr2) ? "YES" : "NO");
    }
