#include <iostream>
#include <vector>

// Assuming what the particle and electronNucleon_event structures might contain based on the Fortran version
class particle {
public:
    int ID = 0; // Default initialization
    // Add other necessary members and methods
};

class nucleonType {
public:
    int charge = 0; // Default initialization
    // Add other necessary members and methods
};

class electronNucleon_event {
public:
    nucleonType nucleon;
    // Add other necessary members and methods
};

class Coll_gammaN_exclPi {
public:
    static void DoColl_gammaN_exclPi(const electronNucleon_event& eNev, int ExclPiCharge, bool& FlagOK, std::vector<particle>& OutPart, double& XS_Tot) {
        int NucCharge;

        // Assuming OutPart is already sized correctly before being passed in
        for (auto& part : OutPart) {
            part.ID = 0; // Assuming ID is publicly accessible or there is a method to set it
        }
        XS_Tot = 0.0;
        FlagOK = false;

        NucCharge = eNev.nucleon.charge - ExclPiCharge; // Assuming proper access to nucleon and its charge
        if (NucCharge < 0 || NucCharge > 1) return;

        FlagOK = true; // If it reaches here, it passes the condition check
    }
};

int main() {
    electronNucleon_event eNev;
    eNev.nucleon.charge = 1; // Example initialization
    int ExclPiCharge = 0;
    std::vector<particle> OutPart(3); // Example size, initializing 3 particles
    double XS_Tot;
    bool FlagOK;

    Coll_gammaN_exclPi::DoColl_gammaN_exclPi(eNev, ExclPiCharge, FlagOK, OutPart, XS_Tot);

    // Simple output to verify the results
    std::cout << "FlagOK: " << std::boolalpha << FlagOK << std::endl;
    std::cout << "XS_Tot: " << XS_Tot << std::endl;
    for (size_t i = 0; i < OutPart.size(); ++i) {
        std::cout << "OutPart[" << i << "].ID: " << OutPart[i].ID << std::endl;
    }

    return 0;
}