#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>

void YIQRGB(float& Y, float& I, float& Q, float& R, float& G, float& B) {
    R = Y + 0.956f * I + 0.621f * Q;
    G = Y - 0.272f * I - 0.647f * Q;
    B = Y - 1.105f * I + 1.702f * Q;

    R = std::min(std::max(R, 0.0f), 1.0f);
    G = std::min(std::max(G, 0.0f), 1.0f);
    B = std::min(std::max(B, 0.0f), 1.0f);
}

bool AreFloatsClose(float a, float b, float epsilon = 0.00001f) {
    return std::fabs(a - b) < epsilon;
}

void TestYIQRGB() {
    float Y, I, Q, R, G, B;

    // Adjusted test cases based on the Fortran output
    Y = 0.5f; I = 0.2f; Q = -0.3f;
    YIQRGB(Y, I, Q, R, G, B);
    assert(AreFloatsClose(R, 0.5049f) && AreFloatsClose(G, 0.6397f) && AreFloatsClose(B, 0.0f));

    Y = 0.1f; I = 0.9f; Q = 0.2f;
    YIQRGB(Y, I, Q, R, G, B);
    assert(AreFloatsClose(R, 1.0f) && AreFloatsClose(G, 0.0f) && AreFloatsClose(B, 0.0f));

    Y = 0.9f; I = -0.4f; Q = 0.6f;
    YIQRGB(Y, I, Q, R, G, B);
    assert(AreFloatsClose(R, 0.8902f) && AreFloatsClose(G, 0.6206f) && AreFloatsClose(B, 1.0f));
    
    std::cout << "All tests passed!" << std::endl;
}

int main() {
    TestYIQRGB();
    return 0;
}