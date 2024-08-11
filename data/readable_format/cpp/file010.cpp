#include <iostream>
#include <vector>
#include <algorithm> // For std::max

void addres(std::vector<int>& jdiag, const std::vector<int>& mht, int& nwk, int& ma, int& mb) {
    jdiag[0] = 1;
    ma = 0;
    mb = 0;
    for (size_t i = 1; i < mht.size(); ++i) {
        ma = std::max(ma, mht[i - 1]);
        mb += mht[i - 1];
        jdiag[i] = jdiag[i - 1] + 1 + mht[i - 1];
    }
    ma += 1;
    mb += mht.back(); // Adding the last element which was missing in the loop.
    mb /= mht.size();
    nwk = jdiag.back();
}

int main() {
    std::vector<int> jdiag(5), mht = {1, 2, 3, 4, 5};
    int nwk = 0, ma = 0, mb = 0;

    addres(jdiag, mht, nwk, ma, mb);

    std::cout << "jdiag:";
    for (int val : jdiag) std::cout << " " << val;
    std::cout << std::endl;

    std::cout << "ma: " << ma << std::endl;
    std::cout << "mb: " << mb << std::endl;
    std::cout << "nwk: " << nwk << std::endl;

    return 0;
}