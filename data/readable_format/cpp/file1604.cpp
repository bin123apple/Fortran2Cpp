#include <iostream>
#include <string>

class ModuleGlobal {
public:
    // Variable declarations
    std::string dirIN = std::string(30, ' ');
    std::string dirOUT = std::string(30, ' ');
    std::string dirTMP = std::string(30, ' ');
    std::string simname = std::string(30, ' ');
    std::string filesim = std::string(30, ' ');
    std::string filexy = std::string(30, ' ');
    std::string filename = std::string(100, ' ');

    int flagbed;
    double beta, beta0, betaold;
    double theta, theta0, thetaold;
    double ds, ds0, dsold;
    double Rp;
    double rpic, rpic0;
    int jmodel;
    double Cf, Cf0, Cfold;
    double CD, CT;
    double phi, phiD, phiT;
    double F0;

    double Ef;
    double Eb;
    double Eo;
    double Ebound;
    double Lhalfvalley;
    double Ltransvalley;
    int jbound;

    int flagxy0;
    int flag_ox;
    int N, Nold, N0;
    int Nrand;
    int jre;
    int jnco;
    int ksavgol;
    double deltas, deltas0;
    double dsmin, dsmax;
    double tollc;
    double stdv;

    int flag_time;
    int flag_dt;
    int ivideo;
    int ifile;
    int nend;
    double TT, TTs;
    double kTTfco;
    double tt0;
    double dt0;
    double cstab;

    // Constructors
    ModuleGlobal() : flagbed(0), beta(0.0), beta0(0.0), betaold(0.0),
                     theta(0.0), theta0(0.0), thetaold(0.0), ds(0.0), ds0(0.0), dsold(0.0),
                     Rp(0.0), rpic(0.0), rpic0(0.0), jmodel(0), Cf(0.0), Cf0(0.0), Cfold(0.0),
                     CD(0.0), CT(0.0), phi(0.0), phiD(0.0), phiT(0.0), F0(0.0),
                     Ef(0.0), Eb(0.0), Eo(0.0), Ebound(0.0), Lhalfvalley(0.0), Ltransvalley(0.0), jbound(0),
                     flagxy0(0), flag_ox(0), N(0), Nold(0), N0(0), Nrand(0), jre(0), jnco(0), ksavgol(0),
                     deltas(0.0), deltas0(0.0), dsmin(0.0), dsmax(0.0), tollc(0.0), stdv(0.0),
                     flag_time(0), flag_dt(0), ivideo(0), ifile(0), nend(0), TT(0.0), TTs(0.0), kTTfco(0.0),
                     tt0(0.0), dt0(0.0), cstab(0.0) {}
};

// Test function
void testModuleGlobal() {
    ModuleGlobal mg;

    // Test initialization
    std::cout << "Testing initialization..." << std::endl;
    if (mg.beta == 0.0) {
        std::cout << "Pass: beta initialized to 0.0" << std::endl;
    } else {
        std::cout << "Fail: beta not initialized to 0.0" << std::endl;
    }

    // Test setting and getting a value
    std::cout << "Testing setting beta..." << std::endl;
    mg.beta = 1.5;
    if (mg.beta == 1.5) {
        std::cout << "Pass: beta set to 1.5" << std::endl;
    } else {
        std::cout << "Fail: beta not set to 1.5" << std::endl;
    }

    // More tests can be added here...
}

int main() {
    testModuleGlobal();
    return 0;
}