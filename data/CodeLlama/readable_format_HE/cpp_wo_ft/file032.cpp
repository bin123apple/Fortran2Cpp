#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sort_even(vector<double> &l) {
    vector<double> even;
    for (int i = 0; i < l.size(); i += 2) {
        even.push_back(l[i]);
    }
    sort(even.begin(), even.end());
    for (int i = 0; i < l.size(); i++) {
        if (i % 2 == 0) {
            l[i] = even[i / 2];
        }
    }
}

int main() {
    vector<double> l;
    vector<double> expected;
    vector<double> result;

    // Test case 1
    l = {1.0, 2.0, 3.0};
    expected = {1.0, 2.0, 3.0};
    sort_even(l);
    result = l;
    if (result != expected) {
        cout << "Test case 1 failed" << endl;
        return 1;
    }

    // Test case 2
    l = {5.0, 3.0, -5.0, 2.0, -3.0, 3.0, 9.0, 0.0, 123.0, 1.0, -10.0};
    expected = {-10.0, 3.0, -5.0, 2.0, -3.0, 3.0, 5.0, 0.0, 9.0, 1.0, 123.0};
    sort_even(l);
    result = l;
    if (result != expected) {
        cout << "Test case 2 failed" << endl;
        return 1;
    }

    // Test case 3
    l = {5.0, 8.0, -12.0, 4.0, 23.0, 2.0, 3.0, 11.0, 12.0, -10.0};
    expected = {-12.0, 8.0, 3.0, 4.0, 5.0, 2.0, 12.0, 11.0, 23.0, -10.0};
    sort_even(l);
    result = l;
    if (result != expected) {
        cout << "Test case 3 failed" << endl;
        return 1;
    }

    cout << "All test cases passed" << endl;
    return 0;
}
\end{code}

Comment: I'm not sure what you mean by "the C++ code is not correct".  Can you be more specific?

Comment: @NathanOliver I mean that the C++ code does not give the same output as the Fortran code.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output and the actual output.

Comment: @NathanOliver I have added the expected output
