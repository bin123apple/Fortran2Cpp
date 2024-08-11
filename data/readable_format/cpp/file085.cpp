#include <iostream>
#include <vector>
#include <cassert>

void dqpsrt(int limit, int& last, int& maxerr, double& ermax, std::vector<double>& elist, std::vector<int>& iord, int& nrmax) {
    double errmax, errmin;
    int i, ibeg, ido, isucc, j, jbnd, jupbn, k;

    if (last <= 2) {
        iord[0] = 1;
        iord[1] = 2;
        return;
    }

    errmax = elist[maxerr - 1];
    if (nrmax != 1) {
        ido = nrmax - 1;
        for (i = 1; i <= ido; ++i) {
            isucc = iord[nrmax - 2];
            if (errmax <= elist[isucc - 1]) break;
            iord[nrmax - 1] = isucc;
            nrmax--;
        }
    }

    jupbn = last;
    if (last > (limit / 2 + 2)) jupbn = limit + 3 - last;
    errmin = elist[last - 1];
    jbnd = jupbn - 1;
    ibeg = nrmax + 1;
    if (ibeg <= jbnd) {
        for (i = ibeg; i <= jbnd; ++i) {
            isucc = iord[i - 1];
            if (errmax >= elist[isucc - 1]) break;
            iord[i - 2] = isucc;
        }
    } else {
        i = jbnd + 2; // Simulate 'goto 50' by setting i for the next condition
    }

    if (i > jbnd + 1) {
        iord[jbnd - 1] = maxerr;
        iord[jupbn - 1] = last;
    } else {
        iord[i - 2] = maxerr;
        k = jbnd;
        for (j = i; j <= jbnd; ++j) {
            isucc = iord[k - 1];
            if (errmin < elist[isucc - 1]) break;
            iord[k] = isucc;
            k = k - 1;
        }
        iord[i - 1] = last;
    }

    maxerr = iord[nrmax - 1];
    ermax = elist[maxerr - 1];
}

int main() {
    int limit = 10;
    int last = 5;
    int maxerr = 2;
    double ermax = 0.0;
    std::vector<double> elist = {0.1, 0.2, 0.05, 0.3, 0.25};
    std::vector<int> iord = {1, 2, 3, 4, 5};
    int nrmax = 1;

    dqpsrt(limit, last, maxerr, ermax, elist, iord, nrmax);

    // Output the results for visual verification
    std::cout << "maxerr: " << maxerr << std::endl;
    std::cout << "ermax: " << ermax << std::endl;
    std::cout << "nrmax: " << nrmax << std::endl;
    std::cout << "iord: ";
    for (const auto& val : iord) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}