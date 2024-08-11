#include <iostream>
#include <cmath>

int main() {
    const double epsilon = 1.e-5;
    double u_prec, u_cour;
    double v_prec, v_cour;
    double somme;
    const double nombre_or = (1.0 + std::sqrt(5.0)) / 2.0;

    u_prec = 1.0;
    u_cour = 1.0;

    while (true) {
        v_prec = u_cour / u_prec;
        somme = u_cour + u_prec;
        u_prec = u_cour;
        u_cour = somme;
        v_cour = u_cour / u_prec;

        if (std::abs((v_cour - v_prec) / v_prec) < epsilon) {
            break;
        }
    }

    std::cout << "Limite de la suite (vn) : " << v_cour << std::endl;
    std::cout << "Nombre d'or : " << nombre_or << std::endl;

    return 0;
}