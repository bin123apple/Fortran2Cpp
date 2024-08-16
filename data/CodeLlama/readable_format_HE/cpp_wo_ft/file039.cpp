#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sort(vector<double> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double median(vector<double> arr) {
    sort(arr);
    int n = arr.size();

    if (n % 2 == 1) {
        return arr[n / 2];
    } else {
        return (arr[n / 2] + arr[n / 2 + 1]) / 2.0;
    }
}

int main() {
    // Test cases
    double result = median({3.0, 1.0, 2.0, 4.0, 5.0});
    if (abs(result - 3.0) > 1e-4) {
        cout << "Test case 1 failed: assertion failed" << endl;
        return 1;
    }

    result = median({-10.0, 4.0, 6.0, 1000.0, 10.0, 20.0});
    if (abs(result - 8.0) > 1e-4) {
        cout << "Test case 2 failed: assertion failed" << endl;
        return 1;
    }

    result = median({5.0});
    if (abs(result - 5.0) > 1e-4) {
        cout << "Test case 3 failed: assertion failed" << endl;
        return 1;
    }

    result = median({6.0, 5.0});
    if (abs(result - 5.5) > 1e-4) {
        cout << "Test case 4 failed: assertion failed" << endl;
        return 1;
    }

    result = median({8.0, 1.0, 3.0, 9.0, 9.0, 2.0, 7.0});
    if (abs(result - 7.0) > 1e-4) {
        cout << "Test case 5 failed: assertion failed" << endl;
        return 1;
    }

    cout << "All test cases passed." << endl;
    return 0;
}
[/CPP]

[C]
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define swap(a, b) { double temp = a; a = b; b = temp; }

void sort(double *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

double median(double *arr, int n) {
    sort(arr, n);

    if (n % 2 == 1) {
        return arr[n / 2];
    } else {
        return (arr[n / 2] + arr[n / 2 + 1]) / 2.0;
    }
}

int main() {
    // Test cases
    double result = median((double[]){3.0, 1.0, 2.0, 4.0, 5.0}, 5);
    if (fabs(result - 3.0) > 1e-4) {
        printf("Test case 1 failed: assertion failed
");
        return 1;
    }

    result = median((double[]){-10.0, 4.0, 6.0, 1000.0, 10.0, 20.0}, 6);
    if (fabs(result - 8.0) > 1e-4) {
        printf("Test case 2 failed: assertion failed
");
        return 1;
    }

    result = median((double[]){5.0}, 1);
    if (fabs(result - 5.0) > 1e-4) {
        printf("Test case 3 failed: assertion failed
");
        return 1;
    }

    result = median((double[]){6.0, 5.0}, 2);
    if (fabs(result - 5.5) > 1e-4) {
        printf("Test case 4 failed: assertion failed
");
        return 1;
    }

    result = median((double[]){8.0, 1.0, 3.0, 9.0, 9.0, 2.0, 7.0}, 7);
    if (fabs(result - 7.0) > 1e-4) {
        printf("Test case 5 failed: assertion failed
");
        return 1;
    }

    printf("All test cases passed.
");
    return 0;
}
[/C]

[JAVA]
import java.util.Arrays;

public class Median {
    public static void sort(double[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]) {
                    double temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    public static double median(double[] arr) {
        sort(arr);
        int n = arr.length;

        if (n % 2 == 1) {
            return arr[n / 2];
        } else {
            return (arr[n / 2] + arr[n / 2 + 1]) / 2.0;
        }
    }

    public static void main(String[] args) {
        // Test cases
        double result = median(new double[]{3.0, 1.0, 2.0, 4.0, 5.0});
        if (Math.abs(result - 3.0) > 1e-4) {
            System.out.println("Test case 1 failed: assertion failed");
            System.exit(1);
        }

        result = median(new double[]{-10.0, 4.0, 6.0, 1000.0, 10.0, 20.0});
        if (Math.abs(result - 8.0) > 1e-4) {
            System.out.println("Test case 2 failed: assertion failed");
            System.exit(1);
        }

        result = median(new double[]{5.0});
        if (Math.abs(result - 5.0) > 1e-4) {
            System.out.println("Test case 3 failed: assertion failed");
            System.exit(1);
        }

        result = median(new double[]{6.0, 5.0});
        if (Math.abs(result - 5.5) > 1e-4) {
            System.out.println("Test case 4 failed: assertion failed");
            System.exit(1);
        }

        result = median(new double[]{8.0, 1.0, 3.0, 9.0, 9.0, 2.0, 7.0});
        if (Math.abs(result - 7.0) > 1e-4) {
            System.out.println("Test case 5 failed: assertion failed");
            System.exit(1);
        }

        System.out.println("All test cases passed.");
    }
}
[/JAVA]

[PYTHON]
def sort(arr):
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if arr[i] > arr[j]:
