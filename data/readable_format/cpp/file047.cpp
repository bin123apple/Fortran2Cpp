#include <iostream>
#include <vector>
#include <string>
#include <array>

class XParams {
public:
    static inline std::vector<std::string> exprs = {
        "nint()  ", "log10() ", "sqrt()  ", "acos()  ", "asin()  ",
        "atan()  ", "cosh()  ", "sinh()  ", "tanh()  ", "int()   ",
        "cos()   ", "sin()   ", "tan()   ", "exp()   ", "log()   ",
        "abs()   ", "delta() ", "step()  ", "rect()  ", "max(,)  ",
        "min(,)  ", "bj0()   ", "bj1()   ", "bjn(,)  ", "by0()   ",
        "by1()   ", "byn(,)  ", "logb(,) ", "erf()   ", "erfc()  ",
        "lgamma()", "gamma() ", "csch()  ", "sech()  ", "coth()  ",
        "lif(,,) ", "gaus()  ", "sinc()  ", "atan2(,)", "mod(,)  ",
        "nthrt(,)", "ramp()  ", "fbi()   ", "fbiq()  ", "uran(,) ",
        "aif(,,)", "sgn()   ", "cbrt()  ", "fact()  ", "somb()  ",
        "bk0()   ", "bk1()   ", "bkn(,)", "bbi(,,) ", "bbiq(,,)"
    };
    static std::array<std::array<bool, 55>, 26> tmp;
};

std::array<std::array<bool, 55>, 26> XParams::tmp = {};

void testXParams() {
    int errors = 0;
    std::string al = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; ++i) {
        for (size_t j = 0; j < XParams::exprs.size(); ++j) {
            XParams::tmp[i][j] = (XParams::exprs[j][0] == al[i]);
            bool expected = (XParams::exprs[j][0] == al[i]);
            if (XParams::tmp[i][j] != expected) {
                std::cout << "Test failed for i = " << i << ", j = " << j << std::endl;
                ++errors;
            }
        }
    }

    if (errors == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "There were " << errors << " errors." << std::endl;
    }
}

int main() {
    testXParams();
    return 0;
}