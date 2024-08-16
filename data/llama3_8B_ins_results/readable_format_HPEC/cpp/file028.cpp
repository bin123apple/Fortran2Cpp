#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    int i = 0;
    int j, k;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                this_thread::sleep_for(chrono::seconds(3));
                i = 1;
            }
            #pragma omp task depend(in:i)
            {
                j = i;
            }
            #pragma omp task depend(in:i)
            {
                k = i;
            }
        }
    }

    cout << "j = " << j << " k = " << k << endl;

    if (j!= 1 || k!= 1) {
        cout << "Race Condition" << endl;
    }

    return 0;
}
