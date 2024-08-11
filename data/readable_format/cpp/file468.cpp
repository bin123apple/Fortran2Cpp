#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

// Function to calculate energy
void hardshellenergy(int atom_count, const vector<vector<double>>& coordinates, double radius, double& energy) {
    energy = 0.0;
    for (int i = 0; i < atom_count; ++i) {
        for (int j = i + 1; j < atom_count; ++j) {
            double dx = coordinates[0][i] - coordinates[0][j];
            double dy = coordinates[1][i] - coordinates[1][j];
            double dz = coordinates[2][i] - coordinates[2][j];
            double dist = sqrt(dx*dx + dy*dy + dz*dz);
            if (dist < radius) {
                energy += pow(radius - dist, 2);
            }
        }
    }
}

// Function to calculate gradient
void hardshellenergy_gradient(int atom_count, const vector<vector<double>>& coordinates, double radius, vector<vector<double>>& gradient) {
    gradient.assign(3, vector<double>(atom_count, 0.0)); // Initialize gradient
    for (int i = 0; i < atom_count; ++i) {
        for (int j = i + 1; j < atom_count; ++j) {
            double dx = coordinates[0][i] - coordinates[0][j];
            double dy = coordinates[1][i] - coordinates[1][j];
            double dz = coordinates[2][i] - coordinates[2][j];
            double dist = sqrt(dx*dx + dy*dy + dz*dz);
            if (dist < radius) {
                double factor = 2.0 * (radius - dist) / dist;
                gradient[0][i] -= factor * dx;
                gradient[1][i] -= factor * dy;
                gradient[2][i] -= factor * dz;
                gradient[0][j] += factor * dx;
                gradient[1][j] += factor * dy;
                gradient[2][j] += factor * dz;
            }
        }
    }
}

int main() {
    vector<vector<double>> coordinates = {{1.0, 2.0}, {0.0, 0.0}, {0.0, 0.0}};
    double radius = 1.5;
    int atom_count = 2;
    double energy;
    vector<vector<double>> gradient(3, vector<double>(2));
    double expected_energy = 0.25;
    vector<vector<double>> expected_gradient = {{1.0, -1.0}, {0.0, 0.0}, {0.0, 0.0}};

    // Test energy calculation
    hardshellenergy(atom_count, coordinates, radius, energy);
    cout << "Energy Test: ";
    assert(fabs(energy - expected_energy) < 1.0e-5);
    cout << "PASS" << endl;

    // Test gradient calculation
    hardshellenergy_gradient(atom_count, coordinates, radius, gradient);
    cout << "Gradient Test: ";
    bool gradient_test_pass = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (fabs(gradient[i][j] - expected_gradient[i][j]) >= 1.0e-5) {
                gradient_test_pass = false;
            }
        }
    }
    assert(gradient_test_pass);
    cout << "PASS" << endl;

    return 0;
}