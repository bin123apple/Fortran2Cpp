#include <cstdlib>  // For getenv and setenv
#include <iostream>

int main() {
    // Setting environment variables
    // Note: setenv is not standard in all environments, e.g., Windows.
    // Use _putenv_s on Windows instead.
    setenv("UVM_TESTNAME", "uex_ve_multicore_test", 1);
    setenv("SW_TESTNAME", "UEX.basic_multicore_test", 1);

    // Getting and printing environment variables to demonstrate
    char* uvmTestName = std::getenv("UVM_TESTNAME");
    if (uvmTestName != nullptr) {
        std::cout << "UVM_TESTNAME=" << uvmTestName << std::endl;
    }

    char* swTestName = std::getenv("SW_TESTNAME");
    if (swTestName != nullptr) {
        std::cout << "SW_TESTNAME=" << swTestName << std::endl;
    }

    return 0;
}