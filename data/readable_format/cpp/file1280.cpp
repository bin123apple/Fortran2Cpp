#include <iostream>
#include <vector>
#include <cstring>

// Function 'f' translated from Fortran
int f(int x) {
    return 2*x + 1;
}

// Class 'Test1' translated from Fortran module
class Test1 {
public:
    // Method 'test2' translated from Fortran function
    static std::vector<char> test2(int x) {
        int len_r = f(x); // Using function 'f' to determine the size
        std::vector<char> r(len_r);
        for(int i = 0; i < len_r; ++i) {
            r[i] = static_cast<char>((i % 32) + '@' + 1);
        }
        return r;
    }
};

int main() {
    // The 'main' logic from the Fortran program
    std::vector<char> chr = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};
    auto test2_result = Test1::test2(10);

    if(test2_result.size() != 21) {
        std::cerr << "STOP 1" << std::endl;
        return 1;
    }

    bool mismatch = false;
    for(size_t i = 0; i < chr.size(); ++i) {
        if(test2_result[i] != chr[i]) {
            mismatch = true;
            break;
        }
    }

    if(mismatch) {
        std::cerr << "STOP 2" << std::endl;
        return 2;
    }

    std::cout << "Program finished successfully." << std::endl;
    return 0;
}