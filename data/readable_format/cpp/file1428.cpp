#include <vector>
#include <iostream>

class ThreeBody {
public:
    void step(const std::vector<std::vector<float>>& x) {
        // Implementation of the step subroutine
        // Since this is just a placeholder, we'll leave it empty
    }

    void run() {
        const int n = 2, d = 2;
        std::vector<std::vector<float>> x_hq(n, std::vector<float>(d));
        step(x_hq);
    }
};

int main() {
    ThreeBody simulation;
    simulation.run();

    return 0;
}