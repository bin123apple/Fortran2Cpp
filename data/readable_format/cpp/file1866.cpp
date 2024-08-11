#include <vector>
#include <iostream>
#include <cassert>

// Assuming kind_rb corresponds to double in C++
using rb = double;

struct m_tenstr_rrlw_cld {
    static inline rb abscld1;
    static inline std::vector<rb> absice0{2};
    static inline std::vector<std::vector<rb>> absice1{2, std::vector<rb>(5)};
    static inline std::vector<std::vector<rb>> absice2{43, std::vector<rb>(16)};
    static inline std::vector<std::vector<rb>> absice3{46, std::vector<rb>(16)};
    static inline rb absliq0;
    static inline std::vector<std::vector<rb>> absliq1{58, std::vector<rb>(16)};
};

// Test functionality
void test_m_tenstr_rrlw_cld() {
    // Initialization
    m_tenstr_rrlw_cld::abscld1 = 1.0;
    m_tenstr_rrlw_cld::absice0 = {2.0, 3.0};
    m_tenstr_rrlw_cld::absice1 = {{1.0, 2.0, 3.0, 4.0, 5.0}, {6.0, 7.0, 8.0, 9.0, 10.0}};
    m_tenstr_rrlw_cld::absliq0 = 4.0;

    // Manipulation
    m_tenstr_rrlw_cld::abscld1 += 1.0;
    m_tenstr_rrlw_cld::absice0[1] = 5.0; // Remember C++ uses 0-based indexing
    m_tenstr_rrlw_cld::absliq0 *= 2.0;

    // Assertions
    assert(m_tenstr_rrlw_cld::abscld1 == 2.0);
    assert(m_tenstr_rrlw_cld::absice0[1] == 5.0);
    assert(m_tenstr_rrlw_cld::absliq0 == 8.0);

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    test_m_tenstr_rrlw_cld();
    return 0;
}