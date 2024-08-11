#include <string>
#include <algorithm>

void GRTRML(std::string& STRING, int& L) {
    STRING = "/dev/tty";
    L = std::min(static_cast<int>(STRING.length()), 8);
}