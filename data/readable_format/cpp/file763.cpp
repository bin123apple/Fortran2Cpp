#include <iostream>
#include <array>
#include <vector>

int main() {
    std::array<float, 5> arreglo_1;
    std::array<float, 5> arreglo_2 = {1, 2, 3, 4, 5};
    std::array<std::array<int, 5>, 5> matriz;
    std::array<int, 5> arreglo_3;
    std::array<std::array<int, 6>, 5> matriz_2;
    std::array<std::array<int, 4>, 4> matriz_3;

    std::cout << "Posición 1 de arreglo_1: " << arreglo_1[0] << std::endl;
    std::cout << "Posición (2, 6) de matriz_2: " << matriz_2[2][5] << std::endl;

    std::cout << "matriz_3(1:4:1): ";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << matriz_3[i][j] << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "matriz_3(1:4:1): ";
    for (int i = 0; i < 4; ++i) {
        for (int j = 3; j >= 0; --j) {
            std::cout << matriz_3[i][j] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}