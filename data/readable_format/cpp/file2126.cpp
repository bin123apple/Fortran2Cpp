#include <iostream>
#include <vector>
#include <memory>

// Function definition
void tq_tvgh(float& t, const float& p) {
    t = p;
}

int main() {
    int jplev = 42;
    int k_lev = 1;

    std::vector<float> p(jplev);
    std::unique_ptr<float[]> q(new float[jplev]);

    for (int i = k_lev - 1; i < jplev; ++i) {
        tq_tvgh(q[i], p[i]);
    }

    // No need to explicitly deallocate q, as unique_ptr will handle it automatically
    return 0;
}