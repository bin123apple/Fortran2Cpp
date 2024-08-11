#include <iostream>
#include <array>

class XLAENV {
public:
    void operator()(int ISPEC, int NVALUE);
    static int getIPARMSValue(int index); // Public method to access IPARMS values

private:
    static std::array<int, 100> IPARMS;
};

// Initialize the static member variable
std::array<int, 100> XLAENV::IPARMS = {0};

void XLAENV::operator()(int ISPEC, int NVALUE) {
    if (ISPEC >= 1 && ISPEC <= 9) {
        IPARMS[ISPEC] = NVALUE;
    }
}

int XLAENV::getIPARMSValue(int index) {
    if (index >= 0 && index < 100) {
        return IPARMS[index];
    } else {
        // Handle out-of-range index if necessary
        return -1; // Return an invalid value or handle it as per your need
    }
}

void printIPARMS(int index) {
    std::cout << "IPARMS(" << index << ") = " << XLAENV::getIPARMSValue(index) << std::endl;
}

int main() {
    XLAENV xlaenv;

    // Test case 1: Set ISPEC = 5, NVALUE = 10
    xlaenv(5, 10);
    printIPARMS(5);  // Should print 10

    // Test case 2: Set ISPEC = 3, NVALUE = 20
    xlaenv(3, 20);
    printIPARMS(3);  // Should print 20

    // Test case 3: Set ISPEC = 10, NVALUE = 30 (out of range)
    xlaenv(10, 30);
    printIPARMS(10);  // Should print 0 (since ISPEC is out of range and index 10 is not set)

    return 0;
}