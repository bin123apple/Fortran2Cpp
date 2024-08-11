#include <iostream>
#include <vector>
#include <cmath>

// Adjust function prototype
void adjust(int km, int nl, float Cpd, float Ps, std::vector<float>& PH, std::vector<float>& P, std::vector<float>& T, std::vector<float>& Th, float kap);

// Adjust function implementation
void adjust(int km, int nl, float Cpd, float Ps, std::vector<float>& PH, std::vector<float>& P, std::vector<float>& T, std::vector<float>& Th, float kap) {
    std::vector<float> TOLD(km, 0.0f); // Initializing TOLD with 0s
    float sum, thbar, ahm, a2, RDCP, kapX, X;
    int jn, i, j, k, jc;

    RDCP = kap;

    jc = 0;
    for (i = nl - 2; i >= 0; --i) { // Adjusting loop for 0-based indexing
        jn = 0;
        sum = Th[i];
        for (j = i + 1; j < nl; ++j) { // Adjusting loop for 0-based indexing
            sum += Th[j];
            thbar = sum / static_cast<float>(j - i + 1);
            if (Th[j] < thbar) jn = j;
        }
        if (jn == 0) continue;

        ahm = 0.0f;
        for (j = i; j <= jn; ++j) { // Adjusting loop for 0-based indexing
            ahm += Cpd * T[j] * (PH[j] - PH[j + 1]);
        }

        a2 = 0.0f;
        for (j = i; j <= jn; ++j) { // Adjusting loop for 0-based indexing
            X = std::pow(P[j] / Ps, RDCP);
            TOLD[j] = T[j];
            T[j] = X;
            a2 += Cpd * X * (PH[j] - PH[j + 1]);
        }

        for (j = i; j <= jn; ++j) { // Adjusting loop for 0-based indexing
            Th[j] = ahm / a2;
            T[j] = T[j] * Th[j];
        }

        if (Th[jn + 1] < Th[jn] && jn <= nl - 1) { // Adjusting condition for 0-based indexing
            jn++;
            --j; // Adjusting to mimic the GOTO 12 behavior
            continue;
        }

        if (i == 0) jc = jn; // Adjusting condition for 0-based indexing
    }
}

// Main function to demonstrate usage and perform a basic test
int main() {
    // Example test data
    int km = 5, nl = 5;
    float Cpd = 1000.0, Ps = 100000.0, kap = 0.286;
    std::vector<float> Th = {288.0, 290.0, 295.0, 300.0, 305.0};
    std::vector<float> T = Th; // Copy initialization
    std::vector<float> P = {100000.0, 95000.0, 90000.0, 85000.0, 80000.0};
    std::vector<float> PH = {100500.0, 95500.0, 90500.0, 85500.0, 80500.0, 75000.0};

    // Call the adjust function
    adjust(km, nl, Cpd, Ps, PH, P, T, Th, kap);

    // Print results for verification
    std::cout << "Adjusted T:" << std::endl;
    for (const auto& t : T) {
        std::cout << t << std::endl;
    }

    std::cout << "Adjusted Th:" << std::endl;
    for (const auto& th : Th) {
        std::cout << th << std::endl;
    }

    return 0;
}