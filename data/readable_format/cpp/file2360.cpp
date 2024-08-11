#include <iostream>
#include <bitset>

// Function to simulate the behavior of the Fortran IRBIT2 function
int IRBIT2(int &ISEED) {
    const int IB1 = 1;
    const int IB2 = 2;
    const int IB5 = 16;
    const int IB18 = 131072;
    const int MASK = IB1 + IB2 + IB5;

    if (ISEED & IB18) {
        ISEED = ((ISEED ^ MASK) << 1) | IB1;
        return 1;
    } else {
        ISEED = (ISEED << 1) & ~IB1;
        return 0;
    }
}

int main() {
    int seed = 12345; // Example seed value
    int result = IRBIT2(seed);
    
    std::cout << "Result: " << result << std::endl;
    std::cout << "New seed value: " << seed << std::endl;

    return 0;
}