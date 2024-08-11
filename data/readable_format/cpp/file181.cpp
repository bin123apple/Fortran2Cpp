#include <iostream>
#include <vector>
#include <iomanip> // For std::setprecision

// Function declaration is optional in this case since we're defining the function before main
void dcdt(std::vector<float>& y, float dt, int npts, int indx1, int indx2, bool ldc, bool ldt) {
    if (!ldc && !ldt) {
        return;
    }

    int nsum = indx2 - indx1 + 1;
    float sumx = 0.0f;
    float sumx2 = 0.0f;
    float sumy = 0.0f;
    float sumxy = 0.0f;
    for (int i = indx1; i <= indx2; ++i) {
        float xsubi = (i - 1) * dt;
        sumxy += xsubi * y[i-1]; // Adjusted for 0-based indexing
        sumx += xsubi;
        sumx2 += xsubi * xsubi;
        sumy += y[i-1]; // Adjusted for 0-based indexing
    }

    if (ldc) {
        float avy = sumy / nsum;
        for (int i = 0; i < npts; ++i) {
            y[i] -= avy;
        }
        std::cout << "Results with ldc = true: ";
        for (auto val : y) std::cout << std::setprecision(4) << val << " ";
        std::cout << std::endl;
        return;
    }

    if (ldt) {
        float bxy = (sumxy - sumx * sumy / nsum) / (sumx2 - sumx * sumx / nsum);
        float axy = (sumy - bxy * sumx) / nsum;
        float qxy = dt * bxy;
        for (int i = 0; i < npts; ++i) {
            y[i] -= (axy + i * qxy);
        }
        std::cout << "Results with ldt = true: ";
        for (auto val : y) std::cout << std::setprecision(4) << val << " ";
        std::cout << std::endl;
        return;
    }
}

int main() {
    std::vector<float> y = {1.0, 2.0, 3.0, 4.0, 5.0};
    float dt = 1.0;
    int npts = 5, indx1 = 1, indx2 = 5;
    bool ldc = true, ldt = false;

    // Test with ldc = true
    dcdt(y, dt, npts, indx1, indx2, ldc, ldt);

    // Reset y for the next test
    y = {1.0, 2.0, 3.0, 4.0, 5.0};
    ldc = false;
    ldt = true;

    // Test with ldt = true
    dcdt(y, dt, npts, indx1, indx2, ldc, ldt);

    return 0;
}