#include <iostream>
#include <vector>

// Declare the inbody function
void inbody(std::vector<int>& irpb, int& n9, const std::vector<int>& iin, int ifound, bool& addold, bool& noroom, int mr) {
    noroom = true;
    if (!addold) n9 = 0;

    for (int i = 0; i < ifound; ++i) {
        int jj = iin[i];
        if (jj == 0) break; // Exit the loop
        if (n9 + 1 > mr) return; // No room for another element

        bool found = false;
        for (int j = 0; j < n9; ++j) {
            if (irpb[j] == jj) {
                found = true; // Element found, skip adding
                break;
            }
        }
        if (!found) {
            irpb[n9] = jj;
            n9++;
        }
    }
    noroom = false;
}

// Test function for the inbody function
void test_inbody() {
    std::vector<int> irpb(10, 0); // Assuming MR = 10
    int n9 = 0;
    std::vector<int> iin = {1, 2, 3, 4, 0}; // Example input
    bool addold = false;
    bool noroom;
    int mr = 10;

    inbody(irpb, n9, iin, iin.size(), addold, noroom, mr);

    // Output the results for verification
    std::cout << "Test InBody - Results:" << std::endl;
    std::cout << "n9: " << n9 << std::endl;
    std::cout << "irpb: ";
    for (int i = 0; i < n9; ++i) {
        std::cout << irpb[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "noroom: " << std::boolalpha << noroom << std::endl;
}

// Main function to run the test
int main() {
    test_inbody();
    return 0;
}