#include <iostream>
#include <omp.h>

using namespace std;

void gen_task(int i) {
    // implement the logic of gen_task here
}

int main() {
    int a[100];

    #pragma omp parallel
    {
        #pragma omp single
        for (int i = 1; i <= 100; i++) {
            gen_task(i);
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (a[i-1]!= i+1) {
            cout << "warning: a(" << i << ") = " << a[i-1] << " not expected " << i+1 << endl;
        }
        // cout << a[i-1] << " " << i+1 << endl;
    }

    return 0;
}
