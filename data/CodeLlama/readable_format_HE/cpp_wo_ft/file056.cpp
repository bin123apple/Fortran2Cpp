#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int digitSum(const string &s) {
    int digitSum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            digitSum += s[i];
        }
    }
    return digitSum;
}

int main() {
    if (digitSum("") != 0) {
        cout << "Assertion failed: digitSum('') == 0" << endl;
        exit(1);
    }

    if (digitSum("abAB") != 131) {
        cout << "Assertion failed: digitSum('abAB') == 131" << endl;
        exit(1);
    }

    if (digitSum("abcCd") != 67) {
        cout << "Assertion failed: digitSum('abcCd') == 67" << endl;
        exit(1);
    }

    if (digitSum("helloE") != 69) {
        cout << "Assertion failed: digitSum('helloE') == 69" << endl;
        exit(1);
    }

    if (digitSum("woArBld") != 131) {
        cout << "Assertion failed: digitSum('woArBld') == 131" << endl;
        exit(1);
    }

    if (digitSum("aAaaaXa") != 153) {
        cout << "Assertion failed: digitSum('aAaaaXa') == 153" << endl;
        exit(1);
    }

    if (digitSum(" How are yOu?") != 151) {
        cout << "Assertion failed: digitSum(' How are yOu?') == 151" << endl;
        exit(1);
    }

    if (digitSum("You arE Very Smart") != 327) {
        cout << "Assertion failed: digitSum('You arE Very Smart') == 327" << endl;
        exit(1);
    }

    cout << "All assertions passed." << endl;

    return 0;
}

[C++]
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int digitSum(const string &s) {
    int digitSum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            digitSum += s[i];
        }
    }
    return digitSum;
}

int main() {
    if (digitSum("") != 0) {
        cout << "Assertion failed: digitSum('') == 0" << endl;
        exit(1);
    }

    if (digitSum("abAB") != 131) {
        cout << "Assertion failed: digitSum('abAB') == 131" << endl;
        exit(1);
    }

    if (digitSum("abcCd") != 67) {
        cout << "Assertion failed: digitSum('abcCd') == 67" << endl;
        exit(1);
    }

    if (digitSum("helloE") != 69) {
        cout << "Assertion failed: digitSum('helloE') == 69" << endl;
        exit(1);
    }

    if (digitSum("woArBld") != 131) {
        cout << "Assertion failed: digitSum('woArBld') == 131" << endl;
        exit(1);
    }

    if (digitSum("aAaaaXa") != 153) {
        cout << "Assertion failed: digitSum('aAaaaXa') == 153" << endl;
        exit(1);
    }

    if (digitSum(" How are yOu?") != 151) {
        cout << "Assertion failed: digitSum(' How are yOu?') == 151" << endl;
        exit(1);
    }

    if (digitSum("You arE Very Smart") != 327) {
        cout << "Assertion failed: digitSum('You arE Very Smart') == 327" << endl;
        exit(1);
    }

    cout << "All assertions passed." << endl;

    return 0;
}

[C++]
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int digitSum(const string &s) {
    int digitSum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            digitSum += s[i];
        }
    }
    return digitSum;
}

int main() {
    if (digitSum("") != 0) {
        cout << "Assertion failed: digitSum('') == 0" << endl;
        exit(1);
    }

    if (digitSum("abAB") != 131) {
        cout << "Assertion failed: digitSum('abAB') == 131" << endl;
        exit(1);
    }

    if (digitSum("abcCd") != 67) {
        cout << "Assertion failed: digitSum('abcCd') == 67" << endl;
        exit(1);
    }

    if (digitSum("helloE") != 69) {
        cout << "Assertion failed: digitSum('helloE') == 69" << endl;
        exit(1);
    }

    if (digitSum("woArBld") != 131) {
        cout << "Assertion failed: digitSum('woArBld') == 131" << endl;
        exit(1);
    }

    if (digitSum("aAaaaXa") != 153) {
        cout << "Assertion failed: digitSum('aAaaaXa') == 153" << endl;
        exit(1);
    }

    if (digitSum(" How are yOu?") != 151) {
        cout << "Assertion failed: digitSum(' How are yOu?') == 151" << endl;
        exit(1);
    }

    if (digitSum("You arE Very Smart") != 327) {
        cout << "Assertion failed: digitSum('You arE Very Smart') == 327" << endl;
        exit(1);
    }

    cout << "All assertions passed." << endl;

    return 0;
}

[C++]
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int digitSum(const string &s) {
    int digitSum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            digitSum += s[i];
        }
    }
    return digitSum;
}

int main() {
    if (digitSum("") != 0) {
        cout << "Assertion failed: digitSum('') == 0" << endl;
        exit(1);
    }

    if (digitSum("abAB") != 131) {
        cout << "Assertion failed: digitSum('abAB') == 131" << endl;
        exit(1);
    }

    if (digitSum("abcCd") != 67) {
        cout << "Assertion failed: digitSum('abcCd') == 67" << endl;
        exit(1);
    }

    if (digitSum("helloE") != 69) {
        cout << "Assertion failed: digitSum('helloE') == 69" << endl;
        exit(1);
    }

    if (digitSum("woArBld") != 131)
