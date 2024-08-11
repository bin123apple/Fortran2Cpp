#include <iostream>
#include <string>

class B1 {
public:
    static void sub() {
        int x[1] = {3};
        std::string st;
        st = fun(x);
        std::cout << "st: " << st << std::endl;
    }

    static std::string fun(const int x[1]) {
        std::string st(lenf(x), ' ');  // Create a string with length lenf(x) filled with spaces
        st = "abc";
        return st;
    }

    static int lenf(const int x[1]) {
        return x[0];
    }
};

int main() {
    B1::sub();
    return 0;
}