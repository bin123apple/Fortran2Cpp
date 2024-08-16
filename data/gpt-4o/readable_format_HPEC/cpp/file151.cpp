#include <cstdio>
#include <fstream>
#include <iostream>

void read_input() {
    using namespace std;

    int fstatus;
    ifstream inFile;
    int ipr, inorm, itmax;
    double dt, omega, tolrsd[5];
    int nx0, ny0, nz0;

    inFile.open("inputlu.data");
    if (inFile.good()) {
        cout << "Reading from input file inputlu.data" << endl;
        inFile >> ipr >> inorm >> itmax >> dt >> omega;
        for (int i = 0; i < 5; i++)
            inFile >> tolrsd[i];
        inFile >> nx0 >> ny0 >> nz0;
    } else {
        // set default values if file does not exist
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

    if (nx0 < 4 || ny0 < 4 || nz0 < 4) {
        cout << "PROBLEM SIZE IS TOO SMALL - ";
        cout << "SET EACH OF NX, NY AND NZ AT LEAST EQUAL TO 5" << endl;
        exit(1);
    }

    if (nx0 > isiz1 || ny0 > isiz2 || nz0 > isiz3) {
        cout << "PROBLEM SIZE IS TOO LARGE - ";
        cout << "NX, NY AND NZ SHOULD BE EQUAL TO ";
        cout << "ISIZ1, ISIZ2 AND ISIZ3 RESPECTIVELY" << endl;
        exit(1);
    }

    cout << "Size: " << nx0 << "x" << ny0 << "x" << nz0 << endl;
    cout << "Iterations: " << itmax << endl;
    cout << "Number of available threads: " << thread::hardware_concurrency() << endl;
}
