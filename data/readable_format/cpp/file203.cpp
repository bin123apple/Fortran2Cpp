#include <iostream>
#include <vector>

// Define the LinkedCells class within the same file
class LinkedCells {
public:
    int nboxesx, nboxesy, nboxesz;
    double xmin, ymin, zmin, xmax, ymax, zmax;
    std::vector<std::vector<std::vector<int>>> ifirstbox; // 3D vector for ifirstbox
    std::vector<int> inextbox; // 1D vector for inextbox
};

int main() {
    // Create an instance of LinkedCells
    LinkedCells cells;

    // Example initialization
    cells.nboxesx = 3;
    cells.nboxesy = 3;
    cells.nboxesz = 3;

    // "Allocate" (resize in C++) vectors to simulate array allocation
    cells.ifirstbox.resize(cells.nboxesx,
                           std::vector<std::vector<int>>(cells.nboxesy,
                                                         std::vector<int>(cells.nboxesz, 0)));
    cells.inextbox.resize(cells.nboxesx * cells.nboxesy * cells.nboxesz);

    // Fill inextbox with test values (1 to N)
    for (int i = 0; i < cells.inextbox.size(); ++i) {
        cells.inextbox[i] = i + 1;
    }

    // Simple test to verify functionality
    bool testPassed = true;
    for (int i = 0; i < cells.inextbox.size(); ++i) {
        if (cells.inextbox[i] != i + 1) {
            testPassed = false;
            break;
        }
    }

    if (testPassed) {
        std::cout << "Test passed: inextbox correctly initialized." << std::endl;
    } else {
        std::cout << "Test failed: inextbox not correctly initialized." << std::endl;
    }

    return 0;
}