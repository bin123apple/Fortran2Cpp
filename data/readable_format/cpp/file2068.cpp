#include <iostream>
#include <cassert>

// Assuming the maximum dimensions are known. Adjust these values as necessary.
const int maxnspec = 10; // Example value, adjust as needed
const int maxspecdim = 10; // Example value, adjust as needed
const int maxpnts = 10; // Example value, adjust as needed

// Definition of spec_min function (assuming it's not included from another file)
double spec_min(double spec[maxnspec][maxspecdim][maxpnts], int nspec, int nchannel, int npnts) {
    // Adjusting for zero-based indexing by subtracting 1 from Fortran indices
    nspec -= 1;
    nchannel -= 1;
    
    double min_val = spec[nspec][nchannel][0]; // Adjusting for zero-based indexing
    for (int i = 1; i < npnts; ++i) { // Loop starts from 1 since we've already used the 0th element
        if (spec[nspec][nchannel][i] < min_val) {
            min_val = spec[nspec][nchannel][i];
        }
    }

    return min_val;
}

int main() {
    // Initialize the 3D array with sample dimensions.
    double spec[maxnspec][maxspecdim][maxpnts] = {{{0}}}; // Initializes all elements to 0.

    // Setting up a test scenario
    const int nspec = 1;
    const int nchannel = 1;
    const int npnts = 10;

    // Fill the relevant slice with values and introduce a known minimum
    for (int k = 0; k < npnts; ++k) {
        spec[nspec-1][nchannel-1][k] = k + 1.0; // Simple initialization (accounting for zero-based indexing)
    }
    spec[nspec-1][nchannel-1][4] = -1.0; // Known minimum

    // Call the function and check the result
    double result = spec_min(spec, nspec, nchannel, npnts);
    std::cout << "The minimum value in the specified slice is: " << result << std::endl;

    // Assert the correctness of the result
    assert(result == -1.0);

    return 0;
}