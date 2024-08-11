#include <iostream>
#include <vector>

using namespace std;

// Define the newInertia function directly in this file
void newInertia(const vector<double>& x, int mxatms, int natoms, double& sum) {
    double xm = 0.0;
    double ym = 0.0;
    double zm = 0.0;

    // Calculate the mean positions
    for (int j1 = 0; j1 < natoms; ++j1) {
        xm += x[3 * j1 + 0]; // Adjusted for 0-based indexing
        ym += x[3 * j1 + 1];
        zm += x[3 * j1 + 2];
    }
    xm /= natoms;
    ym /= natoms;
    zm /= natoms;

    // Calculate the modified inertia
    sum = 0.0;
    for (int j3 = 0; j3 < natoms; ++j3) {
        double dx = x[3 * j3 + 0] - xm; // Adjusted for 0-based indexing
        double dy = x[3 * j3 + 1] - ym;
        double dz = x[3 * j3 + 2] - zm;
        sum += dx * dx + dy * dy + dz * dz;
    }
    sum *= 2.0;
}

// The main function to test newInertia
int main() {
    const int NATOMS = 3;
    vector<double> x(3 * NATOMS);
    
    // Initialize test data
    for (int i = 0; i < NATOMS; ++i) {
        x[3 * i + 0] = (i + 1) * 1.0;
        x[3 * i + 1] = (i + 1) * 2.0;
        x[3 * i + 2] = (i + 1) * 3.0;
    }
    
    double sum = 0.0;
    // Call the function
    newInertia(x, NATOMS, NATOMS, sum);
    
    // Print the result
    cout << "Test SUM: " << sum << endl;
    
    return 0;
}