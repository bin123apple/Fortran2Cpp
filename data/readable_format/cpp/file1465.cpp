#include <iostream>
#include <vector>

// Assuming the use of the std namespace for simplicity
using namespace std;

// Function prototype
int ISRCHFLE(int N, const vector<double>& array, int istep, double value);

int main() {
    // Example of using the function
    vector<double> array = {10.0, 20.0, 30.0, 40.0, 50.0}; // Sample array
    int N = array.size(); // Size of the array
    int istep = 1; // Step value
    double value = 25.0; // Value to search for

    int result = ISRCHFLE(N, array, istep, value);
    if (result != -1) {
        cout << "ISRCHFLE= " << result << " " << array[result-1] << " " << value << endl;
    } else {
        cerr << "ISRCHFLE failed" << endl;
        // In C++, rather than stopping the program, the error state can be handled differently.
        // For example, one could throw an exception, return an error code, etc.
    }

    return 0;
}

int ISRCHFLE(int N, const vector<double>& array, int istep, double value) {
    int i = -1; // Initialized to -1 to indicate failure if not found
    for (int k = N - 1; k >= 0; k -= istep) {
        double arr = array[k];
        if (arr <= value) {
            i = k + 1; // Adjusting index to 1-based to match Fortran's default indexing
            break;
        }
    }
    return i;
}