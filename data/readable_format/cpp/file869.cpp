#include <iostream>
#include <cmath>
#include <string>
#include <vector>

enum Axis { x = 0, y, z };

struct SolventFlux {
    double flux[3] = {0.0, 0.0, 0.0}; // x, y, z
};

struct Node {
    SolventFlux solventFlux;
};

std::vector<std::vector<std::vector<Node>>> node(1, std::vector<std::vector<Node>>(1, std::vector<Node>(1)));

void initialize_system() {
    // Assuming some initialization here
    node[0][0][0].solventFlux.flux[x] = 0.0;
    node[0][0][0].solventFlux.flux[y] = 0.0;
    node[0][0][0].solventFlux.flux[z] = 0.0;
}

void comp_j() {
    // Assuming some computations here, simplified for demonstration
    node[0][0][0].solventFlux.flux[x] = 5.0;
    node[0][0][0].solventFlux.flux[y] = 6.0;
    node[0][0][0].solventFlux.flux[z] = 7.0;
}

void finalize_system() {
    // Assuming some cleanup here
}

void assert_equal(double real_value, double expected_value, const std::string& message, double tolerance = 1.0E-5) {
    if (std::abs(real_value - expected_value) > tolerance) {
        std::cout << message << std::endl;
    } else {
        std::cout << "Test passed." << std::endl;
    }
}

int main() {
    initialize_system();
    comp_j();

    assert_equal(node[0][0][0].solventFlux.flux[x], 5.0, "Test 1 failed for x");
    assert_equal(node[0][0][0].solventFlux.flux[y], 6.0, "Test 2 failed for y");
    assert_equal(node[0][0][0].solventFlux.flux[z], 7.0, "Test 3 failed for z");

    finalize_system();

    return 0;
}