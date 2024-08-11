#include <iostream>
#include <string>

// Function declaration
void unpackpfx(int ng, std::string& call1);

int main() {
    std::string call1;
    int ng;

    // Test case 1
    call1 = "CALLSIGN";
    ng = 12345;
    unpackpfx(ng, call1);
    std::cout << "Test 1: " << call1 << std::endl;
    
    // Test case 2
    call1 = "TEST";
    ng = 60010;
    unpackpfx(ng, call1);
    std::cout << "Test 2: " << call1 << std::endl;
    
    // Test case 3
    call1 = "EXAMPLE";
    ng = 70000;
    unpackpfx(ng, call1);
    std::cout << "Test 3: " << call1 << std::endl;

    return 0;
}

// Function definition
void unpackpfx(int ng, std::string& call1) {
    if (ng < 60000) {
        int n = ng;
        std::string pfx(3, ' '); // Initialize pfx with 3 spaces
        for (int i = 2; i >= 0; --i) { // Indices are 0-based in C++
            int nc = n % 37;
            if (nc >= 0 && nc <= 9) {
                pfx[i] = static_cast<char>(nc + 48);
            } else if (nc >= 10 && nc <= 35) {
                pfx[i] = static_cast<char>(nc + 55);
            } else {
                pfx[i] = ' ';
            }
            n = n / 37;
        }
        call1 = pfx + "/" + call1;
        if (call1[0] == ' ') call1.erase(0, 1);
        if (call1[0] == ' ') call1.erase(0, 1);
    } else {
        size_t i1 = call1.find(' ');
        int nc = ng - 60000;
        if (nc >= 0 && nc <= 9) {
            call1 = call1.substr(0, i1) + "/" + static_cast<char>(nc + 48);
        } else if (nc >= 10 && nc <= 35) {
            call1 = call1.substr(0, i1) + "/" + static_cast<char>(nc + 55);
        } else if (nc >= 36 && nc <= 125) {
            int nc1 = (nc - 26) / 10;
            int nc2 = (nc - 26) % 10;
            call1 = call1.substr(0, i1) + "/" + static_cast<char>(nc1 + 48) + static_cast<char>(nc2 + 48);
        }
    }
}