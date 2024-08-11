#include <iostream>

class MOD_Exactfunc_Vars {
public:
    static float OmegaRef;
};

// Initialize the static member of MOD_Exactfunc_Vars
float MOD_Exactfunc_Vars::OmegaRef = 0;

int main() {
    // Set OmegaRef to a test value
    MOD_Exactfunc_Vars::OmegaRef = 5.0f;

    std::cout << "Testing OmegaRef..." << std::endl;
    // Check if OmegaRef holds the correct value
    if (MOD_Exactfunc_Vars::OmegaRef == 5.0f) {
        std::cout << "Test PASS: OmegaRef set and retrieved successfully." << std::endl;
    } else {
        std::cout << "Test FAIL: OmegaRef value incorrect." << std::endl;
    }

    return 0;
}