#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int len = 100;
    int a[len][len];

    #pragma omp parallel for ordered
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            a[i][j] = a[i][j] + 1;
            #pragma omp ordered
            cout << "test i = " << i << "  j = " << j << endl;
        }
    }

    return 0;
}
