// File: getcount.cpp

#include <iostream>
#include <string>
#include <cassert>

void getcount(int& num, const std::string& linechars) {
    for (int i = num - 1; i >= 0; --i) {
        if (linechars[i] != ' ') {
            num = i + 1; // Adjusting back to 1-based indexing for compatibility
            return;
        }
    }
    num = -1; // Adjusting for Fortran-like behavior
}

int main() {
    {
        std::string linechars = "Hello, World!            ";
        int num = linechars.find_last_not_of(" ") + 1; // Mimic Fortran's behavior
        getcount(num, linechars);
        assert(num == 13);
        std::cout << "Test 1 passed." << std::endl;
    }

    {
        std::string linechars = "Fortran77Programming";
        int num = linechars.find_last_not_of(" ") + 1;
        getcount(num, linechars);
        assert(num == 20);
        std::cout << "Test 2 passed." << std::endl;
    }

    {
        std::string linechars = "                                                            ";
        int num = linechars.find_last_not_of(" ") + 1; // This will be 0 since the string is all spaces
        getcount(num, linechars);
        assert(num == -1);
        std::cout << "Test 3 passed." << std::endl;
    }

    {
        std::string linechars = "";
        int num = linechars.find_last_not_of(" ") + 1; // This will be 0 since the string is empty
        getcount(num, linechars);
        assert(num == -1);
        std::cout << "Test 4 passed." << std::endl;
    }

    return 0;
}