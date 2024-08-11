#include <iostream>
#include <cstdlib>  // For std::abort

int main() {
    constexpr int8_t b1 = 0b000000000001111;
    constexpr int16_t b2 = 0b00000000000000000111000011110000;
    constexpr int32_t b4 = 0b0000000000000000000000000000000001110000111100001111000011110000;

    constexpr int8_t o1 = 012;  // Octal
    constexpr int16_t o2 = 04321;  // Octal
    constexpr int32_t o4 = 043210765;  // Octal

    constexpr int8_t z1 = 0x0a;  // Hexadecimal
    constexpr int16_t z2 = 0x00ab;  // Hexadecimal
    constexpr int32_t z4 = 0x0000dead;  // Hexadecimal

    if (b1 != 15) std::abort();
    if (b2 != 28912) std::abort();
    if (b4 != 1894838512) std::abort();

    if (o1 != 10) std::abort();
    if (o2 != 2257) std::abort();
    if (o4 != 9245173) std::abort();

    if (z1 != 10) std::abort();
    if (z2 != 171) std::abort();
    if (z4 != 57005) std::abort();

    return 0;
}