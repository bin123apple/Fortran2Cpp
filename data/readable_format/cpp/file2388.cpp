#include <vector>

void sort_split_nodes(int numfn, int numelv, std::vector<std::vector<int>>& nfault, const std::vector<int>& indxiel) {
    if (numfn == 0) return;
    
    for (int i = 0; i < numfn; ++i) {
        nfault[0][i] = indxiel[nfault[0][i]];
    }
}

int main() {
    // Example usage
    int numfn = 5;
    int numelv = 10;

    // Initialize nfault as a 2D vector with 3 rows and numfn columns
    std::vector<std::vector<int>> nfault(3, std::vector<int>(numfn));
    // Initialize indxiel as a vector with numelv elements
    std::vector<int> indxiel(numelv);

    // Populate nfault and indxiel with example values
    for (int i = 0; i < numfn; ++i) {
        nfault[0][i] = i; // Example value
    }
    for (int i = 0; i < numelv; ++i) {
        indxiel[i] = i + 1; // Example value
    }

    // Call the function
    sort_split_nodes(numfn, numelv, nfault, indxiel);

    // Output the results for verification
    for (int i = 0; i < numfn; ++i) {
        std::cout << "nfault[0][" << i << "] = " << nfault[0][i] << std::endl;
    }

    return 0;
}