#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int count_nums(vector<int> n) {
    int num = 0;
    for (int i = 0; i < n.size(); i++) {
        if (n[i] > 0) {
            num++;
        } else {
            int sum = 0;
            int w = abs(n[i]);
            while (w >= 10) {
                sum += w % 10;
                w /= 10;
            }
            sum -= w;
            if (sum > 0) num++;
        }
    }
    return num;
}

int main() {
    vector<int> v;
    v.push_back(0);
    if (count_nums(v) != 0) {
        cout << "Assertion failed: count_nums({0}) == 0" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(-1);
    v.push_back(-2);
    v.push_back(0);
    if (count_nums(v) != 0) {
        cout << "Assertion failed: count_nums({-1, -2, 0}) == 0" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    if (count_nums(v) != 6) {
        cout << "Assertion failed: count_nums({1, 1, 2, -2, 3, 4, 5}) == 6" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(1);
    v.push_back(6);
    v.push_back(9);
    v.push_back(-6);
    v.push_back(0);
    v.push_back(1);
    v.push_back(5);
    if (count_nums(v) != 5) {
        cout << "Assertion failed: count_nums({1, 6, 9, -6, 0, 1, 5}) == 5" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(1);
    v.push_back(100);
    v.push_back(98);
    v.push_back(-7);
    v.push_back(1);
    v.push_back(-1);
    if (count_nums(v) != 4) {
        cout << "Assertion failed: count_nums({1, 100, 98, -7, 1, -1}) == 4" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(12);
    v.push_back(23);
    v.push_back(34);
    v.push_back(-45);
    v.push_back(-56);
    v.push_back(0);
    if (count_nums(v) != 5) {
        cout << "Assertion failed: count_nums({12, 23, 34, -45, -56, 0}) == 5" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(-0);
    v.push_back(1);
    if (count_nums(v) != 1) {
        cout << "Assertion failed: count_nums({-0, 1}) == 1" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(1);
    if (count_nums(v) != 1) {
        cout << "Assertion failed: count_nums({1}) == 1" << endl;
        exit(1);
    }

    cout << "All tests passed." << endl;
    return 0;
}
[/SOL]

[M]
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int count_nums(vector<int> n) {
    int num = 0;
    for (int i = 0; i < n.size(); i++) {
        if (n[i] > 0) {
            num++;
        } else {
            int sum = 0;
            int w = abs(n[i]);
            while (w >= 10) {
                sum += w % 10;
                w /= 10;
            }
            sum -= w;
            if (sum > 0) num++;
        }
    }
    return num;
}

int main() {
    vector<int> v;
    v.push_back(0);
    if (count_nums(v) != 0) {
        cout << "Assertion failed: count_nums({0}) == 0" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(-1);
    v.push_back(-2);
    v.push_back(0);
    if (count_nums(v) != 0) {
        cout << "Assertion failed: count_nums({-1, -2, 0}) == 0" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    if (count_nums(v) != 6) {
        cout << "Assertion failed: count_nums({1, 1, 2, -2, 3, 4, 5}) == 6" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(1);
    v.push_back(6);
    v.push_back(9);
    v.push_back(-6);
    v.push_back(0);
    v.push_back(1);
    v.push_back(5);
    if (count_nums(v) != 5) {
        cout << "Assertion failed: count_nums({1, 6, 9, -6, 0, 1, 5}) == 5" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(1);
    v.push_back(100);
    v.push_back(98);
    v.push_back(-7);
    v.push_back(1);
    v.push_back(-1);
    if (count_nums(v) != 4) {
        cout << "Assertion failed: count_nums({1, 100, 98, -7, 1, -1}) == 4" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(12);
    v.push_back(23);
    v.push_back(34);
    v.push_back(-45);
    v.push_back(-56);
    v.push_back(0);
    if (count_nums(v) != 5) {
        cout << "Assertion failed: count_nums({12, 23, 34, -45, -56, 0}) == 5" << endl;
        exit(1);
    }

    v.clear();
    v.push_back(-0);
    v.push_back(1);
    if (count_nums(v) != 1) {
        cout << "Assertion failed: count_nums({-0, 1}) == 1" << endl;
