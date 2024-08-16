#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool issame(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void factorize(int n, vector<int> &out) {
    int m = n;
    int count = 0;
    out.clear();

    for (int i = 2; i <= sqrt(n); i++) {
        if (m <= 1) break;
        while (m % i == 0) {
            m /= i;
            count++;
            out.push_back(i);
        }
    }

    if (m > 1) {
        count++;
        out.push_back(m);
    }
}

int main() {
    vector<int> factors;
    bool result;

    factorize(2, factors);
    result = issame(factors, vector<int>{2});
    if (!result) {
        cout << "Assertion failed for factorize(2)" << endl;
        return 1;
    }

    factorize(4, factors);
    result = issame(factors, vector<int>{2, 2});
    if (!result) {
        cout << "Assertion failed for factorize(4)" << endl;
        return 1;
    }

    factorize(8, factors);
    result = issame(factors, vector<int>{2, 2, 2});
    if (!result) {
        cout << "Assertion failed for factorize(8)" << endl;
        return 1;
    }

    factorize(3 * 19, factors);
    result = issame(factors, vector<int>{3, 19});
    if (!result) {
        cout << "Assertion failed for factorize(3 * 19)" << endl;
        return 1;
    }

    factorize(3 * 19 * 3 * 19, factors);
    result = issame(factors, vector<int>{3, 3, 19, 19});
    if (!result) {
        cout << "Assertion failed for factorize(3 * 19 * 3 * 19)" << endl;
        return 1;
    }

    factorize(3 * 19 * 3 * 19 * 3 * 19, factors);
    result = issame(factors, vector<int>{3, 3, 3, 19, 19, 19});
    if (!result) {
        cout << "Assertion failed for factorize(3 * 19 * 3 * 19 * 3 * 19)" << endl;
        return 1;
    }

    factorize(3 * 19 * 19 * 19, factors);
    result = issame(factors, vector<int>{3, 19, 19, 19});
    if (!result) {
        cout << "Assertion failed for factorize(3 * 19 * 19 * 19)" << endl;
        return 1;
    }

    factorize(3 * 2 * 3, factors);
    result = issame(factors, vector<int>{2, 3, 3});
    if (!result) {
        cout << "Assertion failed for factorize(3 * 2 * 3)" << endl;
        return 1;
    }

    return 0;
}

[C]
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool issame(int *a, int *b, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void factorize(int n, int *out, int *size) {
    int m = n;
    int count = 0;
    *size = 0;

    for (int i = 2; i <= sqrt(n); i++) {
        if (m <= 1) break;
        while (m % i == 0) {
            m /= i;
            count++;
            out[*size] = i;
            *size = *size + 1;
        }
    }

    if (m > 1) {
        count++;
        out[*size] = m;
        *size = *size + 1;
    }
}

int main() {
    int factors[100];
    int size;
    bool result;

    factorize(2, factors, &size);
    result = issame(factors, (int[]){2}, size);
    if (!result) {
        printf("Assertion failed for factorize(2)
");
        return 1;
    }

    factorize(4, factors, &size);
    result = issame(factors, (int[]){2, 2}, size);
    if (!result) {
        printf("Assertion failed for factorize(4)
");
        return 1;
    }

    factorize(8, factors, &size);
    result = issame(factors, (int[]){2, 2, 2}, size);
    if (!result) {
        printf("Assertion failed for factorize(8)
");
        return 1;
    }

    factorize(3 * 19, factors, &size);
    result = issame(factors, (int[]){3, 19}, size);
    if (!result) {
        printf("Assertion failed for factorize(3 * 19)
");
        return 1;
    }

    factorize(3 * 19 * 3 * 19, factors, &size);
    result = issame(factors, (int[]){3, 3, 19, 19}, size);
    if (!result) {
        printf("Assertion failed for factorize(3 * 19 * 3 * 19)
");
        return 1;
    }

    factorize(3 * 19 * 3 * 19 * 3 * 19, factors, &size);
    result = issame(factors, (int[]){3, 3, 3, 19, 19, 19}, size);
    if (!result) {
        printf("Assertion failed for factorize(3 * 19 * 3 * 19 * 3 * 19)
");
        return 1;
    }

    factorize(3 * 19 * 19 * 19, factors, &size);
    result = issame(factors, (int[]){3, 19, 19, 19}, size);
    if (!result) {
        printf("Assertion failed for factorize(3 * 19 * 19 * 19)
");
        return 1;
    }

    factorize(3 * 2 * 3, factors, &size);
    result = issame(factors, (int[]){2, 3, 3}, size);
    if (!result) {
        printf("Assertion failed for factorize(3 * 2 * 3)
");
        return 1;
    }

    return 0;
}

[Python]
def issame(a, b):
    return a == b

def factorize(n):
    m = n
    factors = []

    for i in range(2, int(n ** 0.5) + 1):
        if m <= 1:
            break
        while m % i == 0:
            m //= i
            factors.append(i)

    if m > 1:
        factors.append(m)

    return factors

def main():
    assert issame(factorize(2), [2])
    assert issame(factorize(4), [2, 2])
    assert issame(factorize(8), [2, 2, 2])
