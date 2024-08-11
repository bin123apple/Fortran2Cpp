#include <vector>

void XYZMOD(int NUMNP, int NDIM, 
            const std::vector<float>& XOLD, 
            const std::vector<float>& YOLD, 
            const std::vector<float>& ZOLD, 
            std::vector<float>& XNEW, 
            std::vector<float>& YNEW, 
            std::vector<float>& ZNEW) 
{
    for (int I = 0; I < NUMNP; ++I) {
        XNEW[I] = XOLD[I];
        YNEW[I] = YOLD[I];
        if (NDIM == 3) {
            ZNEW[I] = ZOLD[I];
        }
    }
}

int main() {
    // Example usage
    int NUMNP = 5; // Number of points
    int NDIM = 3;  // Dimension

    // Old coordinates
    std::vector<float> XOLD = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> YOLD = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> ZOLD = {1.0, 2.0, 3.0, 4.0, 5.0};

    // New coordinates (initialized with the same size as old ones)
    std::vector<float> XNEW(NUMNP);
    std::vector<float> YNEW(NUMNP);
    std::vector<float> ZNEW(NUMNP);

    // Call the subroutine
    XYZMOD(NUMNP, NDIM, XOLD, YOLD, ZOLD, XNEW, YNEW, ZNEW);

    // Output the results
    for (int I = 0; I < NUMNP; ++I) {
        std::cout << "XNEW[" << I << "] = " << XNEW[I] << ", "
                  << "YNEW[" << I << "] = " << YNEW[I];
        if (NDIM == 3) {
            std::cout << ", ZNEW[" << I << "] = " << ZNEW[I];
        }
        std::cout << std::endl;
    }

    return 0;
}