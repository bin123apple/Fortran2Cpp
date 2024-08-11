#include <vector>

void checkRange(const std::vector<int>& iArray, int nItems, int maxVal, int& nZero, int& nErr) {
    // Initialize counters
    nZero = 0;
    nErr = 0;

    // Loop through the array elements
    for (int i = 0; i < nItems; i++) {
        int n = iArray[i];
        if (n < 1) {
            nZero++;
        }
        if (n > maxVal) {
            nErr++;
        }
    }
}