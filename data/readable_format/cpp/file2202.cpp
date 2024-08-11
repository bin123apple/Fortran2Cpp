#include <cmath>

void sctovec(const double tp[2], double v[3]) {
    double t1 = std::sin(tp[0]);
    v[0] = t1 * std::cos(tp[1]);
    v[1] = t1 * std::sin(tp[1]);
    v[2] = std::cos(tp[0]);
}

int main() {
    // Example usage:
    double tp[2] = { 1.0, 0.5 }; // input values
    double v[3]; // output values

    sctovec(tp, v);

    // Print the results
    for(int i = 0; i < 3; ++i) {
        printf("%f\n", v[i]);
    }

    return 0;
}