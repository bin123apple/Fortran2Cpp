#include <iostream>
#include <vector>
#include <cmath>

// Constants namespace equivalent
namespace constants {
    const double bohr_r = 0.05291772108;
    const double hbarc = 197.326968;
    const double pi = 3.141592741012573;
    const double pi_2 = pi / 2.0;
    const double pi_4 = pi / 4.0;
}

// System namespace equivalent
namespace system_ns {
    using namespace constants;

    class SpQuantumNumbers {
    public:
        int TotalOrbits;
        std::vector<int> n, s, ms, parity;
        std::vector<double> masses, energy;
    };

    class TwoDim : public SpQuantumNumbers {
    public:
        std::vector<int> ml;
    };

    class ThreeDim : public TwoDim {
    public:
        std::vector<int> l, j, mj;
    };

    class nucleons : public ThreeDim {
    public:
        std::vector<int> t, tz;
    };

    class hyperons : public nucleons {
    public:
        std::vector<int> strange;
    };
}

int main() {
    system_ns::hyperons testHyperon;

    // Set some values
    testHyperon.TotalOrbits = 2;
    testHyperon.strange = {-1, 0};
    testHyperon.t = {1, 1};
    testHyperon.tz = {0, 1};
    testHyperon.l = {0, 1};
    testHyperon.n = {1, 2};

    // Print the values to verify
    std::cout << "TotalOrbits: " << testHyperon.TotalOrbits << std::endl;
    std::cout << "Strange Quarks: ";
    for(int s : testHyperon.strange) std::cout << s << " ";
    std::cout << std::endl;
    std::cout << "Isospin T, Tz: ";
    for(size_t i = 0; i < testHyperon.t.size(); ++i) {
        std::cout << "T: " << testHyperon.t[i] << " Tz: " << testHyperon.tz[i] << std::endl;
    }

    return 0;
}