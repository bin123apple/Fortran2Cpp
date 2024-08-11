#include <iostream>
#include <array>
#include <string>
#include <cassert>

struct molkst_C {
    static inline int maxatoms, natoms, numat = 0, norbs, nelecs, ndep = 0;
    static inline int nvar = 0, nclose, nalpha, nbeta, nopen, numcal, mpack;
    static inline int n2elec, nscf, iscf, iflepo, last, na1, lm61, lm6, dummy;
    
    static inline double escf, emin, elect, enuclr, fract, gnorm;
    static inline double time0 = 0.0, tleft, tdump = 0.0, verson = 7.1;
    static inline double cosine, ux, uy, uz, step, rjkab1, atheat;
    static inline std::array<double, 3> efield;
    static inline double rdummy;
    
    static inline bool moperr, uhf, isok, limscf, is_PARAM = false;
    
    static inline std::string ltxt, jobnam;
    static inline std::string keywrd, koment, title, errtxt;
    
    static inline bool method_mndo, method_am1, method_pm3, method_mndod, method_dorbs, method;
};

void test_variables() {
    // Testing integer variables
    molkst_C::numat = 5;
    assert(molkst_C::numat == 5);

    // Testing real variables
    molkst_C::escf = 10.0;
    assert(molkst_C::escf == 10.0);

    // Testing logical variables
    molkst_C::moperr = true;
    assert(molkst_C::moperr == true);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_variables();
    return 0;
}