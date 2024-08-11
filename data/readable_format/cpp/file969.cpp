#include <iostream>
#include <vector>

// Function to perform the DLAPMT operation
void dlapmt(bool forwrd, int m, int n, std::vector<std::vector<double>>& x, std::vector<int>& k) {
    int i, ii, in, j;
    double temp;

    if (n <= 1) {
        return;
    }

    for (i = 0; i < n; ++i) {
        k[i] = -k[i];
    }

    if (forwrd) {
        for (i = 0; i < n; ++i) {
            if (k[i] > 0) {
                continue;
            }

            j = i;
            k[j] = -k[j];
            in = k[j];

            while (true) {
                if (k[in] > 0) {
                    break;
                }

                for (ii = 0; ii < m; ++ii) {
                    temp = x[ii][j];
                    x[ii][j] = x[ii][in];
                    x[ii][in] = temp;
                }

                k[in] = -k[in];
                j = in;
                in = k[in];
            }
        }
    } else {
        for (i = 0; i < n; ++i) {
            if (k[i] > 0) {
                continue;
            }

            k[i] = -k[i];
            j = k[i];

            while (true) {
                if (j == i) {
                    break;
                }

                for (ii = 0; ii < m; ++ii) {
                    temp = x[ii][i];
                    x[ii][i] = x[ii][j];
                    x[ii][j] = temp;
                }

                k[j] = -k[j];
                j = k[j];
            }
        }
    }
}

int main() {
    bool forwrd = true;
    int m = 2, n = 3;
    std::vector<int> k = {2, 0, 1}; // Adjusted for 0-based indexing
    std::vector<std::vector<double>> x = {{1, 3, 5}, {2, 4, 6}}; // Already in 0-based indexing

    // Call the dlapmt function
    dlapmt(forwrd, m, n, x, k);

    std::cout << "K after DLAPMT:" << std::endl;
    for (auto val : k) {
        std::cout << val + 1 << std::endl; // Adjusted back to 1-based indexing for comparison
    }

    std::cout << "X after DLAPMT:" << std::endl;
    for (const auto& row : x) {
        for (auto val : row) {
            std::cout << val << std::endl;
        }
    }

    return 0;
}