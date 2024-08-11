#include <vector>

void inirea(int len, float rfrom, std::vector<float>& rto) {
    // Ensure the vector is of the correct size
    rto.resize(len);

    for(int i = 0; i < len; ++i) {
        rto[i] = rfrom;
    }
}