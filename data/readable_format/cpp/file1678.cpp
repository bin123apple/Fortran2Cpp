#include <iostream>
#include <vector>

using TINTEGER = int;
using TREAL = double;

void fpchec(TREAL* x, TINTEGER m, TREAL* t, TINTEGER n, TINTEGER k, TINTEGER& ier) {
    TINTEGER k1 = k + 1;
    TINTEGER k2 = k1 + 1;
    TINTEGER nk1 = n - k1;
    TINTEGER nk2 = nk1 + 1;
    TINTEGER nk3, i, j, l;
    TREAL tj, tl;

    ier = 10;
    if (nk1 < k1 || nk1 > m) return;
    
    j = n - 1; // Adjusted for 0-based indexing
    for (i = 0; i < k; ++i) {
        if (t[i] > t[i+1] || t[j] < t[j-1]) return;
        --j;
    }

    for (i = k2 - 1; i < nk2; ++i) {
        if (t[i] <= t[i-1]) return;
    }

    if (x[0] < t[k1 - 1] || x[m-1] > t[nk2 - 1]) return;
    if (x[0] >= t[k2 - 1] || x[m-1] <= t[nk1 - 1]) return;

    i = 0;
    l = k2;
    nk3 = nk1 - 1;
    if (nk3 < 2) {
        ier = 0;
        return;
    }

    for (j = 1; j <= nk3; ++j) { // Adjusted loop to match Fortran logic
        tj = t[j];
        tl = t[l];
        do {
            i++;
            if (i >= m) return;
        } while (x[i] <= tj);
        if (x[i] >= tl) return;
        l++;
    }

    ier = 0;
}

int main() {
    // Test case setup
    std::vector<TREAL> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<TREAL> t = {0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0};
    TINTEGER m = x.size();
    TINTEGER n = t.size();
    TINTEGER k = 2;
    TINTEGER ier;

    // Call the function
    fpchec(x.data(), m, t.data(), n, k, ier);

    // Output the result
    std::cout << "Test 1: ier = " << ier << std::endl;

    return 0;
}