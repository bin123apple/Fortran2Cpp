#include <iostream>
#include <vector>

using namespace std;

int main() {
    int len = 100;
    int x = 10;

    vector<int> a(len);

    #pragma omp parallel for
    for (int i = 0; i < len; i++) {
        a[i] = x;
        x = i;
    }

    cout << "x = " << x << endl;

    return 0;
}
