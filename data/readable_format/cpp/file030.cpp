#include <iostream>
#include <vector>

void integer_regrid_3d_r8(const std::vector<std::vector<std::vector<float>>>& data_in,
                          const std::vector<std::vector<bool>>& landmask_in,
                          int regrid_factor, int im_o, int jm_o, int ntim, int jm_i, int im_i,
                          std::vector<std::vector<std::vector<float>>>& data_out,
                          std::vector<std::vector<bool>>& landmask_out) {
    const float zero = 0.0f;
    const float one = 1.0f;
    const float eps = 0.1f;

    std::vector<float> tempsum(ntim, zero);
    float ngood;

    for (int i = 0; i < im_o; ++i) {
        for (int j = 0; j < jm_o; ++j) {
            std::fill(tempsum.begin(), tempsum.end(), zero);
            ngood = zero;
            for (int ii = 1; ii <= regrid_factor; ++ii) {
                for (int jj = 1; jj <= regrid_factor; ++jj) {
                    int iii = (i * regrid_factor) + (ii - 1);
                    int jjj = (j * regrid_factor) + (jj - 1);
                    if (landmask_in[jjj][iii]) {
                        for (int t = 0; t < ntim; ++t) {
                            tempsum[t] += data_in[t][jjj][iii];
                        }
                        ngood += one;
                    }
                }
            }
            if (ngood > eps) {
                for (int t = 0; t < ntim; ++t) {
                    data_out[t][j][i] = tempsum[t] / ngood;
                }
                landmask_out[j][i] = true;
            } else {
                landmask_out[j][i] = false;
            }
        }
    }
}

int main() {
    int regrid_factor = 2, im_o = 2, jm_o = 2, ntim = 1, jm_i = 4, im_i = 4;

    std::vector<std::vector<std::vector<float>>> data_in(ntim, std::vector<std::vector<float>>(jm_i, std::vector<float>(im_i)));
    std::vector<std::vector<bool>> landmask_in(jm_i, std::vector<bool>(im_i));
    std::vector<std::vector<std::vector<float>>> data_out(ntim, std::vector<std::vector<float>>(jm_o, std::vector<float>(im_o)));
    std::vector<std::vector<bool>> landmask_out(jm_o, std::vector<bool>(im_o));

    // Initialize input data and landmask
    int count = 1;
    for (int t = 0; t < ntim; ++t) {
        for (int j = 0; j < jm_i; ++j) {
            for (int i = 0; i < im_i; ++i) {
                data_in[t][j][i] = static_cast<float>(count++);
                landmask_in[j][i] = ((j < 2 && i < 2) || (j >= 2 && i >= 2));
            }
        }
    }

    // Call the function
    integer_regrid_3d_r8(data_in, landmask_in, regrid_factor, im_o, jm_o, ntim, jm_i, im_i, data_out, landmask_out);

    // Output results for verification
    std::cout << "Data Out:" << std::endl;
    for (int t = 0; t < ntim; ++t) {
        for (int j = 0; j < jm_o; ++j) {
            for (int i = 0; i < im_o; ++i) {
                std::cout << data_out[t][j][i] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::cout << "Landmask Out:" << std::endl;
    for (int j = 0; j < jm_o; ++j) {
        for (int i = 0; i < im_o; ++i) {
            std::cout << (landmask_out[j][i] ? "true" : "false") << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}