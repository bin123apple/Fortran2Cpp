#include <iostream>
#include <vector>

void applympc(std::vector<double>& vfa) {
    for (size_t i = 0; i < vfa.size(); ++i) {
        if (i % 2 == 0) {
            vfa[i] += 1.0;
        } else {
            vfa[i] -= 1.0;
        }
    }
}

int main() {
    std::vector<double> vfa = {0.0, 1.0, 2.0, 3.0};

    applympc(vfa);

    for (size_t i = 0; i < vfa.size(); ++i) {
        std::cout << "vfa[" << i << "] = " << vfa[i] << std::endl;
    }

    return 0;
}