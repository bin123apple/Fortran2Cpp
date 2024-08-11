#include <iostream>
#include <vector>
#include <complex>
#include <string>

// Decoding function declaration
void decodems(std::vector<std::complex<float>>& cdat, int npts, std::vector<std::vector<std::complex<float>>>& cw, int i1, int nchar, std::vector<std::vector<float>>& s2, std::string& msg) {
    std::vector<std::complex<float>> z(npts);
    const std::string cc = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ./?-                 _     @";
    
    msg = "";
    int kpk = 0;
    for (int j = 0; j < nchar; ++j) {
        int ia = i1 + j * 56; // Adjusted for 0-based indexing
        float smax = 0.0f;
        for (int k = 0; k <= 40; ++k) {
            int kk = k;
            if (k == 40) kk = 57;
            std::complex<float> z = 0.0f;
            for (int i = 0; i < 56; ++i) {
                z += cdat[ia + i] * std::conj(cw[i][kk]);
            }
            float ss = std::abs(z);
            s2[k][j] = ss;
            if (ss > smax) {
                smax = ss;
                kpk = kk;
            }
        }
        msg += cc[kpk]; // Direct assignment, assuming ASCII compatibility
        if (kpk == 57) msg[j] = ' ';
    }
}

// Test function
void test_decodems() {
    int npts = 224;
    int nchar = 4;
    int i1 = 0; // Adjusted for 0-based indexing
    std::vector<std::complex<float>> cdat(npts);
    std::vector<std::vector<std::complex<float>>> cw(56, std::vector<std::complex<float>>(64));
    std::vector<std::vector<float>> s2(64, std::vector<float>(400, 0.0f));
    std::string msg;

    // Initialize test data
    for (int i = 0; i < npts; ++i) {
        cdat[i] = std::complex<float>(static_cast<float>(i+1), static_cast<float>(i+1));
    }
    for (int i = 0; i < 56; ++i) {
        for (int j = 0; j < 64; ++j) {
            cw[i][j] = std::complex<float>(static_cast<float>(i+j), static_cast<float>(i-j));
        }
    }

    // Call the function
    decodems(cdat, npts, cw, i1, nchar, s2, msg);

    // Output the result
    std::cout << "Message: " << msg << std::endl;
}

// Main function to run the test
int main() {
    test_decodems();
    return 0;
}