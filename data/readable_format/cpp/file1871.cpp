#include <iostream>
#include <string>

// Declare global variables directly in this file
std::string Evs = "FF";
std::string InEvs = "done";
int Nf_FF = 0;

// Function prototype
void SetFFNS(int nfl);

// Main function
int main() {
    int testNfl = 5;
    SetFFNS(testNfl);

    if (Evs == "FF" && Nf_FF == testNfl && InEvs == "done") {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}

// Definition of SetFFNS function
void SetFFNS(int nfl) {
    Evs = "FF";
    Nf_FF = nfl;
    InEvs = "done";
}