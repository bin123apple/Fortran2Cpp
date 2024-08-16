#include <iostream>
#include <vector>

using namespace std;

vector<double> get_positive(vector<double> l) {
    vector<double> out;
    for (int i = 0; i < l.size(); i++) {
        if (l[i] > 0.0) {
            out.push_back(l[i]);
        }
    }
    return out;
}

bool issame(vector<double> a, vector<double> b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (abs(a[i] - b[i]) > 1.0e-4) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<double> input = {-1.0, -2.0, 4.0, 5.0, 6.0};
    vector<double> expected = {4.0, 5.0, 6.0};
    vector<double> result = get_positive(input);
    bool is_same = issame(result, expected);
    if (!is_same) {
        cout << "Test case 1: assertion failed" << endl;
        return 1;
    }

    input = {5.0, 3.0, -5.0, 2.0, 3.0, 3.0, 9.0, 0.0, 123.0, 1.0, -10.0};
    expected = {5.0, 3.0, 2.0, 3.0, 3.0, 9.0, 123.0, 1.0};
    result = get_positive(input);
    is_same = issame(result, expected);
    if (!is_same) {
        cout << "Test case 2: assertion failed" << endl;
        return 1;
    }

    input = {-1.0, -2.0};
    expected.clear();
    result = get_positive(input);
    is_same = issame(result, expected);
    if (!is_same) {
        cout << "Test case 3: assertion failed" << endl;
        return 1;
    }

    input.clear();
    expected.clear();
    result = get_positive(input);
    is_same = issame(result, expected);
    if (!is_same) {
        cout << "Test case 4: assertion failed" << endl;
        return 1;
    }

    cout << "All tests passed" << endl;
    return 0;
} [/CPP]

[C]
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

double *get_positive(double *l, int size) {
    double *out = malloc(size * sizeof(double));
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (l[i] > 0.0) {
            out[count] = l[i];
            count++;
        }
    }
    return out;
}

bool issame(double *a, double *b, int size) {
    for (int i = 0; i < size; i++) {
        if (fabs(a[i] - b[i]) > 1.0e-4) {
            return false;
        }
    }
    return true;
}

int main() {
    double input[] = {-1.0, -2.0, 4.0, 5.0, 6.0};
    double expected[] = {4.0, 5.0, 6.0};
    double *result = get_positive(input, 5);
    bool is_same = issame(result, expected, 3);
    if (!is_same) {
        printf("Test case 1: assertion failed
");
        return 1;
    }

    double input2[] = {5.0, 3.0, -5.0, 2.0, 3.0, 3.0, 9.0, 0.0, 123.0, 1.0, -10.0};
    double expected2[] = {5.0, 3.0, 2.0, 3.0, 3.0, 9.0, 123.0, 1.0};
    double *result2 = get_positive(input2, 11);
    is_same = issame(result2, expected2, 8);
    if (!is_same) {
        printf("Test case 2: assertion failed
");
        return 1;
    }

    double input3[] = {-1.0, -2.0};
    double *expected3 = malloc(0);
    double *result3 = get_positive(input3, 2);
    is_same = issame(result3, expected3, 0);
    if (!is_same) {
        printf("Test case 3: assertion failed
");
        return 1;
    }

    double *input4 = malloc(0);
    double *expected4 = malloc(0);
    double *result4 = get_positive(input4, 0);
    is_same = issame(result4, expected4, 0);
    if (!is_same) {
        printf("Test case 4: assertion failed
");
        return 1;
    }

    printf("All tests passed
");
    return 0;
} [/C]

[JAVA]
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static double[] getPositive(double[] l) {
        List<Double> out = new ArrayList<>();
        for (double v : l) {
            if (v > 0.0) {
                out.add(v);
            }
        }
        double[] result = new double[out.size()];
        for (int i = 0; i < out.size(); i++) {
            result[i] = out.get(i);
        }
        return result;
    }

    public static boolean isSame(double[] a, double[] b) {
        if (a.length != b.length) {
            return false;
        }

        for (int i = 0; i < a.length; i++) {
            if (Math.abs(a[i] - b[i]) > 1.0e-4) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        double[] input = {-1.0, -2.0, 4.0, 5.0, 6.0};
        double[] expected = {4.0, 5.0, 6.0};
        double[] result = getPositive(input);
        boolean isSame = isSame(result, expected);
        if (!isSame) {
            System.out.println("Test case 1: assertion failed");
            System.exit(1);
        }

        input = new double[] {5.0, 3.0, -5.0, 2.0, 3.0, 3.0, 9.0, 0.0, 123.0, 1.0, -10.0};
        expected = new double[] {5.0, 3.0, 2.0, 3.0, 3.0, 9.0, 123.0, 1.0};
        result = getPositive(input);
        isSame = isSame(result, expected);
        if (!isSame) {
            System.out.println("Test case 2: assertion failed");
            System.exit(1);
        }

        input = new double[] {-1.0, -2.0};
        expected = new double[] {};
        result = getPositive(input);
        isSame = isSame(result, expected);
        if (!isSame) {
            System
