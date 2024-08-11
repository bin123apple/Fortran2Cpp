#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SpeciesNetwork {
private:
    static const int max_species = 10;
    vector<string> species_names;
    vector<int> atomic_numbers;
    int num_species;

public:
    SpeciesNetwork() : num_species(0) {
        species_names.resize(max_species);
        atomic_numbers.resize(max_species);
    }

    void init_network() {
        species_names[0] = "Hydrogen";
        atomic_numbers[0] = 1;
        species_names[1] = "Helium";
        atomic_numbers[1] = 2;
        num_species = 2;
    }

    int find_species_index(const string& name) {
        for (int i = 0; i < num_species; ++i) {
            if (species_names[i] == name) {
                return i + 1; // Adjusting index to match Fortran's 1-based indexing
            }
        }
        return 0; // If not found, return 0
    }
};

void test_species_network() {
    SpeciesNetwork network;
    network.init_network();

    cout << "Testing SpeciesNetwork:" << endl;
    cout << "Index of 'Hydrogen': " << network.find_species_index("Hydrogen") << endl;
    cout << "Index of 'Helium': " << network.find_species_index("Helium") << endl;
    cout << "Index of 'Oxygen' (expected to be 0): " << network.find_species_index("Oxygen") << endl;
}

int main() {
    test_species_network();
    return 0;
}