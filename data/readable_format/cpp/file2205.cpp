// main_cpp_code.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check_results(const vector<int>& tmp) {
    int nerr = 0;
    for (int i = 0; i < 10; ++i) {
        int ival = (i >= 1 && i <= 5) ? (i + 1) * 3 : 0; // Adjusted indices for C++ 0-based indexing
        if (tmp[i] != ival) {
            cerr << "tmp(" << i + 1 << ")=" << tmp[i] << " should be " << ival << endl;
            nerr++;
        }
    }

    return nerr;
}

void simulate_parallel_function(int me, vector<int>& a1d1, vector<int>& tmp) {
    for (int i = 0; i < 10; ++i) {
        a1d1[i] = (i + 1) * me + max(-1, 0);
    }
    if (me == 1) {
        for (int i = 2; i <= 6; ++i) {
            tmp[i - 1] = a1d1[i - 1];
        }
    }
}

int main() {
    int me = 1; // Simulate being node 1 for testing
    vector<int> a1d1(10), tmp(10, 0);

    simulate_parallel_function(me, a1d1, tmp);

    int nerr = check_results(tmp);
    if (nerr == 0) {
        cout << "(" << me << ") OK" << endl;
    } else {
        cout << "(" << me << ") number of NGs: " << nerr << endl;
    }

    return 0;
}