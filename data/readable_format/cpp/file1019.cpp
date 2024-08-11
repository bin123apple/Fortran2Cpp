#include <iostream>
#include <string>

int main() {
    // In C++, std::string is more commonly used than character arrays.
    std::string string = "          "; // 10 spaces, equivalent to uninitialized character array in Fortran
    std::string substring;

    // Assuming 'string' is later assigned or manipulated before this operation
    // Copying characters 2 to 6 from 'string' to 'substring'
    // Note: The index in the substr function starts from 0 and the second parameter is the length of the substring.
    // So, to get the same effect as Fortran string(2:6), we start from index 1 and take a length of 5.
    substring = string.substr(1, 5);

    // Optional: Output the substring to verify
    std::cout << "Substring: '" << substring << "'" << std::endl;

    return 0;
}