#include <iostream>

template <typename DATA_TYPE>
void print_array(DATA_TYPE** d, int ni, int nl) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            std::cout << d[j][i];

            if (((i * ni) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}
