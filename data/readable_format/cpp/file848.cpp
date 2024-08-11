#include <array>
#include <string>

// Using std::array to hold the error messages. The size is 3 to match the Fortran array indices 0 to 2.
std::array<std::string, 3> FITSHDR_ERRMSG = {
    "Success",
    "Null fitskey pointer-pointer passed",
    "Memory allocation failed"
};

// If you need access to FITSHDR_ERRMSG from other source files, you can declare it as extern in a header file.
// For example, in a header file (e.g., FITSHDRData.h), you can declare:
// extern std::array<std::string, 3> FITSHDR_ERRMSG;