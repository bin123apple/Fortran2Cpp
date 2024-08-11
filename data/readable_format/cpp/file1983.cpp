#include <iostream>
#include <vector>

// Function to perform linear interpolation
float xinterp(float x1, float x2, float y1, float y2, float xval) {
    if (xval <= x1) {
        return y1;
    } else if (xval >= x2) {
        return y2;
    } else if (x2 == x1) {
        return (y1 + y2) / 2.0f;
    } else {
        float frac = (xval - x1) / (x2 - x1);
        return (1.0f - frac) * y1 + frac * y2;
    }
}

// Subroutine for linear interpolation across two sets of points
void lininterp(const std::vector<float>& x1, const std::vector<float>& y1,
               std::vector<float>& x2, std::vector<float>& y2) {
    int i1 = 0;
    int j2 = 0;
    int n1 = x1.size();
    int n2 = x2.size();

    while (j2 < n2) {
        if (x2[j2] < x1[i1]) {
            y2[j2] = y1[i1];
            ++j2;
        } else if (x2[j2] > x1[i1]) {
            if (i1 + 1 < n1 && x2[j2] <= x1[i1 + 1]) {
                y2[j2] = xinterp(x1[i1], x1[i1 + 1], y1[i1], y1[i1 + 1], x2[j2]);
                ++j2;
            } else {
                if (i1 + 1 < n1) {
                    ++i1;
                } else {
                    // When x2[j2] is beyond the range of x1, break to fill the rest with y1[n1-1]
                    break;
                }
            }
        } else {
            // When x2[j2] == x1[i1]
            y2[j2] = y1[i1];
            ++j2;
        }
    }
    
    // Fill the remaining y2 elements with the last value of y1 if x2 is beyond the range of x1
    for (; j2 < n2; ++j2) {
        y2[j2] = y1.back();
    }
}

int main() {
    std::vector<float> x1 = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> y1 = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> x2 = {1.5, 2.5, 3.5, 4.5, 1.1, 2.2, 3.3, 4.4, 5.0, 5.5};
    std::vector<float> y2(x2.size());

    lininterp(x1, y1, x2, y2);

    std::cout << "Interpolated values:" << std::endl;
    for (size_t i = 0; i < x2.size(); ++i) {
        std::cout << "x2[" << i << "] = " << x2[i] << ", y2[" << i << "] = " << y2[i] << std::endl;
    }

    return 0;
}