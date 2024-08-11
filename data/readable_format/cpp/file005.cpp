#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>

class Param {
public:
    static const int ACCU = std::numeric_limits<double>::digits10; // Closest equivalent
    static const int ALL_MF = 42;
    static const double MU_TOLERANCE;
    static const double DGEN_TOLERANCE;

    struct Rotor {
        double A, B, C;
    };

    struct Potential {
        double Vj, Vk, Vm;
    };

    static bool is_linear(const Rotor& mol) {
        return mol.A > 0.0 || mol.C > 0.0 ? false : true;
    }

    static void set_k_limit(int k) {
        if (k != 0 && k != 4) {
            throw std::invalid_argument("set_k_limit(): Only K=0 or K=4 supported at the moment");
        }
        K_LIMIT = k;
    }

    static int get_k_limit() {
        return K_LIMIT;
    }

    static void setdim(int i) {
        dim = i;
    }

    static int getdim() {
        return dim;
    }

private:
    static int dim;
    static int K_LIMIT;
};

const double Param::MU_TOLERANCE = 1e-4;
const double Param::DGEN_TOLERANCE = 1e-9;
int Param::dim = 0;
int Param::K_LIMIT = 4;

int main() {
    try {
        // Test is_linear
        Param::Rotor mol = {0.0, 1.0, 0.0};
        std::cout << "Test is_linear with linear molecule: "
                  << (Param::is_linear(mol) ? "PASSED" : "FAILED") << std::endl;

        mol = {1.0, 1.0, 2.0};
        std::cout << "Test is_linear with non-linear molecule: "
                  << (!Param::is_linear(mol) ? "PASSED" : "FAILED") << std::endl;

        // Test set_k_limit and get_k_limit
        Param::set_k_limit(4);
        std::cout << "Test set_k_limit/get_k_limit: "
                  << (Param::get_k_limit() == 4 ? "PASSED" : "FAILED") << std::endl;

        // Test setdim and getdim
        Param::setdim(10);
        std::cout << "Test setdim/getdim: "
                  << (Param::getdim() == 10 ? "PASSED" : "FAILED") << std::endl;

        // Edge case for set_k_limit
        try {
            Param::set_k_limit(3); // This should throw
            std::cout << "Test set_k_limit with invalid value: FAILED" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Test set_k_limit with invalid value: PASSED" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}