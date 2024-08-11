#include <iostream>
#include <cmath>

void shgivens(float &A, float &B, float &C, float &S) {
    float AA = A;
    float BB = B;
    float R, U, V;

    if (std::abs(AA) > std::abs(BB)) {
        U = AA + AA;
        V = BB / U;
        if (std::abs(V) < 1.E-25) V = 0.0f;
        R = std::sqrt(0.25f + V * V) * U;
        C = AA / R;
        S = V * (C + C);

        B = S;
        A = R;
    } else {
        if (BB != 0.0f) {
            U = BB + BB;
            V = AA / U;

            if (std::abs(V) < 1.E-25) V = 0.0f;
            A = std::sqrt(0.25f + V * V) * U;
            S = BB / A;
            C = V * (S + S);

            B = 1.0f;
            if (C != 0.0f) B = 1.0f / C;
        } else {
            C = 1.0f;
            S = 0.0f;
        }
    }
}

int main() {
    float A, B, C, S;

    // Test case 1
    A = 3.0f; B = 4.0f;
    shgivens(A, B, C, S);
    std::cout << "Test 1: A = " << A << ", B = " << B << ", C = " << C << ", S = " << S << std::endl;

    // Test case 2
    A = 1.0f; B = 0.0f;
    shgivens(A, B, C, S);
    std::cout << "Test 2: A = " << A << ", B = " << B << ", C = " << C << ", S = " << S << std::endl;

    // Add more test cases as required

    return 0;
}