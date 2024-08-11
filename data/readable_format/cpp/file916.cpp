#include <cstdint>
#include <iostream>

template<typename T>
void mvbits(uint16_t source, int from, int len, T& dest, int topos) {
    // Assuming source is always an integer that can fit into 16 bits,
    // and the operation is moving 1 bit starting from position 0.
    dest = (source >> from) & ((1 << len) - 1);
}

int main() {
    int64_t i8 = 0;
    int32_t i4 = 0;
    int16_t i2 = 0;
    int8_t i1 = 0;

    mvbits(1, 0, 8, i1, 0);
    if (i1 != 1) return 1;

    mvbits(1, 0, 16, i2, 0);
    if (i2 != 1) return 2;

    mvbits(1, 0, 16, i4, 0);
    if (i4 != 1) return 3;

    mvbits(1, 0, 16, i8, 0);
    if (i8 != 1) return 4;

    return 0;
}