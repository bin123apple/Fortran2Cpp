#include <iostream>
#include <cmath>

const double PI = 3.141593;
const double SOLCON = 0.082;

void radcur(int day, int hr, double rdlat, double decl, double& ratio) {
    double dfact, slrtm, hasun, haset, harise, rdsun;

    dfact = ((2 * PI) * (day - 81)) / 365.0;

    slrtm = (0.1645 * sin(2 * dfact)) - (0.1255 * cos(dfact)) - (0.025 * sin(dfact));

    hasun = ((hr + slrtm) - 12) * (PI / 12);

    haset = hasun - (PI / 24);

    harise = hasun + (PI / 24);

    rdsun = 1 + 0.033 * cos((2 * PI * day) / 365);

    ratio = ((12 * 60) / PI) * SOLCON * rdsun * (cos(rdlat) *
             cos(decl) * (sin(harise) - sin(haset)) +
             (harise - haset) * sin(rdlat) * sin(decl));

    if (ratio < 0.0) {
        ratio = 0.0;
    }
}

void test_radcur(int day, int hr, double rdlat, double decl) {
    double ratio;
    radcur(day, hr, rdlat, decl, ratio);
    std::cout << "Test - Day: " << day << ", Hour: " << hr 
              << ", rdlat: " << rdlat << ", decl: " << decl 
              << ", Ratio: " << ratio << std::endl;
}

int main() {
    // Test Case 1
    test_radcur(100, 12, 0.5, 0.1);
    
    // Test Case 2
    test_radcur(200, 6, 0.5, 0.1);
    
    // Test Case 3
    test_radcur(300, 18, 0.5, 0.1);
    
    return 0;
}