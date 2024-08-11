#include <iostream>

class ESMF_Time {
public:
    int MM; // Assuming MM should be public for operator overloading and other operations.

    // Constructor for initialization
    ESMF_Time(int mm = 0) : MM(mm) {}

    // Operator + overloading for ESMF_Time
    ESMF_Time operator+(const ESMF_Time& rhs) const {
        // Implementing the logic from the Fortran 'add' function
        ESMF_Time result(*this); // Using the current object's state as the base for addition.
        // Assuming the actual addition should combine the MM fields in some meaningful way, 
        // but as the Fortran example doesn't do it, we'll mimic the behavior (simply returning the left operand as-is).
        return result;
    }
};

class ESMF_Clock {
public:
    ESMF_Time CurrTime; // Public for simplicity, to allow direct access like in Fortran code.

    // Assuming default constructor is sufficient.
    
    // Function to advance the clock
    void ESMF_ClockAdvance() {
        CurrTime = CurrTime + CurrTime;
    }
};

int main() {
    ESMF_Clock myClock;
    myClock.CurrTime = ESMF_Time(5); // Example initialization

    std::cout << "Current Time MM before: " << myClock.CurrTime.MM << std::endl;
    myClock.ESMF_ClockAdvance(); // Advance the clock
    std::cout << "Current Time MM after: " << myClock.CurrTime.MM << std::endl;

    return 0;
}