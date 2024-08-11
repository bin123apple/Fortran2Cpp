#include <iostream>
#include <map>
#include <string>

// Define the 'types' namespace to mimic the Fortran module 'types'
namespace types {

class tp4 {
private:
    float x;  // 'real' in Fortran is typically equivalent to 'float' in C++
    int i;

    // Making a constructor public for external access and manipulation
public:
    tp4(float x_val = 0, int i_val = 0) : x(x_val), i(i_val) {}
};

class tp3 {
private:
    int i;  // integer, private

public:
    float x;

    tp3(float x_val = 0, int i_val = 0) : x(x_val), i(i_val) {}
};

class tp2 {
public:
    tp3 t;
};

class tp1 {
public:
    int i;
    tp2 t;
};

} // namespace types

// Define the 'nml' namespace to mimic the Fortran module 'nml'
namespace nml {
using namespace types;

class tp5 {
public:
    tp4 t;
};

tp1 t1;
tp4 t4;

void y() {
    tp2 y2;
    tp3 y3;
    // Functionality for subroutine y goes here.
}

} // namespace nml

// Main program logic
int main() {
    using namespace types;
    using namespace nml;

    tp5 t5;

    // Assuming functionality for the main program and any manipulation of t5 goes here.

    return 0;
}