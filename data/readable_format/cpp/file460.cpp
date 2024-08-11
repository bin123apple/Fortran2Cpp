#include <iostream>
#include <string>

int main() {
    std::string b = "HIFROMPGI";
    // c is assigned a substring of b, starting from index 1 to 6 (inclusive in Fortran, but need to adjust for C++)
    // In C++, substr takes a starting index (0-based) and length of the substring, so for b(2:7) in Fortran, it is b.substr(1, 6) in C++
    std::string c = b.substr(1, 6);
    // a is assigned the first character of c, which is similar to c(1:1) in Fortran
    // In C++, we can directly access this using the [] operator (remembering to adjust indexing)
    char a = c[0];
    
    // Outputting the results to demonstrate
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "a: " << a << std::endl;

    return 0;
}