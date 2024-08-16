#include <iostream>
#include <string>
#include <vector>

using namespace std;

void all_prefixes(const string &str, vector<string> &out) {
    if (str.empty()) {
        out.push_back("");
        return;
    }

    for (int i = 0; i < str.size(); i++) {
        string current = str.substr(0, i + 1);
        out.push_back(current);
    }
}

int main() {
    string str;
    vector<string> prefixes;
    vector<string> expected;
    int i;

    // Test cases
    str = "";
    all_prefixes(str, prefixes);
    expected = {""};
    if (prefixes != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    str = "asdfgh";
    all_prefixes(str, prefixes);
    expected = {"a", "as", "asd", "asdf", "asdfg", "asdfgh"};
    if (prefixes != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    str = "WWW";
    all_prefixes(str, prefixes);
    expected = {"W", "WW", "WWW"};
    if (prefixes != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    return 0;
}

[/FOLD]

[FOLD=Python]

def all_prefixes(str):
    if len(str) == 0:
        return [""]

    prefixes = []
    for i in range(len(str)):
        prefixes.append(str[:i + 1])
    return prefixes


def assert_same(a, b):
    if len(a) != len(b):
        print("Assertion failed")
        exit(1)

    for i in range(len(a)):
        if a[i] != b[i]:
            print("Assertion failed")
            exit(1)


def main():
    str = ""
    prefixes = all_prefixes(str)
    expected = [""]
    assert_same(prefixes, expected)

    str = "asdfgh"
    prefixes = all_prefixes(str)
    expected = ["a", "as", "asd", "asdf", "asdfg", "asdfgh"]
    assert_same(prefixes, expected)

    str = "WWW"
    prefixes = all_prefixes(str)
    expected = ["W", "WW", "WWW"]
    assert_same(prefixes, expected)


if __name__ == "__main__":
    main()

[/FOLD]

[FOLD=Rust]

fn all_prefixes(str: &str) -> Vec<String> {
    if str.is_empty() {
        return vec!["".to_string()];
    }

    let mut prefixes = Vec::new();
    for i in 0..str.len() {
        prefixes.push(str[..i + 1].to_string());
    }
    prefixes
}

fn assert_same(a: &[String], b: &[String]) {
    if a.len() != b.len() {
        println!("Assertion failed");
        std::process::exit(1);
    }

    for i in 0..a.len() {
        if a[i] != b[i] {
            println!("Assertion failed");
            std::process::exit(1);
        }
    }
}

fn main() {
    let str = "";
    let prefixes = all_prefixes(str);
    let expected = vec!["".to_string()];
    assert_same(&prefixes, &expected);

    let str = "asdfgh";
    let prefixes = all_prefixes(str);
    let expected = vec!["a".to_string(), "as".to_string(), "asd".to_string(), "asdf".to_string(), "asdfg".to_string(), "asdfgh".to_string()];
    assert_same(&prefixes, &expected);

    let str = "WWW";
    let prefixes = all_prefixes(str);
    let expected = vec!["W".to_string(), "WW".to_string(), "WWW".to_string()];
    assert_same(&prefixes, &expected);
}

[/FOLD]

[FOLD=C#]

using System;
using System.Collections.Generic;

namespace AllPrefixes
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "";
            var prefixes = AllPrefixes(str);
            var expected = new List<string> { "" };
            if (!Same(prefixes, expected))
            {
                Console.WriteLine("Assertion failed");
                Environment.Exit(1);
            }

            str = "asdfgh";
            prefixes = AllPrefixes(str);
            expected = new List<string> { "a", "as", "asd", "asdf", "asdfg", "asdfgh" };
            if (!Same(prefixes, expected))
            {
                Console.WriteLine("Assertion failed");
                Environment.Exit(1);
            }

            str = "WWW";
            prefixes = AllPrefixes(str);
            expected = new List<string> { "W", "WW", "WWW" };
            if (!Same(prefixes, expected))
            {
                Console.WriteLine("Assertion failed");
                Environment.Exit(1);
            }
        }

        static List<string> AllPrefixes(string str)
        {
            if (str.Length == 0)
            {
                return new List<string> { "" };
            }

            var prefixes = new List<string>();
            for (int i = 0; i < str.Length; i++)
            {
                prefixes.Add(str.Substring(0, i + 1));
            }
            return prefixes;
        }

        static bool Same(List<string> a, List<string> b)
        {
            if (a.Count != b.Count)
            {
                return false;
            }

            for (int i = 0; i < a.Count; i++)
            {
                if (a[i] != b[i])
                {
                    return false;
                }
            }

            return true;
        }
    }
}

[/FOLD]

[FOLD=Java]

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        String str = "";
        List<String> prefixes = allPrefixes(str);
        List<String> expected = new ArrayList<>();
        expected.add("");
        if (!same(prefixes, expected)) {
            System.out.println("Assertion failed");
            System.exit(1);
        }

        str = "asdfgh";
        prefixes = allPrefixes(str);
        expected = new ArrayList<>();
        expected.add("a");
        expected.add("as");
        expected.add("asd");
        expected.add("asdf");
        expected.add("asdfg");
        expected.add("asdfgh");
        if (!same(prefixes, expected)) {
            System.out.println("Assertion failed");
            System.exit(1);
        }

        str = "WWW";
        prefixes = allPrefixes(str);
        expected = new ArrayList<>();
        expected.add("W");
        expected.add("WW");
        expected.add("WWW");
        if (!same(prefixes, expected)) {
            System.out.println("Assertion failed");
            System.exit(1);
        }
    }

    static List<String> allPrefixes(String str) {
        if (str.length() == 0) {
            return List.of("");
