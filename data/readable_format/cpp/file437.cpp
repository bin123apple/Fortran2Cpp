#include <iostream>
#include <string>
#include <cctype> // For std::isdigit

void sla__IDCHI(std::string& STRING, int& NPTR, int& NVEC, double& DIGIT) {
    const int NCREC = 14;
    char KCTAB[NCREC] = {'0','1','2','3','4','5','6','7','8','9',' ','+','-','\0'}; // '\0' for comma since C++ treats strings differently
    int KVTAB[NCREC] = {1,1,1,1,1,1,1,1,1,1,2,3,4,5};
    
    if (NPTR < 1 || NPTR > static_cast<int>(STRING.length())) {
        NVEC = 7;
    } else {
        char K = STRING[NPTR - 1]; // Adjust index for 0-based array
        
        for (int NCHAR = 0; NCHAR < NCREC; ++NCHAR) {
            if (K == KCTAB[NCHAR]) {
                NVEC = KVTAB[NCHAR];
                DIGIT = static_cast<double>(NCHAR); // Adjusted to 0-based index, no need to subtract 1
                goto ExitLoop; // Used goto for direct translation, consider refactoring
            }
        }
        
        if (K == '\t') { // Assuming the tab character ('\t') was intended for CHAR(9) comparison
            NVEC = 2;
        } else {
            NVEC = 6;
        }
        
    ExitLoop:
        NPTR += 1;
    }
}

int main() {
    std::string STRING;
    int NPTR, NVEC;
    double DIGIT;

    // Test 1
    STRING = "1234";
    NPTR = 1;
    sla__IDCHI(STRING, NPTR, NVEC, DIGIT);
    std::cout << "Test 1: " << NVEC << " " << DIGIT << " " << NPTR << std::endl;

    // Test 2
    STRING = "9+,- ";
    NPTR = 2;
    sla__IDCHI(STRING, NPTR, NVEC, DIGIT);
    std::cout << "Test 2: " << NVEC << " " << DIGIT << " " << NPTR << std::endl;

    // Test 3
    STRING = "\tTab test"; // Representing a tab character at the start
    NPTR = 1;
    sla__IDCHI(STRING, NPTR, NVEC, DIGIT);
    std::cout << "Test 3: " << NVEC << " " << DIGIT << " " << NPTR << std::endl;

    return 0;
}