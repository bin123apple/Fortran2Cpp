#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void unpackpfx(int ng, string& call1) {
    string pfx(3, ' ');
    if (ng < 60000) {
        int n = ng;
        for (int i = 2; i >= 0; --i) {
            int nc = n % 37;
            if (nc >= 0 && nc <= 9) {
                pfx[i] = '0' + nc;
            } else if (nc >= 10 && nc <= 35) {
                pfx[i] = 'A' + (nc - 10);
            } else {
                pfx[i] = ' ';
            }
            n /= 37;
        }
        pfx.erase(0, pfx.find_first_not_of(' ')); // Remove leading spaces
        call1 = pfx + "/" + call1;
    } else {
        size_t i1 = call1.find(' ');
        if (i1 == string::npos) i1 = call1.length();
        int nc = ng - 60000;
        if (nc >= 0 && nc <= 9) {
            call1 = call1.substr(0, i1) + "/" + static_cast<char>('0' + nc);
        } else if (nc >= 10 && nc <= 35) {
            call1 = call1.substr(0, i1) + "/" + static_cast<char>('A' + (nc - 10));
        } else if (nc >= 36 && nc <= 125) {
            int nc1 = (nc - 26) / 10;
            int nc2 = (nc - 26) % 10;
            call1 = call1.substr(0, i1) + "/" + static_cast<char>('0' + nc1) + static_cast<char>('0' + nc2);
        }
    }
}

void test_unpackpfx() {
    string call1;
    string result;

    call1 = "examplecall";
    unpackpfx(12345, call1);
    result = "90O/examplecall";
    assert(call1 == result);
    cout << "C++ Test Result 1: " << call1 << endl;

    call1 = "examplecall";
    unpackpfx(60005, call1);
    result = "examplecall/5";
    assert(call1 == result);
    cout << "C++ Test Result 2: " << call1 << endl;
}

int main() {
    test_unpackpfx();
    cout << "All C++ test cases passed!" << endl;
    return 0;
}