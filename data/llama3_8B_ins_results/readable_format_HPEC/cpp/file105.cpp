#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    double x = 1.0;
    int y = 1;

    #pragma omp parallel
    {
        #pragma omp single
        {
            x = 1.0;
            y = 1;
        }
        #pragma omp end single
        #pragma omp copyprivate(x, y)
    }

    cout << "x = " << fixed << setprecision(3) << x << " y = " << y << endl;

    return 0;
}
