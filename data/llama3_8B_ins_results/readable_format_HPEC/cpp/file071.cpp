#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

int main() {
    const int n = 180;
    vector<double> base(2025);
    vector<double> xa1(2025);
    vector<double> xa2(2025);

    for (int i = 521; i <= 2025; i++) {
        base[i - 1] = 0.5 * i;
    }

    #pragma omp parallel for schedule(static, 1)
    for (int i = 0; i < n; i++) {
        int idx1 = indexSet[i];
        int idx2 = indexSet[i] + 12;
        base[idx1 - 1] += 1.0;
        base[idx2 - 1] += 3.0;
    }

    cout << "xa1(999) = " << base[998] << " xa2(1285) = " << base[1284] << endl;

    xa1.clear();
    xa2.clear();

    return 0;
}
