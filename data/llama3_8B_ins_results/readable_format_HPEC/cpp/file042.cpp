#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void foo(vector<double>& newSxx, vector<double>& newSyy, int len) {
    // your code here
}

int main() {
    int len = 1000;
    double dp = 1.0;

    vector<double> newSxx(len);
    vector<double> newSyy(len);

    #pragma omp parallel
    {
        foo(newSxx, newSyy, len);
    }

    newSxx.clear();
    newSyy.clear();

    return 0;
}
