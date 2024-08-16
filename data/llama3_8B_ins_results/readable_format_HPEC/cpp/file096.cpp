#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int i = 0;
    int sum = 0;

    #pragma omp parallel reduction(+:sum) num_threads(10) private(i)
    {
        i = 0;
        callF1(i);
        sum += i;
    }

    if (sum!= 10) {
        cout << "sum = " << sum << endl;
    }

    return 0;
}
