#include <iostream>
#include <vector>

class my_mod {
public:
    static int my_func() {
        return 10;
    }
};

void workshare(std::vector<float>& aa, std::vector<float>& bb, std::vector<float>& cc,
               std::vector<float>& dd, std::vector<float>& ee, std::vector<float>& ff, int n) {
    aa.assign(n, my_mod::my_func());
    cc = dd;
    ee = ff;

    for (int i = 0; i < n; ++i) {
        if (aa[i] != static_cast<float>(my_mod::my_func())) aa[i] = bb[i] * cc[i];
        if (dd[i] < 5) dd[i] = aa[i] * my_mod::my_func();
        if (aa[i] >= static_cast<float>(my_mod::my_func())) cc[i] = aa[i] + my_mod::my_func();
        if (aa[i] <= static_cast<float>(my_mod::my_func())) cc[i] = dd[i] + my_mod::my_func();
    }

    for (int i = 0; i < n && i < my_mod::my_func(); ++i) {
        aa[i] += bb[i];
    }
}

int main() {
    const int n = 10;
    std::vector<float> aa(n), bb(n), cc(n), dd(n), ee(n), ff(n);

    for (int i = 0; i < n; ++i) {
        bb[i] = static_cast<float>(i + 1) * 2.0f;
        dd[i] = static_cast<float>(i + 1) * 3.0f;
        ff[i] = static_cast<float>(i + 1) * 4.0f;
    }

    workshare(aa, bb, cc, dd, ee, ff, n);

    std::cout << "Results:" << std::endl;
    std::cout << "aa:";
    for (const auto& val : aa) std::cout << " " << val;
    std::cout << std::endl << "cc:";
    for (const auto& val : cc) std::cout << " " << val;
    std::cout << std::endl << "dd:";
    for (const auto& val : dd) std::cout << " " << val;
    std::cout << std::endl;

    return 0;
}