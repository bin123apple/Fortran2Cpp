#include <vector>
#include <iostream>

void mapev(int nold, int nnew, int nvar, const std::vector<int>& map, std::vector<float>& vars, std::vector<float>& scr) {
    for (int ivar = 0; ivar < nvar; ++ivar) {
        for (int i = 0; i < nnew; ++i) {
            scr[i] = vars[(map[i] - 1) + nold * ivar]; // Fixed indexing
        }
        
        for (int i = 0; i < nnew; ++i) {
            vars[i + nnew * ivar] = scr[i]; // Corrected logic to match Fortran behavior
        }
    }
}

int main() {
    int nold = 2, nnew = 3, nvar = 2;
    std::vector<int> map = {1, 2, 3};
    std::vector<float> vars = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<float> scr(nnew);

    mapev(nold, nnew, nvar, map, vars, scr);

    std::cout << "Vars:" << std::endl;
    for (int i = 0; i < vars.size(); i++) {
        std::cout << "vars(" << i + 1 << ") = " << vars[i] << std::endl;
    }

    return 0;
}