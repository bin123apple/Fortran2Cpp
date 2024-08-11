#include <cstdint> // For std::int16_t

// Assuming XXTARH is a constant known at compile time
const int XXTARH = /* some value */;

// Define a struct that mimics the Fortran common block
struct TARS {
    std::int16_t FTAR;
    std::int16_t TARHIB;
    std::int16_t TARBUF[XXTARH]; // Fixed-size array, size must be known at compile time
};

// Declare a global instance of the struct
TARS tars;

// Now, you can access FTAR, TARHIB, and TARBUF through the global 'tars' instance
// For example:
// tars.FTAR = 123;
// tars.TARHIB = 456;
// tars.TARBUF[0] = 789;