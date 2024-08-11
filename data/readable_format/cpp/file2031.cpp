#include <iostream>
#include <vector>
#include <cmath>
#include <string>

// Global variables
int npole = 1;
std::vector<std::string> polaxe = {"Z-then-X"};
std::vector<int> yaxis = {1};
std::vector<int> ipole = {1}, zaxis = {2}, xaxis = {3};
std::vector<double> x = {0.0, 1.0, -1.0}, y = {0.0, 0.0, 0.0}, z = {0.0, 0.0, 0.0};

void chkpole() {
    for (int i = 0; i < npole; ++i) {
        bool check = true;
        if (polaxe[i] != "Z-then-X") check = false;
        if (yaxis[i] == 0) check = false;
        if (check) {
            int k = yaxis[i];
            int ia = ipole[i]-1, ib = zaxis[i]-1, ic = xaxis[i]-1, id = abs(k)-1;

            double xad = x[ia] - x[id], yad = y[ia] - y[id], zad = z[ia] - z[id];
            double xbd = x[ib] - x[id], ybd = y[ib] - y[id], zbd = z[ib] - z[id];
            double xcd = x[ic] - x[id], ycd = y[ic] - y[id], zcd = z[ic] - z[id];
            double c1 = ybd*zcd - zbd*ycd, c2 = zbd*xcd - xbd*zcd, c3 = xbd*ycd - ybd*xcd;
            double vol = xad*c1 + yad*c2 + zad*c3;

            if ((k < 0 && vol > 0.0) || (k > 0 && vol < 0.0)) {
                yaxis[i] = -k;
            }
        }
    }
}

int main() {
    chkpole();

    if (yaxis[0] == -1) {
        std::cout << "C++ Test passed." << std::endl;
    } else {
        std::cout << "C++ Test failed." << std::endl;
    }

    return 0;
}