#include <iostream>
#include <omp.h>

using namespace std;

void foo(int* a, int n, int m) {
    // implement foo function here
}

int main() {
    int* a = new int[100];
    foo(a, 100, 7);
    cout << a[50] << endl;
    delete[] a;
    return 0;
}
