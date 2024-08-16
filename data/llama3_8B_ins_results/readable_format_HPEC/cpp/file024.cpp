#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int len = 100;
    int a[len][len];

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp for
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    a[i][j] += 1;
                }
            }
        }
    }

    cout << "a(50,50) = " << a[50][50] << endl;

    return 0;
}
