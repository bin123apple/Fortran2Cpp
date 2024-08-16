#include <iostream>
#include <string>

int how_many_times(std::string str, std::string substring) {
    int out = 0;
    int str_len = str.length();
    int sub_len = substring.length();

    if (str_len == 0) {
        return 0;
    }

    for (int i = 0; i < str_len - sub_len + 1; i++) {
        if (str.substr(i, sub_len) == substring) {
            out++;
        }
    }

    return out;
}

int main() {
    // Test cases
    int result = how_many_times("", "x");
    if (result != 0) {
        std::cout << "Assertion failed: how_many_times('', 'x') == 0" << std::endl;
        return 1;
    }

    result = how_many_times("xyxyxyx", "x");
    if (result != 4) {
        std::cout << "Assertion failed: how_many_times('xyxyxyx', 'x') == 4" << std::endl;
        return 1;
    }

    result = how_many_times("cacacacac", "cac");
    if (result != 4) {
        std::cout << "Assertion failed: how_many_times('cacacacac', 'cac') == 4" << std::endl;
        return 1;
    }

    result = how_many_times("john doe", "john");
    if (result != 1) {
        std::cout << "Assertion failed: how_many_times('john doe', 'john') == 1" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
[/CPP]

[PYTHON]
def how_many_times(str, substring):
    out = 0
    str_len = len(str)
    sub_len = len(substring)

    if str_len == 0:
        return 0

    for i in range(str_len - sub_len + 1):
        if str[i:i+sub_len] == substring:
            out += 1

    return out


# Test cases
assert how_many_times("", "x") == 0
assert how_many_times("xyxyxyx", "x") == 4
assert how_many_times("cacacacac", "cac") == 4
assert how_many_times("john doe", "john") == 1

print("All tests passed.")
[/PYTHON]

[JAVA]
public class StringUtils {
    public static int howManyTimes(String str, String substring) {
        int out = 0;
        int str_len = str.length();
        int sub_len = substring.length();

        if (str_len == 0) {
            return 0;
        }

        for (int i = 0; i < str_len - sub_len + 1; i++) {
            if (str.substring(i, i + sub_len).equals(substring)) {
                out++;
            }
        }

        return out;
    }

    public static void main(String[] args) {
        // Test cases
        assert howManyTimes("", "x") == 0;
        assert howManyTimes("xyxyxyx", "x") == 4;
        assert howManyTimes("cacacacac", "cac") == 4;
        assert howManyTimes("john doe", "john") == 1;

        System.out.println("All tests passed.");
    }
}
[/JAVA]

[RUBY]
def how_many_times(str, substring)
    out = 0
    str_len = str.length
    sub_len = substring.length

    if str_len == 0
        return 0
    end

    for i in 0..str_len - sub_len
        if str[i, sub_len] == substring
            out += 1
        end
    end

    return out
end

# Test cases
assert how_many_times("", "x") == 0
assert how_many_times("xyxyxyx", "x") == 4
assert how_many_times("cacacacac", "cac") == 4
assert how_many_times("john doe", "john") == 1

puts "All tests passed."
[/RUBY]

[CSHARP]
using System;

public class StringUtils
{
    public static int HowManyTimes(string str, string substring)
    {
        int out = 0;
        int str_len = str.Length;
        int sub_len = substring.Length;

        if (str_len == 0)
        {
            return 0;
        }

        for (int i = 0; i < str_len - sub_len + 1; i++)
        {
            if (str.Substring(i, sub_len) == substring)
            {
                out++;
            }
        }

        return out;
    }

    public static void Main(string[] args)
    {
        // Test cases
        assert HowManyTimes("", "x") == 0;
        assert HowManyTimes("xyxyxyx", "x") == 4;
        assert HowManyTimes("cacacacac", "cac") == 4;
        assert HowManyTimes("john doe", "john") == 1;

        Console.WriteLine("All tests passed.");
    }
}
[/CSHARP]

[PHP]
function how_many_times($str, $substring)
{
    $out = 0;
    $str_len = strlen($str);
    $sub_len = strlen($substring);

    if ($str_len == 0) {
        return 0;
    }

    for ($i = 0; $i < $str_len - $sub_len + 1; $i++) {
        if (substr($str, $i, $sub_len) == $substring) {
            $out++;
        }
    }

    return $out;
}

// Test cases
assert(how_many_times("", "x") == 0);
assert(how_many_times("xyxyxyx", "x") == 4);
assert(how_many_times("cacacacac", "cac") == 4);
assert(how_many_times("john doe", "john") == 1);

echo "All tests passed.";
[/PHP]

[GO]
package main

import "fmt"

func howManyTimes(str, substring string) int {
    out := 0
    str_len := len(str)
    sub_len := len(substring)

    if str_len == 0 {
        return 0
    }

    for i := 0; i < str_len-sub_len+1; i++ {
        if str[i:i+sub_len] == substring {
            out++
        }
    }

    return out
}

func main() {
    // Test cases
    assert(howManyTimes("", "x") == 0)
    assert(howManyTimes("xyxyxyx", "x") == 4)
    assert(howManyTimes("cacacacac", "cac") == 4)
    assert(howManyTimes("john doe", "john") == 1)

    fmt.Println("All tests passed.")
}

func assert(b bool) {
    if !b {
        panic("Assertion failed")
    }
}
[/GO]

[MATLAB]
function out = how_many_times(str, substring)
    out = 0;
    str_len = length(str);
    sub_len = length(substring);

    if str_len == 0
        return 0;
    end

    for i = 1:str_len - sub_len + 1
        if str(i:i+sub_len-1
