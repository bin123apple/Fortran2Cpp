#include <iostream>
#include <vector>
#include <string>

// Function to mirror the Fortran subroutine 'networkinum'
void networkinum(std::vector<int>& ipkon, std::vector<int>& inum, std::vector<int>& kon, 
                 const std::vector<std::string>& lakon, int ne, std::vector<int>& itg, 
                 int ntg, int network) {
    
    for (int i = 0; i < ntg; i++) {
        if (inum[itg[i]-1] > 0) inum[itg[i]-1] = -inum[itg[i]-1];
    }

    for (int i = 0; i < ne; i++) {
        if (ipkon[i] < 0) continue;
        std::string lakonl = lakon[i];
        if ((lakonl[0] != 'D') && ((lakonl[0] != 'D') || (network != 1))) continue;

        int indexe = ipkon[i] - 1; // Adjust for 0-based indexing
        if (kon[indexe + 1] != 0) {
            int node1 = kon[indexe + 1] - 1; // Adjust for 0-based indexing
            if (inum[node1] > 0) inum[node1] = -inum[node1];
        }
        int node2 = kon[indexe + 2] - 1; // Adjust for 0-based indexing
        if (inum[node2] > 0) inum[node2] = -inum[node2];
        
        if (kon[indexe + 3] != 0) {
            int node3 = kon[indexe + 3] - 1; // Adjust for 0-based indexing
            if (inum[node3] > 0) inum[node3] = -inum[node3];
        }
    }
}

// Unit test to verify the functionality of networkinum
void testNetworkinum() {
    std::vector<int> ipkon = {1, 4};
    std::vector<int> inum = {2, -3};
    std::vector<int> kon = {1, 2, 0, 2, 3, 0};
    std::vector<std::string> lakon = {"D0000001", "D0000002"};
    int ne = 2;
    std::vector<int> itg = {1, 2};
    int ntg = 2;
    int network = 1;

    // Call the function
    networkinum(ipkon, inum, kon, lakon, ne, itg, ntg, network);

    // Output the results for checking
    std::cout << "Modified inum: ";
    for (int num : inum) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    testNetworkinum();
    return 0;
}