#include <iostream>
#include <vector>
#include <cassert>

void minimax(const std::vector<double>& x, double& xmin, double& xmax) {
    if (x.empty()) return;
    
    xmin = x[0];
    xmax = x[0];
    
    for (size_t i = 0; i < x.size(); ++i) {
        if (x[i] < xmin) xmin = x[i];
        if (x[i] > xmax) xmax = x[i];
    }
}

int main() {
    {
        std::vector<double> testArray = {1.0, 2.5, 3.0, 4.5, 5.0};
        double xmin, xmax;
        minimax(testArray, xmin, xmax);
        assert(xmin == 1.0 && xmax == 5.0);
        std::cout << "Test 1: Positive numbers. Min: " << xmin << " Max: " << xmax << std::endl;
    }

    {
        std::vector<double> testArray = {-3.0, -1.5, -4.5, -2.0, -5.5};
        double xmin, xmax;
        minimax(testArray, xmin, xmax);
        assert(xmin == -5.5 && xmax == -1.5);
        std::cout << "Test 2: Negative numbers. Min: " << xmin << " Max: " << xmax << std::endl;
    }

    {
        std::vector<double> testArray = {2.5, -1.0, 3.0, -4.5, 0.0};
        double xmin, xmax;
        minimax(testArray, xmin, xmax);
        assert(xmin == -4.5 && xmax == 3.0);
        std::cout << "Test 3: Mixed numbers. Min: " << xmin << " Max: " << xmax << std::endl;
    }

    {
        std::vector<double> testArray = {2.0};
        double xmin, xmax;
        minimax(testArray, xmin, xmax);
        assert(xmin == 2.0 && xmax == 2.0);
        std::cout << "Test 4: Single element. Min: " << xmin << " Max: " << xmax << std::endl;
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}