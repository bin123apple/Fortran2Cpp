#include <iostream>
#include <bitset>
#include <algorithm>

void mvbits(unsigned int* src, int srcPos, int len, unsigned int* dest, int destPos) {
    // Extract the bits from the source
    unsigned int mask = ((1U << len) - 1) << srcPos;
    unsigned int bits = (*src & mask) >> srcPos;
    
    // Clear the corresponding bits in the destination
    *dest &= ~(((1U << len) - 1) << destPos);

    // Set the bits in the destination
    *dest |= (bits << destPos);
}

int main() {
    unsigned int a[2] = {1, 1};  // Initialized both elements to 1
    unsigned int b[2] = {0, 0};  // Initialized both elements to 0
    unsigned int x = 1;
    unsigned int y = 0;

    mvbits(a, 0, 1, b, 1);
    mvbits(&x, 0, 1, &y, 1);

    bool arraysEqual = std::equal(std::begin(b), std::end(b), std::bitset<sizeof(y) * 8>(y).to_string().begin());

    if (!arraysEqual) {
        std::cerr << "STOP 1" << std::endl;
        return 1;
    }

    return 0;
}