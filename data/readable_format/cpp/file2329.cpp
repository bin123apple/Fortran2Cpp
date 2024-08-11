#include <vector>
#include <algorithm> // for std::fill

void b4step2(
    int mbc, int mx, int my, int meqn,
    std::vector<double>& q, double xlower, double ylower, 
    double dx, double dy, double t, double dt, 
    int maux, std::vector<double>& aux)
{
    // Calculate the total size of arrays
    int q_size = meqn * (mx + 2 * mbc) * (my + 2 * mbc);
    int aux_size = maux * (mx + 2 * mbc) * (my + 2 * mbc);

    // Check if the time condition is met
    if (t > 1.0) {
        // Set aux(13,:,:) to 0.0
        // Note: In Fortran, arrays are 1-based; in C++, arrays are 0-based.
        // The 13th element corresponds to the 12th index in C++ (0-based).
        int aux_index_offset = 12 * (mx + 2 * mbc) * (my + 2 * mbc);
        std::fill(aux.begin() + aux_index_offset, 
                  aux.begin() + aux_index_offset + (mx + 2 * mbc) * (my + 2 * mbc), 
                  0.0);
    }
}