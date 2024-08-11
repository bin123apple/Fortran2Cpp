#include <cctype> // for std::toupper

bool LSAME(char CA, char CB) {
    static bool first = true;
    static int IOFF = 0;
    if (first) {
        IOFF = 'a' - 'A';
        first = false;
    }
    // Convert both characters to uppercase using std::toupper and compare
    return (CA == CB) || (std::toupper(CA) == std::toupper(CB));
}