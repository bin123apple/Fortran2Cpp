#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class ODBase {
public:
    int value;
};

// Abstract base class to simulate Fortran's interface with module procedures
class ODFName {
public:
    virtual void operator()(ODBase& base, int& nfam, std::vector<std::string>& cnames) = 0;
    virtual void operator()(ODBase& base, int pos, std::string& cname) = 0;
};

class ODFamilyCName : public ODFName {
public:
    void operator()(ODBase& base, int& nfam, std::vector<std::string>& cnames) override {
        // Assuming nfam is the size of cnames vector for this example
        std::fill(cnames.begin(), cnames.end(), "odfamilycnames");
    }

    void operator()(ODBase& base, int pos, std::string& cname) override {
        cname = "odfamilycname";
    }
};

int main() {
    ODBase base;
    ODFamilyCName odfname;
    int i = 1;
    std::string cname;
    std::vector<std::string> cnames(1); // Equivalent to CHARACTER(14) :: cnames(1) in Fortran

    // Simulate the Fortran CALL to a generic interface with a specific implementation
    odfname(base, i, cname);
    if (cname != "odfamilycname") std::abort();

    odfname(base, i, cnames);
    if (cnames[0] != "odfamilycnames") std::abort();

    return 0;
}