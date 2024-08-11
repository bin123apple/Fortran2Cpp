#include <iostream>
#include <vector>

// Define the GETBUF function
void GETBUF(std::vector<float>& BUF1, std::vector<float>& BUF2, int NPIX, int NRAST) {
    int totalSize = NPIX * NRAST;
    
    // Ensure BUF2 is the right size
    BUF2.resize(totalSize);
    
    for (int i = 0; i < totalSize; ++i) {
        BUF2[i] = BUF1[i];
    }
}

// Main function to test the GETBUF function
int main() {
    int npix = 10, nrast = 5;
    std::vector<float> buf1(npix * nrast), buf2;
    bool test_passed = true;
    
    // Fill buf1 with test data
    for (int i = 0; i < npix * nrast; ++i) {
        buf1[i] = i + 1; // +1 to match Fortran 1-indexing in the test
    }
    
    // Call the GETBUF function
    GETBUF(buf1, buf2, npix, nrast);
    
    // Verify buf2 contains the copied data
    for (int i = 0; i < npix * nrast; ++i) {
        if (buf2[i] != buf1[i]) {
            test_passed = false;
            break;
        }
    }
    
    // Output the result
    if (test_passed) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }
    
    return 0;
}