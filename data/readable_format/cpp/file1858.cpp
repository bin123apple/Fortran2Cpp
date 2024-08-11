#include <iostream>
#include <array>
#include <cstdint>

namespace rrlw_kg04 {

    constexpr std::int32_t no4 = 16;
    constexpr std::int32_t ng4 = 14;

    struct module {
        std::array<std::array<double, 9>, no4> fracrefao{};
        std::array<std::array<double, 5>, no4> fracrefbo{};
        std::array<std::array<std::array<std::array<double, no4>, 13>, 5>, 9> kao{};
        std::array<std::array<std::array<std::array<double, no4>, 47>, 5>, 5> kbo{};
        std::array<std::array<double, no4>, 10> selfrefo{};
        std::array<std::array<double, no4>, 4> forrefo{};

        std::array<std::array<double, 9>, ng4> fracrefa{};
        std::array<std::array<double, 5>, ng4> fracrefb{};

        std::array<std::array<double, ng4>, 10> selfref{};
        std::array<std::array<double, ng4>, 4> forref{};

        std::array<std::array<double, 585>, ng4> absa{};
        std::array<std::array<double, 1175>, ng4> absb{};

        struct ka_kb_equivalence {
            union {
                std::array<std::array<std::array<std::array<double, ng4>, 13>, 5>, 9> ka;
                std::array<std::array<double, 585>, ng4> absa;
            };
            union {
                std::array<std::array<std::array<std::array<double, ng4>, 47>, 5>, 5> kb;
                std::array<std::array<double, 1175>, ng4> absb;
            };
        } equivalence;
    };
}

int main() {
    rrlw_kg04::module m;

    // Initialize some values
    m.fracrefao[0][0] = 1.0;
    m.fracrefbo[0][0] = 2.0;
    m.kao[0][0][0][0] = 3.0;
    m.kbo[0][0][0][0] = 4.0;
    m.selfrefo[0][0] = 5.0;
    m.forrefo[0][0] = 6.0;

    m.fracrefa[0][0] = 7.0;
    m.fracrefb[0][0] = 8.0;
    m.equivalence.ka[0][0][0][0] = 9.0;
    m.equivalence.absa[0][0] = 10.0; // This should also change ka[0][0][0][0] due to equivalence
    m.equivalence.kb[0][0][0][0] = 11.0;
    m.equivalence.absb[0][0] = 12.0; // This should also change kb[0][0][0][0] due to equivalence
    m.selfref[0][0] = 13.0;
    m.forref[0][0] = 14.0;

    // Print values to verify
    std::cout << "fracrefao[0][0] = " << m.fracrefao[0][0] << std::endl;
    std::cout << "fracrefbo[0][0] = " << m.fracrefbo[0][0] << std::endl;
    std::cout << "kao[0][0][0][0] = " << m.kao[0][0][0][0] << std::endl;
    std::cout << "kbo[0][0][0][0] = " << m.kbo[0][0][0][0] << std::endl;
    std::cout << "selfrefo[0][0] = " << m.selfrefo[0][0] << std::endl;
    std::cout << "forrefo[0][0] = " << m.forrefo[0][0] << std::endl;

    std::cout << "fracrefa[0][0] = " << m.fracrefa[0][0] << std::endl;
    std::cout << "fracrefb[0][0] = " << m.fracrefb[0][0] << std::endl;
    std::cout << "ka[0][0][0][0] = " << m.equivalence.ka[0][0][0][0] << std::endl; // Should reflect change due to absa
    std::cout << "absa[0][0] = " << m.equivalence.absa[0][0] << std::endl;
    std::cout << "kb[0][0][0][0] = " << m.equivalence.kb[0][0][0][0] << std::endl; // Should reflect change due to absb
    std::cout << "absb[0][0] = " << m.equivalence.absb[0][0] << std::endl;
    std::cout << "selfref[0][0] = " << m.selfref[0][0] << std::endl;
    std::cout << "forref[0][0] = " << m.forref[0][0] << std::endl;

    return 0;
}