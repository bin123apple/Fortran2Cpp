#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_happy(string s) {
    if (s.length() < 3) {
        return false;
    }

    for (int i = 3; i < s.length(); i++) {
        if (s[i] == s[i-1] || s[i] == s[i-2]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s;
    cin >> s;

    if (!is_happy(s)) {
        cout << "Test 1 passed" << endl;
    } else {
        cout << "Test 1 failed" << endl;
        return 1;
    }

    s = "aa";
    if (!is_happy(s)) {
        cout << "Test 2 passed" << endl;
    } else {
        cout << "Test 2 failed" << endl;
        return 1;
    }

    s = "abcd";
    if (is_happy(s)) {
        cout << "Test 3 passed" << endl;
    } else {
        cout << "Test 3 failed" << endl;
        return 1;
    }

    s = "aabb";
    if (!is_happy(s)) {
        cout << "Test 4 passed" << endl;
    } else {
        cout << "Test 4 failed" << endl;
        return 1;
    }

    s = "adb";
    if (is_happy(s)) {
        cout << "Test 5 passed" << endl;
    } else {
        cout << "Test 5 failed" << endl;
        return 1;
    }

    s = "xyy";
    if (!is_happy(s)) {
        cout << "Test 6 passed" << endl;
    } else {
        cout << "Test 6 failed" << endl;
        return 1;
    }

    s = "iopaxpoi";
    if (is_happy(s)) {
        cout << "Test 7 passed" << endl;
    } else {
        cout << "Test 7 failed" << endl;
        return 1;
    }

    s = "iopaxioi";
    if (!is_happy(s)) {
        cout << "Test 8 passed" << endl;
    } else {
        cout << "Test 8 failed" << endl;
        return 1;
    }

    return 0;
}

[C]
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_happy(char *s) {
    if (strlen(s) < 3) {
        return false;
    }

    for (int i = 3; i < strlen(s); i++) {
        if (s[i] == s[i-1] || s[i] == s[i-2]) {
            return false;
        }
    }

    return true;
}

int main() {
    char s[100];
    scanf("%s", s);

    if (!is_happy(s)) {
        printf("Test 1 passed
");
    } else {
        printf("Test 1 failed
");
        return 1;
    }

    strcpy(s, "aa");
    if (!is_happy(s)) {
        printf("Test 2 passed
");
    } else {
        printf("Test 2 failed
");
        return 1;
    }

    strcpy(s, "abcd");
    if (is_happy(s)) {
        printf("Test 3 passed
");
    } else {
        printf("Test 3 failed
");
        return 1;
    }

    strcpy(s, "aabb");
    if (!is_happy(s)) {
        printf("Test 4 passed
");
    } else {
        printf("Test 4 failed
");
        return 1;
    }

    strcpy(s, "adb");
    if (is_happy(s)) {
        printf("Test 5 passed
");
    } else {
        printf("Test 5 failed
");
        return 1;
    }

    strcpy(s, "xyy");
    if (!is_happy(s)) {
        printf("Test 6 passed
");
    } else {
        printf("Test 6 failed
");
        return 1;
    }

    strcpy(s, "iopaxpoi");
    if (is_happy(s)) {
        printf("Test 7 passed
");
    } else {
        printf("Test 7 failed
");
        return 1;
    }

    strcpy(s, "iopaxioi");
    if (!is_happy(s)) {
        printf("Test 8 passed
");
    } else {
        printf("Test 8 failed
");
        return 1;
    }

    return 0;
}

[Python]
def is_happy(s):
    if len(s) < 3:
        return False

    for i in range(3, len(s)):
        if s[i] == s[i-1] or s[i] == s[i-2]:
            return False

    return True


def main():
    s = input()

    if not is_happy(s):
        print("Test 1 passed")
    else:
        print("Test 1 failed")
        return 1

    s = "aa"
    if not is_happy(s):
        print("Test 2 passed")
    else:
        print("Test 2 failed")
        return 1

    s = "abcd"
    if is_happy(s):
        print("Test 3 passed")
    else:
        print("Test 3 failed")
        return 1

    s = "aabb"
    if not is_happy(s):
        print("Test 4 passed")
    else:
        print("Test 4 failed")
        return 1

    s = "adb"
    if is_happy(s):
        print("Test 5 passed")
    else:
        print("Test 5 failed")
        return 1

    s = "xyy"
    if not is_happy(s):
        print("Test 6 passed")
    else:
        print("Test 6 failed")
        return 1

    s = "iopaxpoi"
    if is_happy(s):
        print("Test 7 passed")
    else:
        print("Test 7 failed")
        return 1

    s = "iopaxioi"
    if not is_happy(s):
        print("Test 8 passed")
    else:
        print("Test 8 failed")
        return 1

    return 0

if __name__ == "__main__":
    main()

[JavaScript]
function isHappy(s) {
    if (s.length < 3) {
        return false;
    }

    for (let i = 3; i < s.length; i++) {
        if (s[i] == s[i-1] || s[i] == s[i-2]) {
            return false;
        }
    }

    return true;
}

function main() {
    let s = readline();

    if (!isHappy(s)) {
        console.log("Test 1 passed");
    } else {
        console.log("Test 1 failed");
        return 1;
    }

    s = "aa";
    if (!isHappy(s)) {
        console.log("Test 2 passed");
    } else {
        console.log("Test 2 failed");
        return 1;
    }

    s = "abcd";
    if (isHappy(s)) {
        console.log("Test 3 passed");
    } else {
        console.log("Test 3 failed");
        return 1;
    }

    s = "aabb";
    if (!isHappy(
