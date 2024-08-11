#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string fred = "1234567890123456789012345678901234567890";
    // Automatically trimmed by construction in this case, but let's be explicit
    fred.erase(fred.find_last_not_of(" ") + 1);
    int kk = fred.length(); // Equivalent to len_trim in Fortran
    // Substring starting from 4 (0-based indexing in C++) to the end
    std::string cname = fred.substr(4, kk - 4); // Equivalent to fred(5:kk) in Fortran
    std::cout << kk << ", " << cname << std::endl;
    return 0;
}