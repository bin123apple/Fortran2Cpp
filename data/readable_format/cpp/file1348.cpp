#include <iostream>
#include <string>

// Define the number of error messages
const int CEL_ERRMSG_COUNT = 7;

// Define and initialize the error messages array
std::string CEL_ERRMSG[CEL_ERRMSG_COUNT] = {
    "Success",
    "Null celprm pointer passed",
    "Invalid projection parameters",
    "Invalid coordinate transformation parameters",
    "Ill-conditioned coordinate transformation parameters",
    "One or more of the (x,y) coordinates were invalid",
    "One or more of the (lng,lat) coordinates were invalid"
};

// Main program to test the CEL_ERRMSG contents
int main() {
    std::cout << "Testing CEL_ERRMSG content" << std::endl;

    for (int i = 0; i < CEL_ERRMSG_COUNT; ++i) {
        std::cout << "Error " << i << ": " << CEL_ERRMSG[i] << std::endl;
    }

    return 0;
}