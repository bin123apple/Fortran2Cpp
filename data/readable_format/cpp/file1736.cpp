#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <omp.h>

void putevalfv(const std::string& fext, int ik, std::vector<std::vector<double>>& evalfv) {
    std::string filename = "EVALFV" + fext;
    std::fstream file(filename, std::ios::out | std::ios::binary | std::ios::in | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return; // It's safe to return here as we're not within an OMP block
    }

    #pragma omp critical(u120)
    {
        file.seekp((ik-1) * sizeof(double) * evalfv.size() * evalfv[0].size(), std::ios::beg);

        // Write your data here. This is a simplified example; you'll need to serialize your data properly.
        for (auto& row : evalfv) {
            for (auto& val : row) {
                file.write(reinterpret_cast<const char*>(&val), sizeof(double));
            }
        }
    }

    file.close();
}

int main() {
    std::string fext = ".test";
    int ik = 1;

    // Example data
    std::vector<std::vector<double>> evalfv = {
        {1.1, 1.2},
        {2.1, 2.2}
    };

    // Example usage of putevalfv within the same file
    putevalfv(fext, ik, evalfv);

    std::cout << "Test executed, check the EVALFV" + fext + " file for output." << std::endl;
    return 0;
}