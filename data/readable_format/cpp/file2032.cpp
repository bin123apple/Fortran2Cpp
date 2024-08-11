#include <iostream>

class BoolArray {
public:
    void subrBoolArrayIn(const bool* array_in, int n_in) {
        std::cout << "SUBR_BOOLARRAY_IN" << std::endl;
        
        for (int i = 0; i < n_in; ++i) {
            std::cout << (i + 1) << " " << std::boolalpha << array_in[i] << std::endl;
        }
    }
};

void testBoolArray() {
    BoolArray ba;
    const bool testArray[] = {true, false, true};
    int n = sizeof(testArray) / sizeof(testArray[0]);
    ba.subrBoolArrayIn(testArray, n);
}

int main() {
    testBoolArray();
    return 0;
}