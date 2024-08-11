#include <iostream>
#include <vector>

// Define the function directly in the same file
void testg77(int n, std::vector<float>& a) {
    std::vector<float> b(n); // Assuming 'b' is used for something in your actual code
    for (int i = 1; i <= 10; i++) {
        if (i > 4) goto label100;
        std::cout << i << std::endl;
    }

    goto label200;

label100: ;
label200: return;
}

int main() {
    const int n = 10; // Example size, adjust as necessary
    std::vector<float> a(n); // Example initialization, adjust as necessary
    
    // Call the function
    testg77(n, a);
    
    // You can add additional test code here to verify the function's behavior

    return 0;
}