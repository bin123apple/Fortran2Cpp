#include <iostream>

// Function prototype
void test(float x, float& y, float& z);

int main() {
    float xx, yy, zz;

    xx = 10.0f;
    zz = 15.678f;

    test(xx, yy, zz);

    std::cout << "xx= " << xx << " yy= " << yy << " zz= " << zz << std::endl;

    return 0;
}

void test(float x, float& y, float& z) {
    z = 19.0f;
    y = z * x;
}