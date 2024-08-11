#include <iostream>
#include <cassert>

struct parameters {
    static constexpr int ntypx = 10;
    static constexpr int npsx = ntypx;
    static constexpr int npk = 40000;
    static constexpr int lmaxx = 3;
    static constexpr int nchix = 6;
    static constexpr int ndmx = 2000;

    static constexpr int nbrx = 28;
    static constexpr int lqmax = 2 * lmaxx + 1;
    static constexpr int nqfx = 8;

    static constexpr int nacx = 10;
    static constexpr int nsx = ntypx;
    static constexpr int natx = 5000;
    static constexpr int npkx = npk;
    static constexpr int ncnsx = 101;
    static constexpr int nspinx = 2;
    static constexpr int nhclm = 4;
    static constexpr int max_nconstr = 100;
};

void testParameters() {
    assert(parameters::ntypx == 10);
    assert(parameters::npsx == 10);
    assert(parameters::npk == 40000);
    // Continue for each parameter...
    assert(parameters::max_nconstr == 100);

    // If the program reaches this point, all tests passed
    std::cout << "All tests passed." << std::endl;
}

int main() {
    testParameters();
    return 0;
}