#include <cmath> // Include cmath for the sinh function

// Assuming you want to use float for single precision, as kind=4 in Fortran typically corresponds to single precision.
float specific_sinh_r4(float parm) {
    return std::sinh(parm);
}