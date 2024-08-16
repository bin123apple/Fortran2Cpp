#include <iostream>
#include <string>

using namespace std;

void domain(int nx0, int ny0, int nz0, int isiz1, int isiz2, int isiz3) {
    int nx = nx0;
    int ny = ny0;
    int nz = nz0;

    if ((nx < 4) || (ny < 4) || (nz < 4)) {
        cout << "SUBDOMAIN SIZE IS TOO SMALL - " << endl;
        cout << "ADJUST PROBLEM SIZE OR NUMBER OF PROCESSORS" << endl;
        cout << "SO THAT NX, NY AND NZ ARE GREATER THAN OR EQUAL TO 4 THEY ARE CURRENTLY " << setfill('0') << setw(3) << nx << setw(3) << ny << setw(3) << nz << endl;
        exit(1);
    }

    if ((nx > isiz1) || (ny > isiz2) || (nz > isiz3)) {
        cout << "SUBDOMAIN SIZE IS TOO LARGE - " << endl;
        cout << "ADJUST PROBLEM SIZE OR NUMBER OF PROCESSORS" << endl;
        cout << "SO THAT NX, NY AND NZ ARE LESS THAN OR EQUAL TO " << isiz1 << ", " << isiz2 << " AND " << isiz3 << " RESPECTIVELY.  THEY ARE " << setfill('0') << setw(4) << nx << setw(4) << ny << setw(4) << nz << endl;
        exit(1);
    }

    int ist = 2;
    int iend = nx - 1;

    int jst = 2;
    int jend = ny - 1;

    int ii1 = 2;
    int ii2 = nx0 - 1;
    int ji1 = 2;
    int ji2 = ny0 - 2;
    int ki1 = 3;
    int ki2 = nz0 - 1;
}
