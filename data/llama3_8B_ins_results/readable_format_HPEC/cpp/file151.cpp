#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int fstatus;
    int ipr, inorm;
    int itmax;
    double dt, omega;
    double tolrsd[5];
    int nx0, ny0, nz0;
    int isiz1, isiz2, isiz3;

    // Read input file
    ifstream inputFile("inputlu.data");
    if (inputFile.is_open()) {
        cout << "Reading from input file inputlu.data" << endl;
        inputFile >> ipr >> inorm >> ipr >> nx0 >> ny0 >> nz0 >> itmax >> dt >> omega;
        for (int i = 0; i < 5; i++) {
            inputFile >> tolrsd[i];
        }
        inputFile.close();
    } else {
        ipr = ipr_default;
        inorm = inorm_default;
        itmax = itmax_default;
        dt = dt_default;
        omega = omega_default;
        tolrsd[0] = tolrsd1_def;
        tolrsd[1] = tolrsd2_def;
        tolrsd[2] = tolrsd3_def;
        tolrsd[3] = tolrsd4_def;
        tolrsd[4] = tolrsd5_def;
        nx0 = isiz1;
        ny0 = isiz2;
        nz0 = isiz3;
    }

    // Check problem size
    if ((nx0 < 4) || (ny0 < 4) || (nz0 < 4)) {
        cout << "PROBLEM SIZE IS TOO SMALL - " << endl;
        cout << "SET EACH OF NX, NY AND NZ AT LEAST EQUAL TO 5" << endl;
        return 1;
    }

    if ((nx0 > isiz1) || (ny0 > isiz2) || (nz0 > isiz3)) {
        cout << "PROBLEM SIZE IS TOO LARGE - " << endl;
        cout << "NX, NY AND NZ SHOULD BE EQUAL TO " << isiz1 << ", " << isiz2 << " AND " << isiz3 << " RESPECTIVELY" << endl;
        return 1;
    }

    // Print output
    cout << "Size: " << nx0 << "x" << ny0 << "x" << nz0 << endl;
    cout << "Iterations: " << itmax << endl;
    cout << endl;

    return 0;
}
