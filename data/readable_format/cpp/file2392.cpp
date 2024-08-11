#include <cmath>  // for log and pow functions
#include <iostream>

void get_npw2(int npts, double signnpw2, int &npw2) {
    int npw2_exp = static_cast<int>(std::log(static_cast<double>(npts)) / std::log(2.0));
    if (signnpw2 < 0.0) {
        npw2 = static_cast<int>(std::pow(2.0, npw2_exp));
    } else {
        int npw2_temp = static_cast<int>(std::pow(2.0, npw2_exp));
        if (npw2_temp == npts) {
            npw2 = npts;
        } else {
            npw2 = static_cast<int>(std::pow(2.0, npw2_exp + 1));
        }
    }
}

int main() {
    int npts = 10;
    double signnpw2 = 1.0;
    int npw2;

    get_npw2(npts, signnpw2, npw2);

    std::cout << "npw2: " << npw2 << std::endl;

    return 0;
}