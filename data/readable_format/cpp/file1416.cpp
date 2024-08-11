#include <iostream>
#include <cassert>
#include <iomanip>

double paper(int a2, int a3, int a4, int a5) {
    double p = 0.0;
    double p2 = 0.0, p3 = 0.0, p4 = 0.0, p5 = 0.0;
    
    if (a5 == 1 && a2 + a3 + a4 == 0) {
        p = 0.0;
    } else if (a4 == 1 && a2 + a3 + a5 == 0) {
        p = 1.0;
    } else if (a3 == 1 && a2 + a4 + a5 == 0) {
        p = 1.0;
    } else if (a2 == 1 && a3 + a4 + a5 == 0) {
        p = 1.0;
    } else {
        if (a2 > 0) p2 = a2 * paper(a2 - 1, a3 + 1, a4 + 1, a5 + 1);
        if (a3 > 0) p3 = a3 * paper(a2, a3 - 1, a4 + 1, a5 + 1);
        if (a4 > 0) p4 = a4 * paper(a2, a3, a4 - 1, a5 + 1);
        if (a5 > 0) p5 = a5 * paper(a2, a3, a4, a5 - 1);
        
        p = (p2 + p3 + p4 + p5) / (a2 + a3 + a4 + a5);
    }
    return p;
}

int main() {
    std::cout << std::fixed << std::setprecision(6);
    
    // Test Case 1
    double result1 = paper(1, 1, 1, 1);
    std::cout << "Test Case 1: " << result1 << std::endl;
    
    // More test cases can be added here...
    
    return 0;
}