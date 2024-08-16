#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getClosestVowel(string word) {
    vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    string result = "";

    for (int i = word.length() - 1; i >= 2; i--) {
        if (find(vowels.begin(), vowels.end(), word[i]) != vowels.end()) {
            if (find(vowels.begin(), vowels.end(), word[i + 1]) == vowels.end() && find(vowels.begin(), vowels.end(), word[i - 1]) == vowels.end()) {
                result = word[i];
                return result;
            }
        }
    }

    return result;
}

int main() {
    string word;
    string result;

    // Test cases
    word = "yogurt";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "full";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "easy";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "eAsy";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "ali";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "bad";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "most";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "ab";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "ba";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "quick";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "anime";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "Asia";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "Above";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    return 0;
}

[C++]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getClosestVowel(string word) {
    vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    string result = "";

    for (int i = word.length() - 1; i >= 2; i--) {
        if (find(vowels.begin(), vowels.end(), word[i]) != vowels.end()) {
            if (find(vowels.begin(), vowels.end(), word[i + 1]) == vowels.end() && find(vowels.begin(), vowels.end(), word[i - 1]) == vowels.end()) {
                result = word[i];
                return result;
            }
        }
    }

    return result;
}

int main() {
    string word;
    string result;

    // Test cases
    word = "yogurt";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "full";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "easy";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "eAsy";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "ali";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "bad";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "most";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "ab";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "ba";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "quick";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "anime";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "Asia";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    word = "Above";
    result = getClosestVowel(word);
    cout << "getClosestVowel("" << word << "") = " << result << endl;

    return 0;
}

[C++]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getClosestVowel(string word) {
    vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    string result = "";

    for (int i = word.length() - 1; i >= 2; i--) {
        if (find(vowels.begin(), vowels.end(), word[i]) != vowels.end()) {
            if (find(vowels.begin(), vowels.end(), word[i + 1]) == vowels.end() && find(vowels.begin(), vowels.end(), word[i - 1]) == vowels.end()) {
                result = word[i];
                return result;
            }
        }
    }

    return result;
}

int main() {
    string word;
    string result;

    // Test cases
    word = "yogurt";
    result = getClosestVowel(word);
