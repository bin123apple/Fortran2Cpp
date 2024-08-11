#include <iostream>
#include <array>

struct g1 {
    std::array<long long, 3> a;
    std::array<double, 3> r;
};

int main() {
    g1 s1, s2;
    int me = 2; // Simulate process 2

    // Initialize s1 with values that would come from process 3
    for (int i = 0; i < 3; ++i) {
        s1.a[i] = (i + 1) * 3;
        s1.r[i] = 1.0 / (i + 1) / 3;
    }

    // Simulate receiving s1 into s2 on process 2
    if (me == 2) {
        s2 = s1;
    }

    // Output for verification
    for (int i = 0; i < 3; ++i) {
        std::cout << "s2.a[" << i << "] = " << s2.a[i] << ", s2.r[" << i << "] = " << s2.r[i] << std::endl;
    }

    return 0;
}