#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cassert> // For simple assertion

class Foo {
public:
    static void bar(const std::string& arg1, const std::vector<std::string>& arg2, 
                    const std::vector<int>& arg3, int arg4, const std::string& arg5) {
        std::cout << arg1 << " ";
        for(const auto& element : arg2) {
            std::cout << element << " ";
        }
        for(int num : arg3) {
            std::cout << num << " ";
        }
        std::cout << arg4 << " " << arg5 << std::endl;
    }

    static void foo1(std::vector<std::string>& slist, int i) {
        if(i >= 1 && i <= static_cast<int>(slist.size())) {
            slist[i-1] = "hi=" + std::to_string(i);
        }
    }

    static std::array<std::array<int, 2>, 2> f1(const std::array<std::array<int, 2>, 2>& a) {
        std::array<std::array<int, 2>, 2> result;
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                result[i][j] = 15 + a[i][j];
            }
        }
        return result;
    }

    static std::array<std::array<int, 2>, 2> e1(const std::array<std::array<int, 2>, 2>& b) {
        std::array<std::array<int, 2>, 2> result;
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                result[i][j] = 42 + b[i][j];
            }
        }
        return result;
    }
};

void testBar() {
    Foo::bar("Test for bar", {"Array element 1", "Array element 2"}, {1, 2, 3, 4}, 4, "abcd");
}

void testFoo1() {
    std::vector<std::string> slist = {"", "", ""};
    Foo::foo1(slist, 2);
    assert(slist[1] == "hi=2");
}

void testF1AndE1() {
    std::array<std::array<int, 2>, 2> a = {{{1, 2}, {3, 4}}}; // Corrected initialization
    auto result_f1 = Foo::f1(a);
    auto result_e1 = Foo::e1(a);
    
    assert(result_f1[0][0] == 16);
    assert(result_f1[1][1] == 19);
    assert(result_e1[0][0] == 43);
    assert(result_e1[1][1] == 46);
}

int main() {
    testBar();
    testFoo1();
    testF1AndE1();

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}