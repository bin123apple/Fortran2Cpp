#include <cstdint>

int main() {
    bool l1;
    bool l2;
    bool l4;
    int8_t i1;
    int16_t i2;
    int32_t i4;

    i1 = true;
    i2 = true;
    i4 = true;

    i1 = false;
    i2 = false;
    i4 = false;

    // In C++, you cannot directly assign between integers and booleans like in Fortran.
    // So, we will use ternary operators to achieve a similar effect.
    // The following assignments convert boolean to integer by using ternary operators.
    i1 = l1 ? 1 : 0;
    i2 = l1 ? 1 : 0;
    i4 = l1 ? 1 : 0;

    i1 = l2 ? 1 : 0;
    i2 = l2 ? 1 : 0;
    i4 = l2 ? 1 : 0;

    i1 = l4 ? 1 : 0;
    i2 = l4 ? 1 : 0;
    i4 = l4 ? 1 : 0;

    // The following assignments convert integer to boolean.
    // In C++, any non-zero value is true, and zero is false.
    l1 = i1 != 0;
    l2 = i1 != 0;
    l4 = i1 != 0;

    l1 = i2 != 0;
    l2 = i2 != 0;
    l4 = i2 != 0;

    l1 = i4 != 0;
    l2 = i4 != 0;
    l4 = i4 != 0;

    return 0;
}