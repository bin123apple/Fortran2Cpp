#include <iostream>
#include <cstdlib>
#include <cstring>

// Function prototypes
void subr();
void x(const char c1[11], float r1, const char c2[11], float r2, const char c3[11], float r3, char c4, char c5, char c6);

int main() {
    subr();
    return 0;
}

void subr() {
    char c1[11] = {0}, c2[11] = {0}, c3[11] = {0};
    float r1, r2, r3;
    char c4, c5, c6;

    c1[0] = '1';
    r1 = 1.0f;
    c1[10] = '1';
    c4 = '4';
    c2[0] = '2';
    r2 = 2.0f;
    c2[10] = '2';
    c5 = '5';
    c3[0] = '3';
    r3 = 3.0f;
    c3[10] = '3';
    c6 = '6';

    x(c1, r1, c2, r2, c3, r3, c4, c5, c6);
}

void x(const char c1[11], float r1, const char c2[11], float r2, const char c3[11], float r3, char c4, char c5, char c6) {
    if (c1[0] != '1') std::abort();
    if (r1 != 1.0f) std::abort();
    if (c1[10] != '1') std::abort();
    if (c4 != '4') std::abort();
    if (c2[0] != '2') std::abort();
    if (r2 != 2.0f) std::abort();
    if (c2[10] != '2') std::abort();
    if (c5 != '5') std::abort();
    if (c3[0] != '3') std::abort();
    if (r3 != 3.0f) std::abort();
    if (c3[10] != '3') std::abort();
    if (c6 != '6') std::abort();
}