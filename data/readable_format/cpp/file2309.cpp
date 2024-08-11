#include <iostream>
#include <cmath>
#include <bitset>

extern "C" {
    int xmp_num_nodes();
    int xmp_node_num();
}

int main() {
    int procs, id;
    int mask1, val1;
    int mask2, val2;
    bool l1, l2;
    std::string result = "OK";

    if (xmp_num_nodes() > 31) {
        std::cout << "You have to run this program with less than 32 nodes." << std::endl;
        return 1;
    }

    procs = xmp_num_nodes();
    id = xmp_node_num() - 1;

    for (int i = 0; i < std::pow(2, procs); i += 2) {
        mask1 = 1 << id;
        val1 = i & mask1;
        l1 = (val1 != 0);

        mask2 = 1 << id;
        val2 = (i + 1) & mask2;
        l2 = (val2 != 0);

        if (l1) result = "NG";
        if ((i + 1) == (std::pow(2, procs) - 1)) {
            if (!l2) result = "NG";
        } else {
            if (l2) result = "NG";
        }
    }

    std::cout << xmp_node_num() << " testp061.f " << result << std::endl;

    return 0;
}