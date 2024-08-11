// bisect2.cpp
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <cassert>

struct model_struct {
    // Example structure
};

const double X_TOL = 1e-5;

double bisect2(const std::function<double(model_struct*, double, const std::vector<double>&)>& func, 
               model_struct* current_model, 
               const std::vector<double>& extra_params, 
               double x1, double x2) {
    double dx, f, fmid, xmid, root;
    int MAXIT = 40;

    fmid = func(current_model, x2, extra_params);
    f = func(current_model, x1, extra_params);

    if (f * fmid >= 0.0) {
        std::cerr << "Root must be bracketed for bisection method." << std::endl;
        exit(1);
    }

    root = (f < 0.0) ? x1 : x2;
    dx = (f < 0.0) ? (x2 - x1) : (x1 - x2);

    for (int j = 0; j < MAXIT; ++j) {
        dx *= 0.5;
        xmid = root + dx;
        fmid = func(current_model, xmid, extra_params);
        if (fmid <= 0.0) {
            root = xmid;
        }
        if (std::abs(dx) < X_TOL || fmid == 0.0) {
            return root;
        }
    }

    std::cerr << "Too many iterations in bisection method." << std::endl;
    return root; // Return last computed mid-point as the root
}

double testFunc(model_struct* model, double x, const std::vector<double>& params) {
    return x - params[0];  // Simple linear function: f(x) = x - root
}

void testBisect2() {
    model_struct model;
    std::vector<double> extraParams = {2.0};  // Known root for test function
    double root = bisect2(testFunc, &model, extraParams, 1.0, 3.0);

    std::cout << "Found root: " << root << std::endl;
    assert(std::abs(root - 2.0) < X_TOL && "Test Failed. Incorrect root found.");
}

int main() {
    testBisect2();
    return 0;
}