#include <iostream>
#include <array>

// Assuming these mappings from the Fortran kinds
using rb = float; // Real(kind=rb)
using im = int;   // Integer(kind=im)

class rrlw_kg03 {
public:
    static constexpr im no3 = 16;
    static constexpr im ng3 = 16;

    std::array<std::array<rb, 9>, no3> fracrefao;
    std::array<std::array<rb, 5>, no3> fracrefbo;
    std::array<std::array<std::array<std::array<rb, no3>, 13>, 5>, 9> kao;
    std::array<std::array<std::array<std::array<rb, no3>, 47>, 5>, 5> kbo; // Adjusted for 0-based and contiguous storage.
    std::array<std::array<std::array<rb, no3>, 19>, 9> kao_mn2o;
    std::array<std::array<std::array<rb, no3>, 19>, 5> kbo_mn2o;
    std::array<std::array<rb, no3>, 10> selfrefo;
    std::array<std::array<rb, no3>, 4> forrefo;

    std::array<std::array<rb, 9>, ng3> fracrefa;
    std::array<std::array<rb, 5>, ng3> fracrefb;
    std::array<std::array<std::array<std::array<rb, ng3>, 13>, 5>, 9> ka;
    std::array<std::array<rb, ng3>, 585> absa; // Flattened representation.
    std::array<std::array<std::array<std::array<rb, ng3>, 47>, 5>, 5> kb; // Adjusted for 0-based and contiguous storage.
    std::array<std::array<rb, ng3>, 1175> absb; // Flattened representation.
    std::array<std::array<std::array<rb, ng3>, 19>, 9> ka_mn2o;
    std::array<std::array<std::array<rb, ng3>, 19>, 5> kb_mn2o;
    std::array<std::array<rb, ng3>, 10> selfref;
    std::array<std::array<rb, ng3>, 4> forref;
};

int main() {
    rrlw_kg03 obj;

    // Example test: Assign some values
    obj.fracrefao[0][0] = 1.0f;
    obj.fracrefbo[0][0] = 2.0f;
    obj.kao[0][0][0][0] = 3.0f;
    obj.kbo[0][0][0][0] = 4.0f;
    obj.selfrefo[0][0] = 5.0f;
    obj.forrefo[0][0] = 6.0f;

    // Verify the assigned values
    bool passed = true;
    passed &= (obj.fracrefao[0][0] == 1.0f);
    passed &= (obj.fracrefbo[0][0] == 2.0f);
    passed &= (obj.kao[0][0][0][0] == 3.0f);
    passed &= (obj.kbo[0][0][0][0] == 4.0f);
    passed &= (obj.selfrefo[0][0] == 5.0f);
    passed &= (obj.forrefo[0][0] == 6.0f);

    if (passed) {
        std::cout << "C++ Test Passed" << std::endl;
    } else {
        std::cout << "C++ Test Failed" << std::endl;
    }

    return 0;
}