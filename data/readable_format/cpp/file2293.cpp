#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

void ESSAI(double APX, double& AKPX, int IND, bool& ERREUR, std::vector<double>& AKP, std::vector<double>& AP) {
    static const double epsilon = std::numeric_limits<double>::epsilon();
    
    ERREUR = false;

    if (IND > 0) {
        if (APX < 0.0) {
            ERREUR = true;
            return;
        }

        bool FIN_TRAITEMENT = false;
        int I = 1;
        int IM;

        while (I <= 28 && !FIN_TRAITEMENT) {
            if (std::abs(APX - AP[I - 1]) <= epsilon) {
                AKPX = AKP[I - 1];
                FIN_TRAITEMENT = true;
            } else if (APX <= AP[I - 1]) {
                IM = I - 1;
                AKPX = AKP[IM - 1] + (AKP[I - 1] - AKP[IM - 1]) * (APX - AP[IM - 1]) / (AP[I - 1] - AP[IM - 1]);
                FIN_TRAITEMENT = true;
            } else {
                I = I + 1;
            }
        }
    }
}

int main() {
    double APX;
    double AKPX;
    int IND;
    bool ERREUR;

    std::vector<double> AKP(28);
    std::vector<double> AP(28);

    // Initialize APX, AKP, AP and IND with appropriate values

    ESSAI(APX, AKPX, IND, ERREUR, AKP, AP);

    if (ERREUR) {
        std::cerr << "Error: APX is less than 0." << std::endl;
    } else {
        std::cout << "AKPX: " << AKPX << std::endl;
    }

    return 0;
}