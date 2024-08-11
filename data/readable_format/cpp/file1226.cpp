#include <cstdlib> // For std::abort()

// Function prototype declaration
void mySub(int myInt);

int main() {
    int myInt = 10;

    mySub(myInt);

    if (myInt != 10) {
        std::abort(); // Abort the program if myInt is not equal to 10
    }

    return 0;
}

void mySub(int myInt) {
    myInt = 11; // This modification affects only the local copy
}