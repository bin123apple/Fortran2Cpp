#include <cmath>
#include <vector>

// Assume h_params, h_dist_struct, and h_utils are defined elsewhere,
// and include the relevant parts from those headers.

// Placeholder for the gaus_dist function, assumed to be defined in h_utils.
extern float gaus_dist(float r);

// Placeholder for the parameters structure, assumed to be defined in h_params or h_dist_struct.
struct GP {
    int num_life;
    std::vector<float> alpha;
    float t;
    std::vector<float> tau;
    float R0;
};

// Assuming gp is a global variable or passed to the function.
extern GP gp;

float gaus_decay(float r) {
    float decay = 0.0f;
    for (int j = 0; j < gp.num_life; j++) {
        decay += gp.alpha[j] * exp(-gp.t / gp.tau[j] * (1.0f + pow(gp.R0 / r, 6.0f)));
    }
    float gaus = gaus_dist(r);
    return gaus * decay;
}