#include <array>
#include <iostream>

// Assuming sp is defined somewhere in mod_kind
using sp = float;

void boite(sp x, sp y, sp dx, sp dy, std::array<sp, 5>& desx, std::array<sp, 5>& desy) {
    desx[0] = x - dx;
    desx[1] = x + dx;    
    desx[2] = x + dx;    
    desx[3] = x - dx;    
    desx[4] = x - dx;    
    
    desy[0] = y - dy;    
    desy[1] = y - dy;
    desy[2] = y + dy;
    desy[3] = y + dy;
    desy[4] = y - dy;
}

int main() {
    sp x = 1.0f, y = 2.0f, dx = 0.5f, dy = 0.5f;
    std::array<sp, 5> desx, desy;

    boite(x, y, dx, dy, desx, desy);
    
    for(int i = 0; i < 5; ++i) {
        std::cout << "desx[" << i << "] = " << desx[i] << ", desy[" << i << "] = " << desy[i] << std::endl;
    }

    return 0;
}