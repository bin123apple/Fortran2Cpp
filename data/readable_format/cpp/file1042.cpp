#include <cassert>
#include <iostream>

class Precision {
public:
    struct FitLookupTable {
        int fittype;
        int fitparm;
    };

    static constexpr int doublePrecision = 8;
    static constexpr double Yr = 31557600.0;
    static constexpr double Rsun = 696265000.0;
    static constexpr double Mearth = 5.97219e24;
    static constexpr double day = 86400.0;
    static constexpr double PI = 3.141592653589793;
    static constexpr double maxintg = 2000.0;
    static constexpr double maxintg_nt = 10.0;
    static constexpr double Gr = 6.6719842229637e-11;
    static constexpr double K2 = 2.959122082855911e-04;
    static constexpr double Msun = 1.9891e30;
    static constexpr double AU = 1.4959787e11;
    static constexpr double MU = Msun;
    static constexpr double TU = day;
    static constexpr double LU = AU;
};

int main() {
    // Check constants
    assert(Precision::Yr == 31557600.0);
    assert(Precision::Rsun == 696265000.0);
    assert(Precision::Mearth == 5.97219e24);
    assert(Precision::day == 86400.0);
    assert(Precision::PI == 3.141592653589793);
    assert(Precision::Gr == 6.6719842229637e-11);
    assert(Precision::K2 == 2.959122082855911e-04);
    assert(Precision::Msun == 1.9891e30);
    assert(Precision::AU == 1.4959787e11);
    assert(Precision::MU == Precision::Msun);
    assert(Precision::TU == Precision::day);
    assert(Precision::LU == Precision::AU);

    // Check FitLookupTable
    Precision::FitLookupTable table;
    table.fittype = 1;
    table.fitparm = 2;

    assert(table.fittype == 1);
    assert(table.fitparm == 2);

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}