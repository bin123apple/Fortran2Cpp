#include <iostream>
#include <cmath> // For std::fabs function

// Definition of the eapVarApp class directly included
class eapVarApp {
public:
    static float f(float x) {
        float j, k, l;
        j = x;
        k = g(j * j);
        l = j * g(j * j * j);
        return k; // As per your Fortran logic
    }
    
    static float g(float x) {
        return x; // Directly returning x as per your Fortran logic
    }
    
    static float h(float x) {
        float y;
        y = f(x);
        return y; // As per your Fortran logic
    }
};

bool almostEqual(float x, float y, float epsilon = 0.001f) {
    return std::fabs(x - y) < epsilon;
}

int main() {
    // Test values
    float x = 2.0f;
    
    // Expected values for f, g, h with x = 2.0
    float expectedF = 4.0f; // Expected result of f(x) considering g(x)=x^2 logic
    float expectedG = 2.0f; // Expected result of g(x)
    float expectedH = 4.0f; // Expected result of h(x) which calls f(x)

    // Test function f
    if (almostEqual(eapVarApp::f(x), expectedF)) {
        std::cout << "f(x) test passed." << std::endl;
    } else {
        std::cout << "f(x) test failed." << std::endl;
    }
    
    // Test function g
    if (almostEqual(eapVarApp::g(x), expectedG)) {
        std::cout << "g(x) test passed." << std::endl;
    } else {
        std::cout << "g(x) test failed." << std::endl;
    }
    
    // Test function h
    if (almostEqual(eapVarApp::h(x), expectedH)) {
        std::cout << "h(x) test passed." << std::endl;
    } else {
        std::cout << "h(x) test failed." << std::endl;
    }

    return 0;
}