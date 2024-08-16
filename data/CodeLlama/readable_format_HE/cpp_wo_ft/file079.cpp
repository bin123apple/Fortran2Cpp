#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int skjkasdkd(vector<int> lst) {
    int largest = 0;
    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] > largest) {
            bool prime = true;
            for (int j = 2; j <= sqrt(lst[i]); j++) {
                if (lst[i] % j == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) largest = lst[i];
        }
    }

    int sum = 0;
    string s = to_string(largest);
    for (int i = 0; i < s.length(); i++) {
        sum += s[i] - '0';
    }
    return sum;
}

int main() {
    vector<int> lst = {0,3,2,1,3,5,7,4,5,5,5,2,181,32,4,32,3,2,32,324,4,3};
    int result = skjkasdkd(lst);
    if (result != 10) {
        cout << "Assertion failed: result != 10" << endl;
        exit(1);
    }

    lst = {1,0,1,8,2,4597,2,1,3,40,1,2,1,2,4,2,5,1};
    result = skjkasdkd(lst);
    if (result != 25) {
        cout << "Assertion failed: result != 25" << endl;
        exit(1);
    }

    lst = {1,3,1,32,5107,34,83278,109,163,23,2323,32,30,1,9,3};
    result = skjkasdkd(lst);
    if (result != 13) {
        cout << "Assertion failed: result != 13" << endl;
        exit(1);
    }

    lst = {0,724,32,71,99,32,6,0,5,91,83,0,5,6};
    result = skjkasdkd(lst);
    if (result != 11) {
        cout << "Assertion failed: result != 11" << endl;
        exit(1);
    }

    lst = {0,81,12,3,1,21};
    result = skjkasdkd(lst);
    if (result != 3) {
        cout << "Assertion failed: result != 3" << endl;
        exit(1);
    }

    lst = {0,8,1,2,1,7};
    result = skjkasdkd(lst);
    if (result != 7) {
        cout << "Assertion failed: result != 7" << endl;
        exit(1);
    }

    lst = {8191};
    result = skjkasdkd(lst);
    if (result != 19) {
        cout << "Assertion failed: result != 19" << endl;
        exit(1);
    }

    lst = {8191, 123456, 127, 7};
    result = skjkasdkd(lst);
    if (result != 19) {
        cout << "Assertion failed: result != 19" << endl;
        exit(1);
    }

    lst = {127, 97, 8192};
    result = skjkasdkd(lst);
    if (result != 10) {
        cout << "Assertion failed: result != 10" << endl;
        exit(1);
    }

    cout << "All tests passed." << endl;
    return 0;
} [/CPP]

[C]
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int skjkasdkd(int *lst, int lst_len) {
    int largest = 0;
    for (int i = 0; i < lst_len; i++) {
        if (lst[i] > largest) {
            bool prime = true;
            for (int j = 2; j <= sqrt(lst[i]); j++) {
                if (lst[i] % j == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) largest = lst[i];
        }
    }

    int sum = 0;
    char s[20];
    sprintf(s, "%d", largest);
    for (int i = 0; i < strlen(s); i++) {
        sum += s[i] - '0';
    }
    return sum;
}

int main() {
    int lst[] = {0,3,2,1,3,5,7,4,5,5,5,2,181,32,4,32,3,2,32,324,4,3};
    int result = skjkasdkd(lst, sizeof(lst) / sizeof(lst[0]));
    if (result != 10) {
        printf("Assertion failed: result != 10
");
        exit(1);
    }

    lst = (int[]){1,0,1,8,2,4597,2,1,3,40,1,2,1,2,4,2,5,1};
    result = skjkasdkd(lst, sizeof(lst) / sizeof(lst[0]));
    if (result != 25) {
        printf("Assertion failed: result != 25
");
        exit(1);
    }

    lst = (int[]){1,3,1,32,5107,34,83278,109,163,23,2323,32,30,1,9,3};
    result = skjkasdkd(lst, sizeof(lst) / sizeof(lst[0]));
    if (result != 13) {
        printf("Assertion failed: result != 13
");
        exit(1);
    }

    lst = (int[]){0,724,32,71,99,32,6,0,5,91,83,0,5,6};
    result = skjkasdkd(lst, sizeof(lst) / sizeof(lst[0]));
    if (result != 11) {
        printf("Assertion failed: result != 11
");
        exit(1);
    }

    lst = (int[]){0,81,12,3,1,21};
    result = skjkasdkd(lst, sizeof(lst) / sizeof(lst[0]));
    if (result != 3) {
        printf("Assertion failed: result != 3
");
        exit(1);
    }

    lst = (int[]){0,8,1,2,1,7};
    result = skjkasdkd(lst, sizeof(lst) / sizeof(lst[0]));
    if (result != 7) {
        printf("Assertion failed: result != 7
");
        exit(1);
    }

    lst = (int[]){8191};
    result = skjkasdkd(lst, sizeof(lst) / sizeof(lst[0]));
    if (result != 19) {
        printf("Assertion failed: result != 19
");
        exit(1);
    }

    lst = (int[]){8191, 123456, 127, 7};
    result = skjkasdkd(lst, sizeof(lst) / sizeof(lst[0]));
    if (result != 19) {
        printf("Assertion failed: result !=
