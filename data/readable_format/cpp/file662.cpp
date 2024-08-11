#include <iostream>
#include <vector>

class BackusMod {
private:
    int navg, nz;

public:
    BackusMod() : navg(0), nz(0) {}

    void dobackus_init(int navg_in, int nz_in) {
        navg = navg_in;
        nz = nz_in;
    }

    void handlEnds(std::vector<float>& p) {
        int mm = (navg - 1) / 2 + 1;

        float gt = p[mm - 1]; // Adjusted for 0-based indexing
        float gb = p[nz - mm]; // Adjusted for 0-based indexing

        for (int ii = 0; ii < mm; ++ii) {
            p[ii] = gt;
        }

        for (int ii = nz - mm; ii < nz; ++ii) {
            p[ii] = gb;
        }
    }

    void dobackus(std::vector<float>& p, std::vector<float>& avg) {
        int mm = (navg - 1) / 2;
        avg.resize(p.size()); // Ensure avg is the same size as p

        for (int ii = 0; ii < nz; ++ii) {
            float val = 0.0f;

            if (ii - mm >= 0 && ii + mm < nz) {
                for (int jj = ii - mm; jj <= ii + mm; ++jj) {
                    val += p[jj];
                }
                avg[ii] = val / navg;
            } else {
                avg[ii] = p[ii];
            }
        }
    }
};

int main() {
    int navg = 5, nz = 10;
    std::vector<float> p(nz), avg;

    // Initialize p with linearly increasing values
    for (int i = 0; i < nz; ++i) {
        p[i] = static_cast<float>(i + 1); // +1 for 1-based equivalent values
    }

    BackusMod backusMod;
    backusMod.dobackus_init(navg, nz);

    // Test handling ends
    backusMod.handlEnds(p);
    std::cout << "After handling ends:" << std::endl;
    for (const auto& val : p) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Test main data processing routine
    backusMod.dobackus(p, avg);
    std::cout << "After dobackus:" << std::endl;
    for (const auto& val : avg) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}