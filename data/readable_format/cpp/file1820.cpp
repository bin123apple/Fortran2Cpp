#include <iostream>
#include <vector>
#include <cassert>

void mvbits(int& from, int frompos, int len, int& to, int topos) {
    int mask = ((1 << len) - 1);
    int bits = (from >> frompos) & mask;
    to &= ~(mask << topos);
    to |= (bits << topos);
}

void ya0013(std::vector<int>& ida, int nf1, int nf5, int nf6) {
    std::fill(ida.begin(), ida.end(), 1);
    mvbits(ida[nf5 - 1], 0, 1, ida[nf6 - 1], 2);
}

void testYA0013() {
    std::vector<int> ida(9, 0); 
    ya0013(ida, 1, 5, 6);

    for(int i = 0; i < ida.size(); i++) {
        std::cout << "ida[" << i << "] = " << ida[i] << std::endl;
    }
}

int main() {
    testYA0013();
    return 0;
}