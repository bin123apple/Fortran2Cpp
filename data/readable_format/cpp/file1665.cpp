#include <iostream>

namespace ControlRet {
    int increment(int n) {
        return n + 1;
    }
}

void NDTRAN(int n, int& result) {
    result = ControlRet::increment(n);
}

int main() {
    int input = 5;
    int output;
    NDTRAN(input, output);
    std::cout << "Input: " << input << " Output: " << output << std::endl;
    return 0;
}