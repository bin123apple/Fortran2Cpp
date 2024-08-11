#include <iostream>
#include <vector>
#include <iomanip>

void r1f2kb(int ido, int l1, std::vector<std::vector<std::vector<std::vector<double>>>>& cc, int in1,
            std::vector<std::vector<std::vector<std::vector<double>>>>& ch, int in2, std::vector<double>& wa1) {
    int i, ic, idp2, k;

    for (k = 0; k < l1; ++k) {
        ch[0][0][k][0] = cc[0][0][0][k] + cc[0][ido-1][1][k];
        ch[0][0][k][1] = cc[0][0][0][k] - cc[0][ido-1][1][k];
    }

    if (ido > 2) {
        idp2 = ido + 2;
        for (k = 0; k < l1; ++k) {
            for (i = 2; i < ido; i += 2) {
                ic = idp2 - i - 1;

                ch[0][i-1][k][0] = cc[0][i-1][0][k] + cc[0][ic-1][1][k];
                ch[0][i][k][0] = cc[0][i][0][k] - cc[0][ic][1][k];

                ch[0][i-1][k][1] = wa1[i-2] * (cc[0][i-1][0][k] - cc[0][ic-1][1][k]) -
                                   wa1[i-1] * (cc[0][i][0][k] + cc[0][ic][1][k]);
                ch[0][i][k][1] = wa1[i-2] * (cc[0][i][0][k] + cc[0][ic][1][k]) +
                                 wa1[i-1] * (cc[0][i-1][0][k] - cc[0][ic-1][1][k]);
            }
        }
    }

    if (ido % 2 == 0) {
        for (k = 0; k < l1; ++k) {
            ch[0][ido-1][k][0] = 2 * cc[0][ido-1][0][k];
            ch[0][ido-1][k][1] = -2 * cc[0][0][1][k];
        }
    }
}

int main() {
    const int ido = 2, l1 = 2, in1 = 2, in2 = 2;
    std::vector<double> wa1 = {1.0, 2.0};
    std::vector<std::vector<std::vector<std::vector<double>>>> cc(in1, std::vector<std::vector<std::vector<double>>>(ido, std::vector<std::vector<double>>(2, std::vector<double>(l1))));
    std::vector<std::vector<std::vector<std::vector<double>>>> ch(in2, std::vector<std::vector<std::vector<double>>>(ido, std::vector<std::vector<double>>(l1, std::vector<double>(2))));

    // Initialize test data
    double val = 1.0;
    for (int i = 0; i < in1; ++i) {
        for (int j = 0; j < ido; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < l1; ++l) {
                    cc[i][j][k][l] = val++;
                }
            }
        }
    }

    // Call the function
    r1f2kb(ido, l1, cc, in1, ch, in2, wa1);

    // Print results
    std::cout << std::fixed << std::setprecision(1);
    for (int l = 0; l < 2; ++l) {
        for (int k = 0; k < l1; ++k) {
            for (int j = 0; j < ido; ++j) {
                std::cout << "ch[" << in2 << "][" << j << "][" << k << "][" << l << "] = " << ch[in2-1][j][k][l] << std::endl;
            }
        }
    }

    return 0;
}