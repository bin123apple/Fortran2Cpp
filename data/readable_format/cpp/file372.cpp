#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

struct MyType {
    int x;
    MyType(int val = 0) : x(val) {}
    MyType& operator=(const MyType& rhs) {
        x = rhs.x * 2;
        return *this;
    }
};

void assertEqualIntArrays(const std::vector<MyType>& vec, const std::initializer_list<int>& expected) {
    auto it = expected.begin();
    for (const auto& elem : vec) {
        assert(elem.x == *it);
        ++it;
    }
    std::cout << "Test passed." << std::endl;
}

int main() {
    std::vector<MyType> x = {MyType(1), MyType(20), MyType(300), MyType(4000), MyType(50000), MyType(1000000)};
    std::vector<int> indices = {1, 2, 0, 3, 4, 5};
    std::vector<MyType> tempX(x);

    for (size_t i = 0; i < x.size(); ++i) {
        x[i] = tempX[indices[i]];
    }
    assertEqualIntArrays(x, {40, 600, 2, 8000, 100000, 2000000});

    std::cout << "C++ code: All tests passed." << std::endl;
    return 0;
}