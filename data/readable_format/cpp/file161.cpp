#include <iostream>
#include <vector>
#include <cmath>

// Define the mover function directly in this file
void mover(double** c1, int na1, double** c2, int na2, double cut, int np2, int* atom_list) {
    double x1, y1, z1, x2, y2, z2, dist;
    double dx2, dy2, dz2;
    int count = 0; // Note: C++ uses 0-based indexing

    for (int i = 0; i < na1; ++i) { // Adjusted for 0-based indexing
        x1 = c1[i][0];
        y1 = c1[i][1];
        z1 = c1[i][2];
        for (int j = 0; j < na2; ++j) { // Adjusted for 0-based indexing
            x2 = c2[j][0];
            y2 = c2[j][1];
            z2 = c2[j][2];
            bool qex = false; // Replaced Fortran flag with bool
            if (!qex) {
                dx2 = (x2 - x1) * (x2 - x1);
                dy2 = (y2 - y1) * (y2 - y1);
                dz2 = (z2 - z1) * (z2 - z1);
                dist = std::sqrt(dx2 + dy2 + dz2);
                if (dist < cut) {
                    atom_list[count] = 1;
                    ++count;
                }
            }
        }
    }

    std::cout << "C++: COUNT = " << count << std::endl;
}

int main() {
    int na1 = 2, na2 = 2, np2 = 2;
    double cut = 1.5;
    std::vector<std::vector<double>> c1(na1, std::vector<double>(3, 0.0));
    std::vector<std::vector<double>> c2(na2, std::vector<double>(3, 0.0));
    std::vector<int> atom_list(np2, 0);

    // Initializing test data
    c1[0] = {0.0, 0.0, 0.0};
    c1[1] = {3.0, 3.0, 3.0};

    c2[0] = {1.0, 1.0, 1.0};
    c2[1] = {4.0, 4.0, 4.0};

    // Convert vectors to raw pointers for compatibility with the mover function signature
    double** c1_raw = new double*[na1];
    double** c2_raw = new double*[na2];
    for (int i = 0; i < na1; ++i) c1_raw[i] = c1[i].data();
    for (int j = 0; j < na2; ++j) c2_raw[j] = c2[j].data();

    mover(c1_raw, na1, c2_raw, na2, cut, np2, atom_list.data());

    // Output results
    std::cout << "atom_list: ";
    for (auto val : atom_list) std::cout << val << " ";
    std::cout << std::endl;

    // Clean-up
    delete[] c1_raw;
    delete[] c2_raw;

    return 0;
}