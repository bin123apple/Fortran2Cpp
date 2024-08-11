#include <iostream>
#include <array>

class m_tenstr_rrlw_kg03 {
public:
    static constexpr int no3 = 16;
    std::array<std::array<float, 9>, no3> fracrefao;

    m_tenstr_rrlw_kg03() {
        // Initialization or any necessary setup can go here
    }
};

int main() {
    m_tenstr_rrlw_kg03 obj;
    obj.fracrefao[0][0] = 123.45f;
    std::cout << "C++ fracrefao[0][0] = " << obj.fracrefao[0][0] << std::endl;
    return 0;
}