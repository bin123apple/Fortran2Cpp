#include <iostream>
#include <vector>
#include <cstdint>

class SumAll3DArrayDP {
public:
    static void sumAll3DArrayDP(const std::vector<std::vector<std::vector<double>>>& sendBuf,
                                std::vector<std::vector<std::vector<double>>>& recvBuf,
                                std::int32_t nx, std::int32_t ny, std::int32_t nz) {
        double sum = 0.0;

        for (int z = 0; z < nz; ++z) {
            for (int y = 0; y < ny; ++y) {
                for (int x = 0; x < nx; ++x) {
                    sum += sendBuf[x][y][z];
                }
            }
        }

        for (int z = 0; z < nz; ++z) {
            for (int y = 0; y < ny; ++y) {
                for (int x = 0; x < nx; ++x) {
                    recvBuf[x][y][z] = sum;
                }
            }
        }
    }
};

int main() {
    std::vector<std::vector<std::vector<double>>> sendBuf = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    std::int32_t nx = sendBuf.size();
    std::int32_t ny = sendBuf[0].size();
    std::int32_t nz = sendBuf[0][0].size();
    std::vector<std::vector<std::vector<double>>> recvBuf(nx, std::vector<std::vector<double>>(ny, std::vector<double>(nz, 0.0)));

    double expectedSum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8;

    SumAll3DArrayDP::sumAll3DArrayDP(sendBuf, recvBuf, nx, ny, nz);

    double actualSum = 0.0;
    for (const auto& plane : recvBuf) {
        for (const auto& row : plane) {
            for (double val : row) {
                actualSum += val;
            }
        }
    }

    if (actualSum == expectedSum * nx * ny * nz) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Expected sum: " << expectedSum * nx * ny * nz << ", Actual sum: " << actualSum << std::endl;
    }

    return 0;
}