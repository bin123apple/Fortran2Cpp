#include <iostream>
#include <cmath>
#include <cassert>

void Ctme(int T, int& Ih, int& Im, double& Is) {
    Ih = T / 3600;
    Im = (T / 60) - (Ih * 60);
    Is = static_cast<double>(T - Ih * 3600 - Im * 60);
}

int main() {
    int Ih, Im, T;
    double Is;
    
    // Test case 1
    T = 3661;
    Ctme(T, Ih, Im, Is);
    assert(Ih == 1 && Im == 1 && std::abs(Is - 1) < 0.001);
    
    // Additional test cases...
    T = 86399;
    Ctme(T, Ih, Im, Is);
    assert(Ih == 23 && Im == 59 && std::abs(Is - 59) < 0.001);
    
    T = 0;
    Ctme(T, Ih, Im, Is);
    assert(Ih == 0 && Im == 0 && Is == 0);
    
    T = 60;
    Ctme(T, Ih, Im, Is);
    assert(Ih == 0 && Im == 1 && Is == 0);
    
    T = 3600;
    Ctme(T, Ih, Im, Is);
    assert(Ih == 1 && Im == 0 && Is == 0);
    
    std::cout << "All tests passed successfully.";
    
    return 0;
}