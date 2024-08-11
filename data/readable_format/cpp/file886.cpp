#include <iostream>
#include <iomanip>

// Define the writeboun function
void writeboun(const int* nodeboun, const int* ndirboun, const double* xboun, const char* typeboun, int nboun) {
    using namespace std;
    
    cout << endl; // Mimicking write(*,*)
    cout << "SPC " << endl;
    for (int i = 0; i < nboun; ++i) {
        cout << setw(5) << i + 1 << " " // Adjusting index for 1-based output
             << setw(10) << nodeboun[i] << " "
             << setw(5) << ndirboun[i] << " "
             << setw(11) << fixed << setprecision(4) << xboun[i] << " "
             << typeboun[i] << endl;
    }
}

// Main function for testing
int main() {
    int nodeboun[] = {1, 2, 3};
    int ndirboun[] = {100, 200, 300};
    double xboun[] = {1.234, 2.345, 3.456};
    char typeboun[] = {'A', 'B', 'C'};
    int nboun = 3;

    writeboun(nodeboun, ndirboun, xboun, typeboun, nboun);

    return 0;
}