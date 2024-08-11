#include <iostream>
#include <vector>
#include <string>

class Configuration {
public:
    int natoms = 0;
    std::vector<float> xmass;

    void init_atoms(int n) {
        natoms = n;
        xmass.resize(natoms);
        for (int i = 0; i < natoms; ++i) {
            xmass[i] = static_cast<float>(i + 1); // Just an example; modify as needed
        }
    }

    void print_first_atom_mass() const {
        if (!xmass.empty()) {
            std::cout << "xmass[0]: " << xmass[0] << std::endl;
        }
    }
};

// Function prototypes for any additional tests you might want to add
void test_init_atoms();
void test_print_first_atom_mass();

int main() {
    // Run your tests
    test_init_atoms();
    test_print_first_atom_mass();

    return 0;
}

void test_init_atoms() {
    std::cout << "Testing init_atoms..." << std::endl;
    Configuration config;
    config.init_atoms(10);
    if (config.natoms == 10 && config.xmass.size() == 10) {
        std::cout << "test_init_atoms passed." << std::endl;
    } else {
        std::cout << "test_init_atoms failed." << std::endl;
    }
}

void test_print_first_atom_mass() {
    std::cout << "Testing print_first_atom_mass..." << std::endl;
    Configuration config;
    config.init_atoms(1); // Ensure there's at least one atom to print
    config.print_first_atom_mass(); // This will output the mass of the first atom
    // This test function primarily checks for runtime errors when calling print_first_atom_mass.
    // Since it outputs to the console, we can't automatically verify its output here without additional mechanisms.
    std::cout << "test_print_first_atom_mass done. Check output manually." << std::endl;
}