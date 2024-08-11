#include <string>

void chr_ltoc(bool lvalue, std::string& str, int& nchar) {
    if (lvalue) {
        str = "TRUE";
        nchar = 4;
    } else {
        str = "FALSE";
        nchar = 5;
    }
}