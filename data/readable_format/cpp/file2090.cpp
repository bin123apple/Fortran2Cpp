#include <iostream>
#include <algorithm> // For std::min

// Function prototype
void rk_addtend_dry(float* t_tend, float* t_tendf, const float* t_save, const float* h_diabatic,
                    const float* mut, const float* msft, int rk_step,
                    int ide, int jde, int ims, int ime, int jms, int jme, int kms, int kme,
                    int its, int ite, int jts, int jte, int kts, int kte);

// Function definition
void rk_addtend_dry(float* t_tend, float* t_tendf, const float* t_save, const float* h_diabatic,
                    const float* mut, const float* msft, int rk_step,
                    int ide, int jde, int ims, int ime, int jms, int jme, int kms, int kme,
                    int its, int ite, int jts, int jte, int kts, int kte) {
    // Adjustments for 0-based indexing not necessary in argument list
    for (int j = jts-1; j < std::min(jte, jde)-1; j++) {
        for (int k = kts-1; k < kte-1; k++) {
            for (int i = its-1; i < std::min(ite, ide)-1; i++) {
                // Calculate the 1D index for the "flattened" 3D array (i, k, j)
                int idx3D = (i - (ims-1)) + (ime - (ims-1)) * ((k - (kms-1)) + (kme - (kms-1)) * (j - (jms-1)));
                // Calculate the 1D index for the "flattened" 2D array (i, j)
                int idx2D = (i - (ims-1)) + (ime - (ims-1)) * (j - (jms-1));

                if (rk_step == 1) {
                    t_tendf[idx3D] += t_save[idx3D];
                }

                t_tend[idx3D] += t_tendf[idx3D] / msft[idx2D] + mut[idx2D] * h_diabatic[idx3D] / msft[idx2D];
            }
        }
    }
}

void test_rk_addtend_dry() {
    const int ide = 3, jde = 3, ims = 1, ime = 3, jms = 1, jme = 3, kms = 1, kme = 2;
    const int its = 1, ite = 3, jts = 1, jte = 3, kts = 1, kte = 2;
    int rk_step = 1;
    float t_tend[18], t_tendf[18], t_save[18], h_diabatic[18], mut[9], msft[9];

    // Initialize arrays
    std::fill_n(t_tend, 18, 1.0f);
    std::fill_n(t_tendf, 18, 2.0f);
    std::fill_n(t_save, 18, 0.5f);
    std::fill_n(h_diabatic, 18, 0.4f);
    std::fill_n(mut, 9, 0.3f);
    std::fill_n(msft, 9, 1.0f);

    rk_addtend_dry(t_tend, t_tendf, t_save, h_diabatic, mut, msft, rk_step,
                   ide, jde, ims, ime, jms, jme, kms, kme, its, ite, jts, jte, kts, kte);

    // Print results to check
    for (int k = kts-1; k < kte-1; k++) {
        for (int j = jts-1; j < jte-1; j++) {
            for (int i = its-1; i < ite-1; i++) {
                int idx3D = (i - (ims-1)) + (ime - (ims-1)) * ((k - (kms-1)) + (kme - (kms-1)) * (j - (jms-1)));
                std::cout << "t_tend[" << i << "][" << k << "][" << j << "] = " << t_tend[idx3D] << std::endl;
            }
        }
    }
}

int main() {
    test_rk_addtend_dry();
    return 0;
}