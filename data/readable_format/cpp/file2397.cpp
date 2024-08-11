#include <vector>
#include <iostream>
#include <cmath>

void interv(const std::vector<double>& xt, int lxt, double x, int& left, int& mflag) {
    int ilo = 1;
    int ihi = ilo + 1;
    int istep, middle;

    if (ihi >= lxt) {
        if (x >= xt[lxt - 1]) {
            goto case_110;
        }
        if (lxt <= 1) {
            goto case_90;
        }
        ilo = lxt - 1;
        ihi = lxt;
    }
    if (x >= xt[ihi - 1]) {
        goto case_40;
    }
    if (x >= xt[ilo - 1]) {
        goto case_100;
    }
    istep = 1;
    while (true) {
        ihi = ilo;
        ilo = ihi - istep;
        if (ilo <= 1) {
            goto case_35;
        }
        if (x >= xt[ilo - 1]) {
            goto case_50;
        }
        istep *= 2;
    }
case_35:
    ilo = 1;
    if (x < xt[0]) {
        goto case_90;
    }
    goto case_50;
case_40:
    istep = 1;
    while (true) {
        ilo = ihi;
        ihi = ilo + istep;
        if (ihi >= lxt) {
            goto case_45;
        }
        if (x < xt[ihi - 1]) {
            goto case_50;
        }
        istep *= 2;
    }
case_45:
    if (x >= xt[lxt - 1]) {
        goto case_110;
    }
    ihi = lxt;
case_50:
    while (true) {
        middle = (ilo + ihi) / 2;
        if (middle == ilo) {
            goto case_100;
        }
        if (x < xt[middle - 1]) {
            ihi = middle;
        } else {
            ilo = middle;
        }
    }
case_90:
    mflag = -1;
    left = 1;
    return;
case_100:
    mflag = 0;
    left = ilo;
    return;
case_110:
    mflag = 1;
    if (x == xt[lxt - 1]) {
        mflag = 0;
    }
    left = lxt;
    while (left != 1) {
        left -= 1;
        if (xt[left - 1] < xt[lxt - 1]) {
            return;
        }
    }
    return;
}

int main() {
    std::vector<double> xt = {1.0, 2.0, 3.0, 4.0, 5.0}; // Example data
    int lxt = xt.size();
    double x = 3.5; // Example input
    int left = 0;
    int mflag = 0;
    
    interv(xt, lxt, x, left, mflag);
    
    std::cout << "left: " << left << ", mflag: " << mflag << std::endl;
    
    return 0;
}