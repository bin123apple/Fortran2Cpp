#include <iostream>
#include <cmath>
#include <cassert> // For assert

void calculate(double& a, double& b, double& c) {
    double p[2] = {0.0, 1.0};
    double q[2] = {1.0, 0.9};
    double r[2] = {3.0, 0.5};

    a = q[0]*r[0]*log(p[1])/((p[0]-q[0])*(p[0]-r[0])) 
        - p[0]*r[0]*log(q[1])/((p[0]-q[0])*(q[0]-r[0])) 
        + p[0]*q[0]*log(r[1])/((p[0]-r[0])*(q[0]-r[0]));
    
    b = -(q[0]+r[0])*log(p[1])/((p[0]-q[0])*(p[0]-r[0])) 
        + (p[0]+r[0])*log(q[1])/((p[0]-q[0])*(q[0]-r[0])) 
        + (p[0]+q[0])*log(r[1])/((p[0]-r[0])*(r[0]-q[0]));
    
    c = log(p[1])/((p[0]-q[0])*(p[0]-r[0])) 
        - log(q[1])/((p[0]-q[0])*(q[0]-r[0])) 
        + log(r[1])/((p[0]-r[0])*(q[0]-r[0]));
}

void test_calculations() {
    double a, b, c;
    calculate(a, b, c);

    // Actual expected values based on the computation
    double expected_a = 0.0; // Actual expected value
    double expected_b = -0.0425162911; // Actual expected value
    double expected_c = -0.0628442615; // Actual expected value
    double tolerance = 1e-5;

    assert(std::abs(a - expected_a) < tolerance);
    assert(std::abs(b - expected_b) < tolerance);
    assert(std::abs(c - expected_c) < tolerance);

    std::cout << "Test passed." << std::endl;
}

int main() {
    test_calculations();

    return 0;
}