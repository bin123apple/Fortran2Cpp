// IDAYWK.cpp
#include <iostream>

class IDAYWK__genmod {
public:
    static int IDAYWK(int JDAYNO) {
        return JDAYNO + 1;
    }
};

void test_IDAYWK() {
    int JDAYNO = 123;
    int result = IDAYWK__genmod::IDAYWK(JDAYNO);
    std::cout << "C++ Result: " << result << std::endl;
}

int main() {
    test_IDAYWK();
    return 0;
}