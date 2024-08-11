#include <iostream>
#include <cassert>

class SwitchesBin {
public:
    static bool l_coll_coal;
    static bool l_break;
    static bool l_sed_ult;
    static bool l_two_mom;
};

// Initialize static members outside the class definition
bool SwitchesBin::l_coll_coal = true;
bool SwitchesBin::l_break = false;
bool SwitchesBin::l_sed_ult = false;
bool SwitchesBin::l_two_mom = true;

int main() {
    // Test l_coll_coal
    assert(SwitchesBin::l_coll_coal == true);
    std::cout << "Test passed: l_coll_coal is True." << std::endl;

    // Test l_break
    assert(SwitchesBin::l_break == false);
    std::cout << "Test passed: l_break is False." << std::endl;

    // Test l_sed_ult
    assert(SwitchesBin::l_sed_ult == false);
    std::cout << "Test passed: l_sed_ult is False." << std::endl;

    // Test l_two_mom
    assert(SwitchesBin::l_two_mom == true);
    std::cout << "Test passed: l_two_mom is True." << std::endl;

    return 0;
}