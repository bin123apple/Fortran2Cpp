#include <iostream>
#include <iomanip>

// Declaration and definition of writeRandomField function
void writeRandomField(const double* d, int nev, double abserr, double relerr) {
    using std::cout;
    using std::endl;
    using std::setw;
    
    cout << endl;
    cout << "EIGENVALUES OF MODESHAPES OF RANDOMFIELD" << endl;
    cout << endl;
    
    for (int i = nev - 1; i >= 0; --i) {
        cout << setw(7) << "" << std::scientific << std::setprecision(7) << d[i] << endl;
    }
    
    cout << endl;
    cout << "ABSOLUTE ERROR W.R.T. THE VARIANCE OF THE RANDOMFIELD" << endl;
    cout << endl;
    cout << setw(7) << "" << std::scientific << std::setprecision(7) << abserr << endl;
    
    cout << endl;
    cout << "RELATIVE ERROR W.R.T. THE VARIANCE OF THE RANDOMFIELD" << endl;
    cout << endl;
    cout << setw(7) << "" << std::scientific << std::setprecision(7) << relerr << endl;
}

// Main function to test writeRandomField
int main() {
    int nev = 3; // Number of eigenvalues
    double d[3] = {0.1, 0.2, 0.3}; // Example eigenvalues
    double abserr = 0.01; // Example absolute error
    double relerr = 0.05; // Example relative error
    
    writeRandomField(d, nev, abserr, relerr);
    
    return 0;
}