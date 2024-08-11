#include <iostream>
#include <string>
#include <vector>

// Declaration and implementation of BUFRQEL
namespace BUFRQEL_mod {
    void BUFRQEL(const std::string& STRING, bool CMPRES, int LASTEL, int LASBIT, int N,
                 int& NEXBIT, int& SCALE, int& WIDTH, int& REFVAL, char& FORMAT,
                 std::vector<int>& DESCR, int& NLOG, int& IRC) {
        // Example implementation - adapt according to your actual subroutine's logic
        IRC = 0; // Indicate success
        NEXBIT += LASTEL; // Example operation
        std::cout << "BUFRQEL called with STRING: " << STRING << std::endl;
        // Further logic...
    }
}

// Test function for BUFRQEL
void test_BUFRQEL() {
    std::string STRING = "Test";
    bool CMPRES = true;
    int LASTEL = 10;
    int LASBIT = 5;
    int N = 1;
    int NEXBIT = 0;
    int SCALE = 1;
    int WIDTH = 2;
    int REFVAL = 3;
    char FORMAT = 'I';
    std::vector<int> DESCR = {123};
    int NLOG = 0;
    int IRC;

    // Call BUFRQEL
    BUFRQEL_mod::BUFRQEL(STRING, CMPRES, LASTEL, LASBIT, N, NEXBIT, SCALE, WIDTH, REFVAL, FORMAT, DESCR, NLOG, IRC);
    
    // Verify results (simple print statements for demonstration)
    std::cout << "After call:" << std::endl;
    std::cout << "NEXBIT: " << NEXBIT << std::endl;
    std::cout << "IRC: " << IRC << std::endl;
    // Add more checks as needed
}

int main() {
    test_BUFRQEL(); // Run the test
    return 0;
}