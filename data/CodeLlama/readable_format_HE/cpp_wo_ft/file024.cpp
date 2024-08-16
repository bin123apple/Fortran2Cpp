#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> filter_by_prefix(vector<string> strings, string prefix) {
    vector<string> out;
    for (string s : strings) {
        if (s.substr(0, prefix.length()) == prefix) {
            out.push_back(s);
        }
    }
    return out;
}

int main() {
    vector<string> strings;
    string prefix;
    vector<string> result;

    // Test case 1
    result = filter_by_prefix(strings, prefix);
    if (result != strings) {
        cout << "Assertion failed: filter_by_prefix({}, 'john')" << endl;
        return 1;
    }

    // Test case 2
    strings = {"xxx     ", "asd     ", "xxy     ", "john doe", "xxxAAA  ", "xxx     "};
    prefix = "xxx";
    result = filter_by_prefix(strings, prefix);
    vector<string> expected = {"xxx     ", "xxxAAA  ", "xxx     "};
    if (result != expected) {
        cout << "Assertion failed: filter_by_prefix({'xxx', 'asd', 'xxy', 'john doe', 'xxxAAA', 'xxx'}, 'xxx')" << endl;
        return 1;
    }

    return 0;
} [/CPP]

[PYTHON]
def filter_by_prefix(strings, prefix):
    return [s for s in strings if s.startswith(prefix)]


def test_cases():
    # Test case 1
    strings = []
    prefix = ""
    result = filter_by_prefix(strings, prefix)
    expected = []
    assert result == expected

    # Test case 2
    strings = ["xxx     ", "asd     ", "xxy     ", "john doe", "xxxAAA  ", "xxx     "]
    prefix = "xxx"
    result = filter_by_prefix(strings, prefix)
    expected = ["xxx     ", "xxxAAA  ", "xxx     "]
    assert result == expected


if __name__ == "__main__":
    test_cases()
[/PYTHON]

[JAVA]
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static List<String> filterByPrefix(List<String> strings, String prefix) {
        List<String> out = new ArrayList<>();
        for (String s : strings) {
            if (s.startsWith(prefix)) {
                out.add(s);
            }
        }
        return out;
    }

    public static void main(String[] args) {
        // Test case 1
        List<String> strings = new ArrayList<>();
        String prefix = "";
        List<String> result = filterByPrefix(strings, prefix);
        List<String> expected = new ArrayList<>();
        assert result.equals(expected);

        // Test case 2
        strings = Arrays.asList("xxx     ", "asd     ", "xxy     ", "john doe", "xxxAAA  ", "xxx     ");
        prefix = "xxx";
        result = filterByPrefix(strings, prefix);
        expected = Arrays.asList("xxx     ", "xxxAAA  ", "xxx     ");
        assert result.equals(expected);
    }
} [/JAVA]

[C#]
using System;
using System.Collections.Generic;

public class Program {
    public static List<string> FilterByPrefix(List<string> strings, string prefix) {
        List<string> out = new List<string>();
        foreach (string s in strings) {
            if (s.StartsWith(prefix)) {
                out.Add(s);
            }
        }
        return out;
    }

    public static void Main() {
        // Test case 1
        List<string> strings = new List<string>();
        string prefix = "";
        List<string> result = FilterByPrefix(strings, prefix);
        List<string> expected = new List<string>();
        if (result.Count != expected.Count) {
            Console.WriteLine("Assertion failed: FilterByPrefix({}, 'john')");
            Environment.Exit(1);
        }

        // Test case 2
        strings = new List<string> { "xxx     ", "asd     ", "xxy     ", "john doe", "xxxAAA  ", "xxx     " };
        prefix = "xxx";
        result = FilterByPrefix(strings, prefix);
        expected = new List<string> { "xxx     ", "xxxAAA  ", "xxx     " };
        if (result.Count != expected.Count) {
            Console.WriteLine("Assertion failed: FilterByPrefix({'xxx', 'asd', 'xxy', 'john doe', 'xxxAAA', 'xxx'}, 'xxx')");
            Environment.Exit(1);
        }
    }
} [/C#]

[GO]
package main

import (
    "fmt"
    "strings"
)

func filterByPrefix(strings []string, prefix string) []string {
    out := []string{}
    for _, s := range strings {
        if strings.HasPrefix(s, prefix) {
            out = append(out, s)
        }
    }
    return out
}

func main() {
    // Test case 1
    strings := []string{}
    prefix := ""
    result := filterByPrefix(strings, prefix)
    expected := []string{}
    if len(result) != len(expected) {
        fmt.Println("Assertion failed: filterByPrefix({}, 'john')")
        return
    }

    // Test case 2
    strings = []string{"xxx     ", "asd     ", "xxy     ", "john doe", "xxxAAA  ", "xxx     "}
    prefix = "xxx"
    result = filterByPrefix(strings, prefix)
    expected = []string{"xxx     ", "xxxAAA  ", "xxx     "}
    if len(result) != len(expected) {
        fmt.Println("Assertion failed: filterByPrefix({'xxx', 'asd', 'xxy', 'john doe', 'xxxAAA', 'xxx'}, 'xxx')")
        return
    }
} [/GO]

[PHP]
function filterByPrefix($strings, $prefix) {
    $out = [];
    foreach ($strings as $s) {
        if (strpos($s, $prefix) === 0) {
            $out[] = $s;
        }
    }
    return $out;
}

function testCases() {
    // Test case 1
    $strings = [];
    $prefix = "";
    $result = filterByPrefix($strings, $prefix);
    $expected = [];
    if ($result != $expected) {
        echo "Assertion failed: filterByPrefix({}, 'john')";
        exit(1);
    }

    // Test case 2
    $strings = ["xxx     ", "asd     ", "xxy     ", "john doe", "xxxAAA  ", "xxx     "];
    $prefix = "xxx";
    $result = filterByPrefix($strings, $prefix);
    $expected = ["xxx     ", "xxxAAA  ", "xxx     "];
    if ($result != $expected) {
        echo "Assertion failed: filterByPrefix({'xxx', 'asd', 'xxy', 'john doe', 'xxxAAA', 'xxx'}, 'xxx')";
        exit(1);
    }
}

testCases(); [/PHP]

[RUBY]
def filter_by_prefix(strings, prefix)
    out = []
    strings.each do |s|
        if s.start_with?(prefix)
            out.push(s)
        end
    end
    out
end

def test_cases
    # Test case 1
    strings = []
    prefix = ""
    result = filter_by_prefix(strings, prefix)
    expected = []
    assert_equal(result, expected)

    # Test case 2
    strings = ["xxx     ", "asd     ", "xxy     ", "john doe", "xxxAAA  ", "xxx     "
