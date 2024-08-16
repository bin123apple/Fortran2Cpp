#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void odd_count(vector<string> &input, vector<string> &output) {
    string s = "the number of odd elements in the string i of the input.";
    string s2;
    string temp;
    int sum;
    int pos;

    output.clear();
    for (int i = 0; i < input.size(); i++) {
        sum = 0;
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] >= '0' && input[i][j] <= '9') {
                if (input[i][j] % 2 == 1) sum++;
            }
        }

        s2 = "";
        pos = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'i') {
                temp = to_string(sum);
                s2.insert(pos, temp);
                pos += temp.size();
            } else {
                s2.insert(pos, 1, s[j]);
                pos++;
            }
        }
        output.push_back(s2);
    }
}

int main() {
    vector<string> input;
    vector<string> output;
    vector<string> expected;

    // Test case 1
    input.clear();
    input.push_back("1234567");
    expected.clear();
    expected.push_back("the number of odd elements in the string 4 of the input.");
    odd_count(input, output);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    assert(output == expected);

    // Test case 2
    input.clear();
    input.push_back("3");
    input.push_back("11111111");
    expected.clear();
    expected.push_back("the number of odd elements in the string 1 of the input.");
    expected.push_back("the number of odd elements in the string 8 of the input.");
    odd_count(input, output);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    assert(output == expected);

    // Test case 3
    input.clear();
    input.push_back("271");
    input.push_back("137");
    input.push_back("314");
    expected.clear();
    expected.push_back("the number of odd elements in the string 2 of the input.");
    expected.push_back("the number of odd elements in the string 3 of the input.");
    expected.push_back("the number of odd elements in the string 2 of the input.");
    odd_count(input, output);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    assert(output == expected);

    return 0;
}

[C++]
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void odd_count(vector<string> &input, vector<string> &output) {
    string s = "the number of odd elements in the string i of the input.";
    string s2;
    string temp;
    int sum;
    int pos;

    output.clear();
    for (int i = 0; i < input.size(); i++) {
        sum = 0;
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] >= '0' && input[i][j] <= '9') {
                if (input[i][j] % 2 == 1) sum++;
            }
        }

        s2 = "";
        pos = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'i') {
                temp = to_string(sum);
                s2.insert(pos, temp);
                pos += temp.size();
            } else {
                s2.insert(pos, 1, s[j]);
                pos++;
            }
        }
        output.push_back(s2);
    }
}

int main() {
    vector<string> input;
    vector<string> output;
    vector<string> expected;

    // Test case 1
    input.clear();
    input.push_back("1234567");
    expected.clear();
    expected.push_back("the number of odd elements in the string 4 of the input.");
    odd_count(input, output);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    assert(output == expected);

    // Test case 2
    input.clear();
    input.push_back("3");
    input.push_back("11111111");
    expected.clear();
    expected.push_back("the number of odd elements in the string 1 of the input.");
    expected.push_back("the number of odd elements in the string 8 of the input.");
    odd_count(input, output);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    assert(output == expected);

    // Test case 3
    input.clear();
    input.push_back("271");
    input.push_back("137");
    input.push_back("314");
    expected.clear();
    expected.push_back("the number of odd elements in the string 2 of the input.");
    expected.push_back("the number of odd elements in the string 3 of the input.");
    expected.push_back("the number of odd elements in the string 2 of the input.");
    odd_count(input, output);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    assert(output == expected);

    return 0;
}

[C++]
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void odd_count(vector<string> &input, vector<string> &output) {
    string s = "the number of odd elements in the string i of the input.";
    string s2;
    string temp;
    int sum;
    int pos;

    output.clear();
    for (int i = 0; i < input.size(); i++) {
        sum = 0;
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] >= '0' && input[i][j] <= '9') {
                if (input[i][j] % 2 == 1) sum++;
            }
        }

        s2 = "";
        pos = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'i') {
                temp = to_string(sum);
                s2.insert(pos, temp);
                pos += temp.size();
            } else {
                s2.insert(pos, 1, s[j]);
                pos++;
            }
        }
        output.push_back(s2);
    }
}

int main() {
    vector<string> input;
    vector<string> output;
    vector<string> expected;

    // Test case 1
    input.clear();
    input.push_back("1234567");
    expected.clear();
    expected.push_back("the number of odd elements in the string 4 of the input.");
    odd_count(input, output);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    assert(output == expected
