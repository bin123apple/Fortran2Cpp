#include <vector>

// Function to initialize the LINK array
void LTNEW(int MDIM, std::vector<std::vector<int>>& LINK) {
    // Resize the LINK array to have dimensions 2 x MDIM
    LINK.resize(2, std::vector<int>(MDIM, 0));

    // Set the first row of the LINK array to 0
    for (int i = 0; i < MDIM; ++i) {
        LINK[0][i] = 0;
    }
}

int main() {
    int MDIM = 10; // Example dimension size
    std::vector<std::vector<int>> LINK;

    // Call the LTNEW function
    LTNEW(MDIM, LINK);

    // Optional: Print the LINK array to verify
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < MDIM; ++j) {
            std::cout << LINK[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}