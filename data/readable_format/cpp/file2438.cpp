#include <iostream>
#include <array>
#include <cassert>

namespace rrsw_kg16 {

    constexpr std::size_t no16 = 16;
    using rb = double;

    rb rayl;
    std::array<std::array<rb, no16>, 585> absa;
    std::array<std::array<rb, no16>, 235> absb;

    void initialize() {
        rayl = 1.0;
        for (std::size_t i = 0; i < 585; ++i) {
            absa[i][0] = static_cast<rb>(i + 1);
        }
        for (std::size_t i = 0; i < 235; ++i) {
            absb[i][0] = static_cast<rb>(i + 1001);
        }
    }
}

int main() {
    using namespace rrsw_kg16;

    initialize();

    // Example test: Check values
    assert(rayl == 1.0);
    assert(absa[0][0] == 1.0);
    assert(absb[0][0] == 1001.0);

    std::cout << "rayl = " << rayl << std::endl;
    std::cout << "First element of absa: " << absa[0][0] << std::endl;
    std::cout << "First element of absb: " << absb[0][0] << std::endl;

    return 0;
}