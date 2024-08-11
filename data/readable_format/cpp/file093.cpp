#include <vector>
using namespace std;

void minimax(const vector<double>& x, double& xmin, double& xmax) {
    if (x.empty()) return; // Handle empty input vector

    xmax = x[0];
    xmin = xmax;

    for (int i = 1; i < x.size(); ++i) {
        if (x[i] < xmin) xmin = x[i];
        if (x[i] > xmax) xmax = x[i];
    }
}