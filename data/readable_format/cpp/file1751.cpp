#include <iostream>
#include <vector>

// Declarations
void allocate_pert();
void deallocate_pert();

int nat; // Example: global variable definition
int npertx;

std::vector<std::vector<std::vector<std::vector<double>>>> t;
std::vector<std::vector<std::vector<double>>> tmq;

void allocate_pert() {
    t.resize(npertx);
    for (int i = 0; i < npertx; ++i) {
        t[i].resize(npertx);
        for (int j = 0; j < npertx; ++j) {
            t[i][j].resize(48);
            for (int k = 0; k < 48; ++k) {
                t[i][j][k].resize(3 * nat);
            }
        }
    }

    tmq.resize(npertx);
    for (int i = 0; i < npertx; ++i) {
        tmq[i].resize(npertx);
        for (int j = 0; j < npertx; ++j) {
            tmq[i][j].resize(3 * nat);
        }
    }
}

void deallocate_pert() {
    t.clear();
    tmq.clear();
    // Optionally, to ensure memory is freed immediately, you can use the swap trick
    std::vector<std::vector<std::vector<std::vector<double>>>>().swap(t);
    std::vector<std::vector<std::vector<double>>>().swap(tmq);
}

// Test function
void test_allocation_deallocation() {
    try {
        allocate_pert();
        std::cout << "Allocation successful." << std::endl;
        deallocate_pert();
        std::cout << "Deallocation successful." << std::endl;
    } catch (...) {
        std::cout << "An exception occurred." << std::endl;
    }
}

int main() {
    // Initialize test variables
    nat = 10;
    npertx = 5;

    test_allocation_deallocation();

    return 0;
}