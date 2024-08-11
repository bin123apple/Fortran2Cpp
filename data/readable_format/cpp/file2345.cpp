#include <cmath>

void realim(float* a, float* b, int m, int n) {
    float im;
    float modul;
    float phase;
    float rl;

    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < m; ++j) {
            modul = a[j + k * m];
            phase = b[j + k * m];
            rl = modul * cos(phase);
            im = modul * sin(phase);
            a[j + k * m] = rl;
            b[j + k * m] = im;
        }
    }
}