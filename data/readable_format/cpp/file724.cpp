#include <iostream>
#include <vector>
#include <numeric>  // For std::accumulate
#include <cassert>  // For assert

// Interface (abstract base class)
class IUserInterface {
public:
    virtual void evalf(int n, const std::vector<double>& x, double& f, int& flag) = 0;
    virtual void evalc(int n, const std::vector<double>& x, int ind, double& c, int& flag) = 0;
    virtual void evaljac(int n, const std::vector<double>& x, int ind, std::vector<int>& jcvar, std::vector<double>& jcval, int& jcnnz, int& flag) = 0;
    virtual ~IUserInterface() = default;
};

// Test implementation of the IUserInterface
class TestUserInterface : public IUserInterface {
public:
    void evalf(int n, const std::vector<double>& x, double& f, int& flag) override {
        f = std::accumulate(x.begin(), x.end(), 0.0); // Sum of elements
        flag = 0;
    }

    void evalc(int n, const std::vector<double>& x, int ind, double& c, int& flag) override {
        c = x[ind - 1]; // Account for 0-based indexing
        flag = 0;
    }

    void evaljac(int n, const std::vector<double>& x, int ind, std::vector<int>& jcvar, std::vector<double>& jcval, int& jcnnz, int& flag) override {
        jcnnz = n;
        for (int i = 0; i < n; ++i) {
            jcvar[i] = i + 1; // Fortran-style 1-based indexing
            jcval[i] = x[i];
        }
        flag = 0;
    }
};

// Simple test runner function
void runTests() {
    TestUserInterface ui;
    std::vector<double> x = {1, 2, 3, 4, 5};
    double f;
    int flag;
    
    // Test evalf
    ui.evalf(5, x, f, flag);
    assert(f == 15.0); // Sum of elements

    // Test evalc
    double c;
    ui.evalc(5, x, 3, c, flag);
    assert(c == 3.0); // Value at index 3

    // Test evaljac
    std::vector<int> jcvar(5);
    std::vector<double> jcval(5);
    int jcnnz;
    ui.evaljac(5, x, 3, jcvar, jcval, jcnnz, flag);
    assert(jcnnz == 5);
    for (int i = 0; i < 5; ++i) {
        assert(jcvar[i] == i + 1);      // Fortran-style 1-based indexing
        assert(jcval[i] == x[i]);       // Value check
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}