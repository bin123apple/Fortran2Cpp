#include <string>

class ilaenv_I {
public:
    virtual int ilaenv(int ISPEC, const std::string& NAME, int N1, int N2, int N4) = 0;
};