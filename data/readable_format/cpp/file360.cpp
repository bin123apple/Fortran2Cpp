#include <iostream>

// Equivalent of Fortran's type t1
class t1 {
public:
    int a1;
};

// Equivalent of Fortran's type t2, extends t1
class t2 : public t1 {
public:
    int a2;
};

// Equivalent of Fortran's type t3, extends t2
class t3 : public t2 {
public:
    int a3;
};

int main() {
    t3 x3; // Instance of t3
    int i;

    // Accessing members in the C++ way
    i = x3.a2;
    i = x3.a1;
    // Note: In C++, there's no direct equivalent to Fortran's component % parent type access like x3%t2%a2
    // Direct access is used instead, as inheritance makes all accessible base members part of the derived class

    // The following are Fortran-specific and have no direct equivalent in C++:
    // i = x3%t2%a2; // This is not applicable in C++ as shown above
    // i = x3%t2%a1; // Not applicable
    // i = x3%t1%a1; // Not applicable
    // i = x3%t2%t1%a1; // Not applicable

    return 0;
}

// Equivalent of Fortran's module m1 and subroutine s1 translation
class m1_t1 {
public:
    int t1;
};

// Equivalent to `use m1, only: t2 => t1` and type t3, extends t2 in subroutine s1
class s1_t3 : public m1_t1 {
public:
    void s1() {
        s1_t3 x; // Instance of s1_t3
        int i;

        i = x.t1;
        // Note: In C++, there's no direct equivalent for Fortran's renaming and scope control through `use, only:`
        // and the component % parent type access within derived types. Direct member access is used instead.
    }
};