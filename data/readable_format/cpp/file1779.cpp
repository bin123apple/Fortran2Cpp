#include <iostream>
#include <vector>
#include <complex>
#include <cassert>

class WannierNew {
public:
    static constexpr int ningx = 10;
    static bool use_wannier;
    static bool rkmesh;
    static bool plot_wannier;
    static bool use_energy_int;
    static bool print_wannier_coeff;
    static int nwan;
    static int plot_wan_num;
    static int plot_wan_spin;
    static std::vector<std::vector<double>> wan_pot;
    static std::vector<std::vector<double>> wannier_energy;
    static std::vector<std::vector<std::vector<double>>> wannier_occ;
    static std::vector<std::vector<std::complex<double>>> pp;
    static std::vector<std::vector<std::vector<std::complex<double>>>> coef;

    struct Ingredient {
        int l = 0;
        int m = 0;
        int iatomwfc = 0;
        double c = 0.0;

        Ingredient() = default;
    };

    struct WannierData {
        int iatom = 0;
        int ning = 0;
        double bands_from = 0.0;
        double bands_to = 0.0;
        std::vector<Ingredient> ing;

        WannierData() : ing(ningx) {}
    };

    static std::vector<std::vector<WannierData>> wan_in;
};

// Static member definitions
bool WannierNew::use_wannier = false;
bool WannierNew::rkmesh = false;
bool WannierNew::plot_wannier = false;
bool WannierNew::use_energy_int = false;
bool WannierNew::print_wannier_coeff = false;
int WannierNew::nwan = 0;
int WannierNew::plot_wan_num = 0;
int WannierNew::plot_wan_spin = 0;
std::vector<std::vector<double>> WannierNew::wan_pot;
std::vector<std::vector<double>> WannierNew::wannier_energy;
std::vector<std::vector<std::vector<double>>> WannierNew::wannier_occ;
std::vector<std::vector<std::complex<double>>> WannierNew::pp;
std::vector<std::vector<std::vector<std::complex<double>>>> WannierNew::coef;
std::vector<std::vector<WannierNew::WannierData>> WannierNew::wan_in;

int main() {
    // Example test: Check if static variables are initialized correctly
    assert(WannierNew::use_wannier == false);
    std::cout << "WannierNew::use_wannier initialized correctly." << std::endl;

    // Initialize dynamic variables and test
    WannierNew::wan_pot.resize(2, std::vector<double>(2, 0.0));
    assert(WannierNew::wan_pot.size() == 2);
    std::cout << "WannierNew::wan_pot resized and initialized correctly." << std::endl;

    // Add more tests as needed

    std::cout << "All tests passed." << std::endl;

    return 0;
}