#include <iostream>
#include <cmath>

using namespace std;

void init_array(int n, double alpha, double** a, double** b) {
    alpha = 32412.0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[j][i] = (double(i - 1) * double(j - 1)) / n;
            b[j][i] = ((double(i - 1) * double(j - 1))) / n;
        }
    }
}

int main() {
    int n = 10; // Change this to your desired value
    double alpha;
    double** a = new double*[n];
    double** b = new double*[n];

    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
        b[i] = new double[n];
    }

    init_array(n, alpha, a, b);

    // Print the arrays
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[j][i] << " ";
        }
        cout << endl;
    }

    // Don't forget to free the memory
    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}
