#include <cmath>

void sla_DVN(const double V[3], double UV[3], double &VM) {
    double W1 = 0.0;

    // Compute the magnitude of the vector V
    for(int i = 0; i < 3; ++i) {
        double W2 = V[i];
        W1 += W2 * W2;
    }

    W1 = std::sqrt(W1);
    VM = W1;

    // Avoid division by zero
    if (W1 <= 0.0) {
        W1 = 1.0;
    }

    // Normalize the vector
    for(int i = 0; i < 3; ++i) {
        UV[i] = V[i] / W1;
    }
}