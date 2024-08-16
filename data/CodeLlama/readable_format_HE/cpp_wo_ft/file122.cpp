#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string find_max(vector<string> words) {
    string max_word = "";
    string unique;
    string word;
    int maxu = 0;
    int len_words = words.size();

    for (int i = 0; i < len_words; i++) {
        word = words[i];
        unique = "";
        for (int j = 0; j < word.length(); j++) {
            if (unique.find(word[j]) == string::npos) {
                unique += word[j];
            }
        }
        if (unique.length() > maxu || (unique.length() == maxu && word < max_word)) {
            max_word = word;
            maxu = unique.length();
        }
    }
    return max_word;
}

int main() {
    vector<string> words;
    string result;

    words = {"name   ", "of     ", "string "};
    result = find_max(words);
    if (result != "string") {
        cerr << "Assertion failed: expected 'string', got " << result << endl;
        return 1;
    }

    words = {"name   ", "enam   ", "game   "};
    result = find_max(words);
    if (result != "enam") {
        cerr << "Assertion failed: expected 'enam', got " << result << endl;
        return 1;
    }

    words = {"aaaaaaa", "bb     ", "cc     "};
    result = find_max(words);
    if (result != "aaaaaaa") {
        cerr << "Assertion failed: expected 'aaaaaaa', got " << result << endl;
        return 1;
    }

    words = {"abc    ", "cba    "};
    result = find_max(words);
    if (result != "abc") {
        cerr << "Assertion failed: expected 'abc', got " << result << endl;
        return 1;
    }

    words = {"play    ", "this    ", "game    ", "of      ", "footbott"};
    result = find_max(words);
    if (result != "footbott") {
        cerr << "Assertion failed: expected 'footbott', got " << result << endl;
        return 1;
    }

    words = {"we      ", "are     ", "gonna   ", "rock    "};
    result = find_max(words);
    if (result != "gonna") {
        cerr << "Assertion failed: expected 'gonna', got " << result << endl;
        return 1;
    }

    words = {"we      ", "are     ", "a       ", "mad     ", "nation  "};
    result = find_max(words);
    if (result != "nation") {
        cerr << "Assertion failed: expected 'nation', got " << result << endl;
        return 1;
    }

    words = {"this    ", "is      ", "a       ", "prrk    "};
    result = find_max(words);
    if (result != "this") {
        cerr << "Assertion failed: expected 'this', got " << result << endl;
        return 1;
    }

    words = {"b       "};
    result = find_max(words);
    if (result != "b") {
        cerr << "Assertion failed: expected 'b', got " << result << endl;
        return 1;
    }

    words = {"play    ", "play    ", "play    "};
    result = find_max(words);
    if (result != "play") {
        cerr << "Assertion failed: expected 'play', got " << result << endl;
        return 1;
    }

    cout << "All tests passed." << endl;
    return 0;
} [/CPP]

[PY]
def find_max(words):
    max_word = ""
    unique = ""
    maxu = 0
    len_words = len(words)

    for i in range(len_words):
        word = words[i]
        unique = ""
        for j in range(len(word)):
            if unique.find(word[j]) == -1:
                unique += word[j]
        if len(unique) > maxu or (len(unique) == maxu and word < max_word):
            max_word = word
            maxu = len(unique)
    return max_word


if __name__ == "__main__":
    words = ["name   ", "of     ", "string "]
    result = find_max(words)
    if result != "string":
        print("Assertion failed: expected 'string', got", result)
        exit(1)

    words = ["name   ", "enam   ", "game   "]
    result = find_max(words)
    if result != "enam":
        print("Assertion failed: expected 'enam', got", result)
        exit(1)

    words = ["aaaaaaa", "bb     ", "cc     "]
    result = find_max(words)
    if result != "aaaaaaa":
        print("Assertion failed: expected 'aaaaaaa', got", result)
        exit(1)

    words = ["abc    ", "cba    "]
    result = find_max(words)
    if result != "abc":
        print("Assertion failed: expected 'abc', got", result)
        exit(1)

    words = ["play    ", "this    ", "game    ", "of      ", "footbott"]
    result = find_max(words)
    if result != "footbott":
        print("Assertion failed: expected 'footbott', got", result)
        exit(1)

    words = ["we      ", "are     ", "gonna   ", "rock    "]
    result = find_max(words)
    if result != "gonna":
        print("Assertion failed: expected 'gonna', got", result)
        exit(1)

    words = ["we      ", "are     ", "a       ", "mad     ", "nation  "]
    result = find_max(words)
    if result != "nation":
        print("Assertion failed: expected 'nation', got", result)
        exit(1)

    words = ["this    ", "is      ", "a       ", "prrk    "]
    result = find_max(words)
    if result != "this":
        print("Assertion failed: expected 'this', got", result)
        exit(1)

    words = ["b       "]
    result = find_max(words)
    if result != "b":
        print("Assertion failed: expected 'b', got", result)
        exit(1)

    words = ["play    ", "play    ", "play    "]
    result = find_max(words)
    if result != "play":
        print("Assertion failed: expected 'play', got", result)
        exit(1)

    print("All tests passed.")
[/PY]

[JAVA]
import java.util.ArrayList;
import java.util.List;

public class FindMax {
    public static String findMax(List<String> words) {
        String max_word = "";
        String unique;
        String word;
        int maxu = 0;
        int len_words = words.size();

        for (int i = 0; i < len_words; i++) {
            word = words.get(i);
            unique = "";
            for (int j = 0; j < word.length(); j++) {
                if (unique.indexOf(word.charAt(j)) == -1) {
                    unique += word.charAt(j);
                }
            }
            if (unique.length() > maxu || (unique.length() == maxu && word.compareTo(max_word) < 0)) {
                max_word = word;
                maxu = unique.length();
            }
        }
        return max_word;
    }

    public static void main(String[] args) {
        List<String> words = new ArrayList<>();
