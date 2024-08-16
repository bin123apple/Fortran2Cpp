#include <vector>

void vecset(int n, std::vector<double>& v, std::vector<int>& iv, int& nzv, int i, double val) {
    bool set = false;
    for (int k = 0; k < nzv; ++k) {
        if (iv[k] == i) {
            v[k] = val;
            set = true;
        }
    }
    if (!set) {
        iv.push_back(i);
        v.push_back(val);
        ++nzv;
    }
}
