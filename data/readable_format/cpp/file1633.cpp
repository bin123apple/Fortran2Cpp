#include <iostream>
#include <string>

int main() {
    // Equivalent to the format statement in Fortran, though direct usage in C++.
    std::string format = "%s"; // A simple format string, assuming the goal is to replicate Fortran's text formatting.
    
    // Since C++ doesn't support assigning to labels and indirect printing through them,
    // we directly print to the console using cout.
    std::cout << "hello" << std::endl;
    
    return 0;
}