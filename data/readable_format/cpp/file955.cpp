#include <iostream>

void sortint(int n, int arr[]) {
    for (int i = 1; i < n; i++) {
        int a = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > a) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = a;
    }
}

int main() {
    int testArray[] = {4, 2, 5, 1, 3};
    int n = sizeof(testArray) / sizeof(testArray[0]);

    sortint(n, testArray);

    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << testArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}