#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 180;
    std::vector<int> indexSet = {521, 523, 525, 527, 529, 531, 547, 549,
                                 // continue the initialization as per Fortran code
                                 2009, 2011, 2013};
    std::vector<double> base(2026, 0.0); // size is 2026 to match 1-indexing in Fortran
    int idx1, idx2;

#pragma omp parallel for private(idx1, idx2)
    for (int i = 0; i < N; i++) {
        idx1 = indexSet[i];
        idx2 = indexSet[i] + 12;
        base[idx1] += 1.0;
        base[idx2] += 3.0;
    }

    for (int i = 521; i <= 2025; i++) {
        if (base[i] == 4.0) {
            std::cout << "i= " << i << ", base= " << base[i] << std::endl;
        }
    }

    return 0;
}
