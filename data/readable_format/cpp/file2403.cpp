#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

int main() {
    const char* filename = "tmpfile";
    std::ofstream file;

    // Open the file in write mode (equivalent to Fortran open with status='new')
    file.open(filename, std::ios::out);
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Fortran 'pad' parameter is used to specify whether to pad short records.
    // C++ doesn't have a direct equivalent, but we can simulate checking a flag
    // Here, we assume 'yes' is 'no' in the Fortran code, so we don't pad.

    // Inquire equivalent in C++
    bool pad = false; // Equivalent of 'no' in Fortran

    // Convert boolean pad flag to string 'YES' or 'NO' for printing
    char a[4]; // 3 characters + null terminator
    std::strcpy(a, pad ? "YES" : "NO");

    // Print the value of 'a'
    std::cout << a << std::endl;

    // Close the file and delete it (equivalent to Fortran close with status='delete')
    file.close();
    std::remove(filename);

    return 0;
}