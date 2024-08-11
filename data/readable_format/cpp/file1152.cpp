#include <iostream>
#include <vector>

// Declaration and definition of the peak function
void peak(std::vector<float>& peaksu, float peaki, int iel, std::vector<int>& ieltmp, int& icnt) {
    if (peaki > 1.0e-05) {
        icnt++;
        peaksu[icnt - 1] = peaki; // Adjusted for 0-based indexing
        ieltmp[icnt - 1] = iel;   // Adjusted for 0-based indexing
    }
}

int main() {
    std::vector<float> peaksu(3);
    float peaki = 0.00002; // Example peak value
    int iel = 2; // Example element index
    std::vector<int> ieltmp(3);
    int icnt = 0; // Counter for peaks

    // Call the peak function
    peak(peaksu, peaki, iel, ieltmp, icnt);

    // Output the results
    std::cout << "icnt: " << icnt << std::endl;
    std::cout << "peaksu: ";
    for (int i = 0; i < icnt; ++i) {
        std::cout << peaksu[i] << " ";
    }
    std::cout << std::endl << "ieltmp: ";
    for (int i = 0; i < icnt; ++i) {
        std::cout << ieltmp[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}