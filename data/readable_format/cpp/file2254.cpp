#include <iostream>
#include <vector>

void OED_CTR_2INDEX_REORDER(int NXYZT, int NCTR,
                            int NCGTOR, int NCGTOS,
                            int IXOFFI, int IXOFFJ,
                            const std::vector<std::vector<double>>& X,
                            std::vector<std::vector<double>>& Y) {

    int J, IJ;
    int RS = 0;

    J = -IXOFFJ + 1;
    for (int S = 1; S <= NCGTOS; ++S) {
        J = J + IXOFFJ;
        IJ = J - IXOFFI;
        for (int R = 1; R <= NCGTOR; ++R) {
            IJ = IJ + IXOFFI;
            RS = RS + 1;

            for (int N = 0; N < NXYZT; ++N) {
                if (RS <= NCTR) {
                    Y[N][IJ - 1] = X[N][RS - 1]; // Adjusting for 1-based index
                }
            }
        }
    }
}

int main() {
    int NXYZT = 10;
    int NCTR = 5;
    int NCGTOR = 3;
    int NCGTOS = 2;
    int IXOFFI = 1;
    int IXOFFJ = 2;

    std::vector<std::vector<double>> X(NXYZT, std::vector<double>(NCTR));
    std::vector<std::vector<double>> Y(NXYZT, std::vector<double>(NCTR));

    // Initialize X with some values.
    for (int i = 0; i < NXYZT; ++i) {
        for (int j = 0; j < NCTR; ++j) {
            X[i][j] = static_cast<double>((i + 1) * (j + 1));
        }
    }

    OED_CTR_2INDEX_REORDER(NXYZT, NCTR, NCGTOR, NCGTOS, IXOFFI, IXOFFJ, X, Y);

    std::cout << "Y = " << std::endl;
    for (int i = 0; i < NXYZT; ++i) {
        for (int j = 0; j < NCTR; ++j) {
            std::cout << Y[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}