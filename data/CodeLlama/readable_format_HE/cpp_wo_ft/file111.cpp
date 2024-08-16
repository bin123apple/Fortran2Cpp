#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool file_name_check(string file_name) {
    int numdigit = 0;
    int numdot = 0;
    int i;
    string last;
    char w;

    if (file_name.length() < 5) return false;

    w = file_name[0];
    if (isalpha(w) == 0 || (isalpha(w) == 0 && isdigit(w) == 0) || isalpha(w) == 0) return false;

    last = file_name.substr(file_name.length()-4, 4);
    if (last != ".txt" && last != ".exe" && last != ".dll") return false;

    for (i = 0; i < file_name.length(); i++) {
        if (isdigit(file_name[i]) != 0) numdigit++;
        if (file_name[i] == '.') numdot++;
    }

    if (numdigit > 3 || numdot != 1) return false;

    return true;
}

int main() {
    assert(file_name_check("example.txt") == true);
    assert(file_name_check("1example.dll") == false);
    assert(file_name_check("s1sdf3.asd") == false);
    assert(file_name_check("K.dll") == true);
    assert(file_name_check("MY16FILE3.exe") == true);
    assert(file_name_check("His12FILE94.exe") == false);
    assert(file_name_check("_Y.txt") == false);
    assert(file_name_check("?aREYA.exe") == false);
    assert(file_name_check("/this_is_valid.dll") == false);
    assert(file_name_check("this_is_valid.wow") == false);
    assert(file_name_check("this_is_valid.txt") == true);
    assert(file_name_check("this_is_valid.txtexe") == false);
    assert(file_name_check("#this2_i4s_5valid.ten") == false);
    assert(file_name_check("@this1_is6_valid.exe") == false);
    assert(file_name_check("this_is_12valid.6exe4.txt") == false);
    assert(file_name_check("all.exe.txt") == false);
    assert(file_name_check("I563_No.exe") == true);
    assert(file_name_check("Is3youfault.txt") == true);
    assert(file_name_check("no_one#knows.dll") == true);
    assert(file_name_check("1I563_Yes3.exe") == false);
    assert(file_name_check("I563_Yes3.txtt") == false);
    assert(file_name_check("final..txt") == false);
    assert(file_name_check("final132") == false);
    assert(file_name_check("_f4indsartal132.") == false);
    assert(file_name_check(".txt") == false);
    assert(file_name_check("s.") == false);

    return 0;
}

[C]
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int file_name_check(char *file_name) {
    int numdigit = 0;
    int numdot = 0;
    int i;
    char last[5];
    char w;

    if (strlen(file_name) < 5) return 0;

    w = file_name[0];
    if (isalpha(w) == 0 || (isalpha(w) == 0 && isdigit(w) == 0) || isalpha(w) == 0) return 0;

    strncpy(last, file_name + strlen(file_name) - 4, 4);
    if (strcmp(last, ".txt") != 0 && strcmp(last, ".exe") != 0 && strcmp(last, ".dll") != 0) return 0;

    for (i = 0; i < strlen(file_name); i++) {
        if (isdigit(file_name[i]) != 0) numdigit++;
        if (file_name[i] == '.') numdot++;
    }

    if (numdigit > 3 || numdot != 1) return 0;

    return 1;
}

int main() {
    assert(file_name_check("example.txt") == 1);
    assert(file_name_check("1example.dll") == 0);
    assert(file_name_check("s1sdf3.asd") == 0);
    assert(file_name_check("K.dll") == 1);
    assert(file_name_check("MY16FILE3.exe") == 1);
    assert(file_name_check("His12FILE94.exe") == 0);
    assert(file_name_check("_Y.txt") == 0);
    assert(file_name_check("?aREYA.exe") == 0);
    assert(file_name_check("/this_is_valid.dll") == 0);
    assert(file_name_check("this_is_valid.wow") == 0);
    assert(file_name_check("this_is_valid.txt") == 1);
    assert(file_name_check("this_is_valid.txtexe") == 0);
    assert(file_name_check("#this2_i4s_5valid.ten") == 0);
    assert(file_name_check("@this1_is6_valid.exe") == 0);
    assert(file_name_check("this_is_12valid.6exe4.txt") == 0);
    assert(file_name_check("all.exe.txt") == 0);
    assert(file_name_check("I563_No.exe") == 1);
    assert(file_name_check("Is3youfault.txt") == 1);
    assert(file_name_check("no_one#knows.dll") == 1);
    assert(file_name_check("1I563_Yes3.exe") == 0);
    assert(file_name_check("I563_Yes3.txtt") == 0);
    assert(file_name_check("final..txt") == 0);
    assert(file_name_check("final132") == 0);
    assert(file_name_check("_f4indsartal132.") == 0);
    assert(file_name_check(".txt") == 0);
    assert(file_name_check("s.") == 0);

    return 0;
}

[Python]
def file_name_check(file_name):
    numdigit = 0
    numdot = 0
    i = 0
    last = file_name[-4:]

    if len(file_name) < 5:
        return False

    w = file_name[0]
    if not (65 <= ord(w) <= 90 or 97 <= ord(w) <= 122):
        return False

    if last != ".txt" and last != ".exe" and last != ".dll":
        return False

    for i in range(len(file_name)):
        if 48 <= ord(file_name[i]) <= 57:
            numdigit += 1
        if file_name[i] == ".":
            numdot += 1

    if numdigit > 3 or numdot != 1:
        return False

    return True

def assert(condition):
    if not condition:
        print("Assertion failed")
        exit(1)

if __name__ == "__main__":
    assert(file_name_check("example.txt") == True)
    assert(file_name_check("1example.dll") == False)
