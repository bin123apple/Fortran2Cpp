#include <iostream>
#include <cassert>

// Define the ModExtras namespace directly in this file
namespace ModExtras {
    
    const int GSM_ = 1;
    const int GSE_ = 2;
    bool north = true;
    const int MaxInputLines = 1000;

} // End of ModExtras namespace

int main() {
    // Test constants
    assert(ModExtras::GSM_ == 1);
    std::cout << "Test GSM_: Passed" << std::endl;
    
    assert(ModExtras::GSE_ == 2);
    std::cout << "Test GSE_: Passed" << std::endl;
    
    // Test variable
    assert(ModExtras::north == true);
    std::cout << "Test north (true): Passed" << std::endl;
    
    // Test MaxInputLines
    assert(ModExtras::MaxInputLines == 1000);
    std::cout << "Test MaxInputLines: Passed" << std::endl;
    
    std::cout << "All tests passed." << std::endl;
    
    return 0;
}