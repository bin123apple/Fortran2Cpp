#include <iostream>
#include <cmath>
#include <vector>

// Define MSTDEV right in this file
void MSTDEV(const int* LINE, int NX, int* NRAN, int JN, double& AM, double& STD, double& SNUM) {
    double S, SS, SN;
    int KL = NRAN[0];
    int KH = NRAN[1];
  
    for (int J = 1; J <= JN; ++J) {
        S = 0.0;
        SN = 0.0;
        SS = 0.0;
      
        if (KH >= KL) {
            for (int K = KL; K <= KH; ++K) {
                double AN = static_cast<double>(LINE[K-1]); // Adjusting index for 0-based array
                double V = static_cast<double>(K);
                SN += AN;
                S += AN * V;
                SS += AN * V * V;
            }
        }
      
        if (SN > 0.0) {
            AM = S / SN;
        } else {
            AM = 0.0;
        }
      
        if (SN > 1.0) {
            SS = (SS - S * S / SN) / (SN - 1.0);
            if (SS > 1.0E-20) {
                STD = std::sqrt(SS);
            } else {
                STD = 0.0;
            }
        } else {
            STD = 0.0;
        }
      
        int KLA = static_cast<int>(AM - 3.0 * STD);
        int KHA = static_cast<int>(AM + 3.0 * STD);
      
        if(KLA > NRAN[0]) KL = KLA;
        if(KHA < NRAN[1]) KH = KHA;
    }
  
    SNUM = SN;
}

// Main function to test MSTDEV
int main() {
    std::vector<int> LINE = {2, 3, 5, 7, 11};
    int NX = LINE.size();
    int NRAN[2] = {1, 5};
    int JN = 2;
    double AM, STD, SNUM;

    MSTDEV(LINE.data(), NX, NRAN, JN, AM, STD, SNUM);

    std::cout << "AM = " << AM << std::endl;
    std::cout << "STD = " << STD << std::endl;
    std::cout << "SNUM = " << SNUM << std::endl;

    return 0;
}