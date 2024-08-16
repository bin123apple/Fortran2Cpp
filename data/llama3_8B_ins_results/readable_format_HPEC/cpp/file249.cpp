#include <iostream>
#include <vector>

using namespace std;

void kernel_reg_detect(int niter, int maxgrid, int length, vector<vector<double>>& sumTang, vector<vector<double>>& mean, vector<vector<double>>& path, vector<vector<vector<double>>>& diff, vector<vector<vector<double>>>& sumDiff) {
    for (int t = 1; t <= niter; t++) {
        for (int j = 1; j <= maxgrid; j++) {
            for (int i = j; i <= maxgrid; i++) {
                for (int cnt = 1; cnt <= length; cnt++) {
                    diff[cnt - 1][i - 1][j - 1] = sumTang[i - 1][j - 1];
                }
            }
        }
    }

    for (int j = 1; j <= maxgrid; j++) {
        for (int i = j; i <= maxgrid; i++) {
            sumDiff[0][i - 1][j - 1] = diff[0][i - 1][j - 1];
            for (int cnt = 1; cnt < length; cnt++) {
                sumDiff[cnt][i - 1][j - 1] = sumDiff[cnt - 1][i - 1][j - 1] + diff[cnt][i - 1][j - 1];
            }
            mean[i - 1][j - 1] = sumDiff[length - 1][i - 1][j - 1];
        }
    }

    for (int i = 1; i <= maxgrid; i++) {
        path[i - 1][0] = mean[i - 1][0];
    }

    for (int j = 1; j <= maxgrid; j++) {
        for (int i = j; i <= maxgrid; i++) {
            path[i - 1][j] = path[i - 2][j - 1] + mean[i - 1][j];
        }
    }
}

int main() {
    int niter = 1;
    int maxgrid = 10;
    int length = 10;
    vector<vector<double>> sumTang(maxgrid, vector<double>(maxgrid));
    vector<vector<double>> mean(maxgrid, vector<double>(maxgrid));
    vector<vector<double>> path(maxgrid, vector<double>(maxgrid));
    vector<vector<vector<double>>> diff(length, vector<vector<double>>(maxgrid, vector<double>(maxgrid)));
    vector<vector<vector<double>>> sumDiff(length, vector<vector<double>>(maxgrid, vector<double>(maxgrid)));

    kernel_reg_detect(niter, maxgrid, length, sumTang, mean, path, diff, sumDiff);

    // Print the results
    for (int i = 0; i < maxgrid; i++) {
        for (int j = 0; j < maxgrid; j++) {
            cout << mean[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < maxgrid; i++) {
        for (int j = 0; j < maxgrid; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
