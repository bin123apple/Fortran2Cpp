#include <iostream>
#include <vector>

void vecset(int n, std::vector<double>& v, std::vector<int>& iv, int nzv, int i, double val) {
    bool set = false;

    for (int k = 1; k <= nzv; k++) {
        if (iv[k - 1] == i) {
            v[k - 1] = val;
            set = true;
        }
    }

    if (!set) {
        nzv++;
        v.push_back(val);
        iv.push_back(i);
    }
}

int main() {
    int n = 10;
    std::vector<double> v(n);
    std::vector<int> iv;
    int nzv = 0;
    int i = 5;
    double val = 3.14;

    vecset(n, v, iv, nzv, i, val);

    // Print the result
    for (int k = 0; k < v.size(); k++) {
        std::cout << "v[" << k << "] = " << v[k] << std::endl;
    }

    for (int k = 0; k < iv.size(); k++) {
        std::cout << "iv[" << k << "] = " << iv[k] << std::endl;
    }

    return 0;
}
