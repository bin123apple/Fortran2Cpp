#include <iostream>
#include <string>
#include <vector>
#include <cassert>

// Translation of the Fortran code into C++ classes and functions
class Test1 {
public:
    static std::string test1(int n) {
        return std::string(n, ' ');
    }
    
    static std::string bar1(int n) {
        return std::string(n, ' ');
    }
};

std::string test2() {
    return " ";
}

std::string bar2() {
    return " ";
}

std::string test3() {
    return "";
}

std::string bar3() {
    return "";
}

class Test4 {
public:
    static std::string test4(int n) {
        return std::string(n, ' ');
    }
    
    static std::string bar4() {
        return "";
    }
};

std::string test5() {
    return " ";
}

std::string bar5() {
    return "  ";
}

std::string test6() {
    return "";
}

std::string bar6() {
    return "  ";
}

// Basic testing framework
void assertEqual(const std::string& lhs, const std::string& rhs, const std::string& testName) {
    assert(lhs == rhs && testName.c_str());
}

int main() {
    // Run tests
    assertEqual(Test1::test1(5), "     ", "Test1");
    assertEqual(Test1::bar1(5), "     ", "Bar1");
    
    assertEqual(test2(), " ", "Test2");
    assertEqual(bar2(), " ", "Bar2");
    
    assertEqual(test3(), "", "Test3");
    assertEqual(bar3(), "", "Bar3");
    
    assertEqual(Test4::test4(5), "     ", "Test4");
    assertEqual(Test4::bar4(), "", "Bar4");
    
    assertEqual(test5(), " ", "Test5");
    assertEqual(bar5(), "  ", "Bar5");
    
    assertEqual(test6(), "", "Test6");
    assertEqual(bar6(), "  ", "Bar6");
    
    std::cout << "All tests passed successfully." << std::endl;
    
    return 0;
}