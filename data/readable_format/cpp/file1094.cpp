#include <iostream>
#include <vector>
#include <string>

void save_in_electrons(int iter, double dr2) {
    // Mock conditions
    bool conv_elec = true;
    std::vector<std::vector<double>> et = {{1.0, 2.0}, {3.0, 4.0}};
    std::vector<double> vnew = {0.1, 0.2, 0.3};
    double etot = 100.0, tr2 = 1.0, ethr = 0.5;
    std::string where;

    // Logic for save_in_electrons (simplified)
    if (conv_elec) {
        where = "IONS";
        std::cout << where << std::endl;
        for (auto& row : et) {
            for (auto& val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << etot << " " << tr2 << std::endl;
        for (auto& val : vnew) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } else {
        where = "ELECTRONS";
        std::cout << where << std::endl;
    }
}

int main() {
    save_in_electrons(1, 0.25);
    return 0;
}