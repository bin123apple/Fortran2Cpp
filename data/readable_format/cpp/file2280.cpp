#include <array>
#include <algorithm>

const int LENRLS = 218;
const int LENILS = 33;

std::array<float, LENRLS> RLS;
std::array<int, LENILS> ILS;

void RSCO(const std::array<float, LENRLS>& RSAV, const std::array<int, LENILS>& ISAV) {
    std::copy(RSAV.begin(), RSAV.end(), RLS.begin());
    std::copy(ISAV.begin(), ISAV.end(), ILS.begin());
}