#include <iostream>
#include <array>

// Assuming ng22 is known and fixed for simplicity
constexpr int ng22 = 16; 
using rb = double; // Assuming real(kind=rb) translates to double in C++

struct rrsw_kg22 {
    static constexpr int no22 = 16;

    std::array<std::array<std::array<std::array<rb, no22>, 13>, 5>, 9> kao;
    std::array<std::array<std::array<rb, no22>, 47>, 5> kbo; // Adjusted for 0-based indexing
    std::array<std::array<rb, no22>, 10> selfrefo;
    std::array<std::array<rb, no22>, 3> forrefo;
    std::array<std::array<rb, 9>, no22> sfluxrefo;

    rb rayl;

    union {
        struct {
            std::array<std::array<std::array<std::array<rb, ng22>, 13>, 5>, 9> ka;
            std::array<std::array<std::array<rb, ng22>, 47>, 5> kb;
        };
        struct {
            std::array<rb, 585 * ng22> absa;
            std::array<rb, 235 * ng22> absb;
        };
    };

    rrsw_kg22() {
        // Constructor to handle any necessary initialization
    }
    
    // Basic test function to verify the equivalence mapping
    void test_equivalence() {
        ka[0][0][0][0] = 123.456;
        if (absa[0] != 123.456) {
            std::cerr << "Equivalence mapping failed for ka -> absa" << std::endl;
        } else {
            std::cout << "Equivalence mapping successful for ka -> absa" << std::endl;
        }
    }
};

int main() {
    rrsw_kg22 example;
    example.test_equivalence();
    return 0;
}