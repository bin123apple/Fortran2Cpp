#include <iostream>
#include <vector>
#include <cmath>

// Declaration of per_credat function
void per_credat(std::vector<double>& x, std::vector<double>& y, int nval, 
                const std::vector<double>& f, const std::vector<double>& c, const std::vector<double>& p, 
                int nf, bool epfl, const std::vector<double>& ep, double epoch, double freq);

// Definition of per_credat function
void per_credat(std::vector<double>& x, std::vector<double>& y, int nval, 
                const std::vector<double>& f, const std::vector<double>& c, const std::vector<double>& p, 
                int nf, bool epfl, const std::vector<double>& ep, double epoch, double freq) {
    
    double delt = (ep[1] - ep[0]) / static_cast<double>(nval - 1);
    
    for (int i = 0; i < nval; ++i) {
        
        double t;
        
        if (epfl) {
            x[i] = ep[0] + static_cast<double>(i) * delt;
            t = (x[i] - epoch) * 6.283185;
        } else {
            x[i] = static_cast<double>(i) / static_cast<double>(nval - 1);
            t = (x[i] / freq + ep[0] - epoch) * 6.283185;
        }
        
        y[i] = c[0];
        
        for (int j = 0; j < nf; ++j) {
            y[i] += c[j + 1] * std::sin(t * f[j] + p[j]);
        }
        
    }
}

void print_vectors(const std::vector<double>& vec) {
    for (const auto& v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int nval = 5;
    std::vector<double> x(nval), y(nval);
    std::vector<double> f = {1.0, 2.0};
    std::vector<double> c = {0.0, 1.0, 0.5};
    std::vector<double> p = {0.0, 3.14};
    int nf = 2;
    bool epfl = true;
    std::vector<double> ep = {0.0, 10.0};
    double epoch = 5.0, freq = 1.0;
    
    // Call the per_credat function with provided arguments
    per_credat(x, y, nval, f, c, p, nf, epfl, ep, epoch, freq);
    
    // Print the results
    std::cout << "X: ";
    print_vectors(x);
    std::cout << "Y: ";
    print_vectors(y);
    
    return 0;
}