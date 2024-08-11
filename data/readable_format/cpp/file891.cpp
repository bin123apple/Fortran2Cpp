#include <iostream>
#include <cmath>

void ARGCH2(int KEY, double& RA, double& DEC, int& IH, double& AM, char& ISGN, int& ID, double& AMIN) {
    const double RAD = 0.0174532925199;
    const char IPLUS = '+';
    const char IMINUS = '-';
    double H, D, HOURS, DEG;

    if(KEY == -1) goto label10;

    H = IH;
    D = ID;
    RA = 15.0 * (H + AM / 60.0) * RAD;
    DEC = (D + AMIN / 60.0) * RAD;
    if(ISGN == '-') DEC = -DEC;
    return;

label10:
    HOURS = RA / RAD / 15.0;
    HOURS = std::fmod(HOURS, 24.0);
    IH = static_cast<int>(HOURS);
    AM = (HOURS - IH) * 60.0;
    AM = AM + 1e-6;
    if(AM < 60.0) goto label12;
    AM = AM - 60.0;
    IH = IH + 1;

label12:
    if(IH >= 24) IH = IH - 24;

    if(DEC < 0) goto label15;
    else goto label20;

label15:
    ISGN = IMINUS;
    goto label25;

label20:
    ISGN = IPLUS;

label25:
    DEG = std::abs(DEC) / RAD;
    ID = static_cast<int>(DEG);
    AMIN = (DEG - ID) * 60.0;
}

void testARGCH2() {
    double RA, DEC, AM, AMIN;
    int KEY, IH, ID;
    char ISGN;

    // Test case 1
    KEY = 0; IH = 10; ID = 45; AM = 30.0; AMIN = 30.0; ISGN = '+';
    RA = DEC = 0.0; // Initialize to something
    ARGCH2(KEY, RA, DEC, IH, AM, ISGN, ID, AMIN);
    std::cout << "Test 1: " << RA << " " << DEC << " " << IH << " " << AM << " " << ISGN << " " << ID << " " << AMIN << std::endl;

    // Test case 2: Reverse conversion
    KEY = -1;
    ARGCH2(KEY, RA, DEC, IH, AM, ISGN, ID, AMIN);
    std::cout << "Test 2: " << RA << " " << DEC << " " << IH << " " << AM << " " << ISGN << " " << ID << " " << AMIN << std::endl;
}

int main() {
    testARGCH2();
    return 0;
}