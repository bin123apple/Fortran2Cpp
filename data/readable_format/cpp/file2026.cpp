#include <iostream>
#include <cstring>

// Variable declarations with initializations
int ct_lun = 0;
int ion_lun = 0;
int curr_lsf_num = 0;
char sf_name[2] = " "; // Adjusted size for null terminator
char def_map[2] = " "; // Adjusted size for null terminator
bool cal_init = false;
bool ion_init = false;
bool map_init = false;
bool rem_init = false;

// Test function definitions
void testInt(const char* name, int actual, int expected) {
    if (actual == expected) {
        std::cout << name << " PASSED" << std::endl;
    } else {
        std::cout << name << " FAILED: Expected " << expected << ", got " << actual << std::endl;
    }
}

void testChar(const char* name, const char* actual, const char* expected) {
    if (strcmp(actual, expected) == 0) {
        std::cout << name << " PASSED" << std::endl;
    } else {
        std::cout << name << " FAILED: Expected " << expected << ", got " << actual << std::endl;
    }
}

void testBool(const char* name, bool actual, bool expected) {
    if (actual == expected) {
        std::cout << name << " PASSED" << std::endl;
    } else {
        std::cout << name << " FAILED: Expected " << std::boolalpha << expected << ", got " << actual << std::endl;
    }
}

// Main function to run tests
int main() {
    // Running tests
    testInt("ct_lun", ct_lun, 0);
    testInt("ion_lun", ion_lun, 0);
    testInt("curr_lsf_num", curr_lsf_num, 0);
    testChar("sf_name", sf_name, " ");
    testChar("def_map", def_map, " ");
    testBool("cal_init", cal_init, false);
    testBool("ion_init", ion_init, false);
    testBool("map_init", map_init, false);
    testBool("rem_init", rem_init, false);

    return 0;
}