#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function to calculate average, RMS, and maximum value of a vector
void averms(const std::vector<float>& x, float& ave, float& rms, float& xmax) {
    int npts = x.size();
    if (npts == 0) {
        ave = 0;
        rms = 0;
        xmax = 0;
        return;
    }
    
    float s = 0.0f;
    xmax = x[0];
    for (int i = 0; i < npts; ++i) {
        s += x[i];
        xmax = std::max(xmax, std::abs(x[i]));
    }
    ave = s / npts;
    
    float sq = 0.0f;
    for (int i = 0; i < npts; ++i) {
        sq += (x[i] - ave) * (x[i] - ave);
    }
    rms = std::sqrt(sq / (npts - 1));
}

int main() {
    // Sample data
    std::vector<float> x = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    float ave, rms, xmax;

    // Calculate average, RMS, and maximum
    averms(x, ave, rms, xmax);

    // Display the results
    std::cout << "Average: " << ave << std::endl;
    std::cout << "RMS: " << rms << std::endl;
    std::cout << "Maximum: " << xmax << std::endl;

    // Expected output:
    // Average: 3.0
    // RMS: 1.58114 (approximately, depending on precision)
    // Maximum: 5.0

    return 0;
}