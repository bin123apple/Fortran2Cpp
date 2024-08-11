#include <iostream>
#include <cmath>

// Definition of the sdsdot function
float sdsdot(int N, float sb, const float *sx, int strideX, const float *sy, int strideY) {
    double dtemp = static_cast<double>(sb);
    if (N <= 0) {
        return static_cast<float>(dtemp);
    }
    
    int ix, iy;
    
    if (strideX == 1 && strideY == 1) {
        int m = N % 5;
        if (m != 0) {
            for (int i = 0; i < m; ++i) {
                dtemp += static_cast<double>(sx[i]) * static_cast<double>(sy[i]);
            }
        }
        for (int i = m; i < N; i += 5) {
            dtemp += static_cast<double>(sx[i]) * static_cast<double>(sy[i]) +
                     static_cast<double>(sx[i + 1]) * static_cast<double>(sy[i + 1]) +
                     static_cast<double>(sx[i + 2]) * static_cast<double>(sy[i + 2]) +
                     static_cast<double>(sx[i + 3]) * static_cast<double>(sy[i + 3]) +
                     static_cast<double>(sx[i + 4]) * static_cast<double>(sy[i + 4]);
        }
    } else {
        ix = (strideX < 0) ? (1 - N) * strideX : 0;
        iy = (strideY < 0) ? (1 - N) * strideY : 0;
        for (int i = 0; i < N; ++i) {
            dtemp += static_cast<double>(sx[ix]) * static_cast<double>(sy[iy]);
            ix += strideX;
            iy += strideY;
        }
    }
    return static_cast<float>(dtemp);
}

// Main function to run test cases
int main() {
    // Test vectors and parameters
    float sx[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float sy[] = {1.0, 1.0, 1.0, 1.0, 1.0};
    float sb;
    int N = 5;
    int strideX, strideY;
    float result;

    // Test 1 - Basic dot product
    sb = 0.0;
    strideX = 1;
    strideY = 1;
    result = sdsdot(N, sb, sx, strideX, sy, strideY);
    std::cout << "Test 1 (Basic): Expected 15.0, Got " << result << std::endl;

    // Test 2 - With scaling factor
    sb = 2.0;
    result = sdsdot(N, sb, sx, strideX, sy, strideY);
    std::cout << "Test 2 (Scaling): Expected 17.0, Got " << result << std::endl;

    // Test 3 - With strides
    strideX = 2;
    strideY = 2;
    result = sdsdot(N, sb, sx, strideX, sy, strideY);
    std::cout << "Test 3 (Strides): Expected 8.0, Got " << result << std::endl;

    return 0;
}