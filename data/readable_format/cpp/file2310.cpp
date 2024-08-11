#include <iostream>
using namespace std;

int main() {
    int i[3] = {1, 2, 3};

    // Apply the condition similar to the Fortran 'where' construct
    for (int idx = 0; idx < 3; idx++) {
        if (i[idx] > 1) {
            i[idx] *= 2;
        } else {
            i[idx] *= 3;
        }
    }

    // Print the array
    for (int idx = 0; idx < 3; idx++) {
        cout << i[idx] << " ";
    }
    cout << endl;

    return 0;
}