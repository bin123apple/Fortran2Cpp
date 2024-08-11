// DataProcTest.cpp
#include <iostream>
#include <string>

class DataProc {
public:
    int nproc;              
    int mynum;              
    std::string appnproc; // Adjusted to 4 characters in use, not size
    std::string appmynum; // Adjusted to 4 characters in use, not size
    bool lpr;                
    std::string procstrg; // Adjusted to 8 characters in use, not size

    DataProc() : appnproc(4, ' '), appmynum(4, ' '), procstrg(8, ' '), nproc(0), mynum(0), lpr(false) {}

    void print_data() {
        std::cout << "Testing DataProc class..." << std::endl;
        std::cout << "nproc = " << nproc << std::endl;
        std::cout << "mynum = " << mynum << std::endl;
        std::cout << "appnproc = " << appnproc << std::endl;
        std::cout << "appmynum = " << appmynum << std::endl;
        std::cout << "lpr = " << std::boolalpha << lpr << std::endl; // Use boolalpha for boolean printing
        std::cout << "procstrg = " << procstrg << std::endl;
    }
};

int main() {
    DataProc dp;

    // Initialize variables
    dp.nproc = 2;
    dp.mynum = 1;
    dp.appnproc = "002 "; // Adjusted to match Fortran's space padding
    dp.appmynum = "001 "; // Adjusted to match Fortran's space padding
    dp.lpr = true;
    dp.procstrg = "process1";

    dp.print_data();

    return 0;
}