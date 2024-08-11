#include <iostream>

namespace test_block {
    
    void suba() {
        int a = 5;
        {
            int b = a + 2;
            // Assuming you might want to do something with b, 
            // like print it, otherwise, this variable won't be necessary.
            std::cout << "Value of b in suba: " << b << std::endl;
        }
    }

    void subb() {
        // Empty, as in the original Fortran code.
    }

} // end namespace test_block

int main() {
    // Example usage
    test_block::suba();
    test_block::subb();
    return 0;
}