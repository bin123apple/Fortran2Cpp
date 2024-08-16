#include <iostream>
#include <omp.h>

using namespace std;

void foo() {
    int x = 0, y = 2;

    #pragma omp parallel
    {
        #pragma omp single
        {
            x = x + 1;  // 1st Child Task
        }

        #pragma omp task shared(y)
        {
            y = y - x;  // 2nd child task
        }

        #pragma omp taskwait depend(in: x)  // 1st taskwait
        #pragma omp taskwait  // 2nd taskwait
    }

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            foo();
        }
    }
    return 0;
}
