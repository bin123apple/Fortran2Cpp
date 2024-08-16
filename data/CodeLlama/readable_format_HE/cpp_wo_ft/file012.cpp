#include <iostream>
#include <string>

int main() {
    std::string result;

    // Test cases
    result = string_sequence(0);
    if (result != "0") {
        std::cout << "Assertion failed: string_sequence(0) == '0'" << std::endl;
        return 1;
    }

    result = string_sequence(3);
    if (result != "0 1 2 3") {
        std::cout << "Assertion failed: string_sequence(3) == '0 1 2 3'" << std::endl;
        return 1;
    }

    result = string_sequence(10);
    if (result != "0 1 2 3 4 5 6 7 8 9 10") {
        std::cout << "Assertion failed: string_sequence(10) == '0 1 2 3 4 5 6 7 8 9 10'" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}

std::string string_sequence(int n) {
    std::string out = "0";
    for (int i = 1; i <= n; i++) {
        out += " " + std::to_string(i);
    }
    return out;
}
[/C++]

[C]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char result[100];

    // Test cases
    string_sequence(0, result);
    if (strcmp(result, "0") != 0) {
        printf("Assertion failed: string_sequence(0) == '0'
");
        return 1;
    }

    string_sequence(3, result);
    if (strcmp(result, "0 1 2 3") != 0) {
        printf("Assertion failed: string_sequence(3) == '0 1 2 3'
");
        return 1;
    }

    string_sequence(10, result);
    if (strcmp(result, "0 1 2 3 4 5 6 7 8 9 10") != 0) {
        printf("Assertion failed: string_sequence(10) == '0 1 2 3 4 5 6 7 8 9 10'
");
        return 1;
    }

    printf("All tests passed.
");

    return 0;
}

void string_sequence(int n, char *out) {
    sprintf(out, "0");
    for (int i = 1; i <= n; i++) {
        char temp[10];
        sprintf(temp, " %d", i);
        strcat(out, temp);
    }
}
[/C]

[Python]
def string_sequence(n):
    out = "0"
    for i in range(1, n + 1):
        out += " " + str(i)
    return out


# Test cases
assert string_sequence(0) == "0"
assert string_sequence(3) == "0 1 2 3"
assert string_sequence(10) == "0 1 2 3 4 5 6 7 8 9 10"

print("All tests passed.")
[/Python]

[JavaScript]
function string_sequence(n) {
    let out = "0";
    for (let i = 1; i <= n; i++) {
        out += " " + i;
    }
    return out;
}

// Test cases
console.assert(string_sequence(0) === "0");
console.assert(string_sequence(3) === "0 1 2 3");
console.assert(string_sequence(10) === "0 1 2 3 4 5 6 7 8 9 10");

console.log("All tests passed.");
[/JavaScript]

[PHP]
function string_sequence($n) {
    $out = "0";
    for ($i = 1; $i <= $n; $i++) {
        $out .= " " . $i;
    }
    return $out;
}

// Test cases
assert(string_sequence(0) === "0");
assert(string_sequence(3) === "0 1 2 3");
assert(string_sequence(10) === "0 1 2 3 4 5 6 7 8 9 10");

echo "All tests passed.
";
[/PHP]

[Go]
package main

import "fmt"

func string_sequence(n int) string {
    out := "0"
    for i := 1; i <= n; i++ {
        out += " " + fmt.Sprintf("%d", i)
    }
    return out
}

// Test cases
func main() {
    assert(string_sequence(0) == "0")
    assert(string_sequence(3) == "0 1 2 3")
    assert(string_sequence(10) == "0 1 2 3 4 5 6 7 8 9 10")

    fmt.Println("All tests passed.")
}

func assert(b bool) {
    if !b {
        panic("Assertion failed")
    }
}
[/Go]

[Ruby]
def string_sequence(n)
    out = "0"
    for i in 1..n
        out += " " + i.to_s
    end
    return out
end

# Test cases
assert(string_sequence(0) == "0")
assert(string_sequence(3) == "0 1 2 3")
assert(string_sequence(10) == "0 1 2 3 4 5 6 7 8 9 10")

puts "All tests passed."
[/Ruby]

[Swift]
func string_sequence(_ n: Int) -> String {
    var out = "0"
    for i in 1...n {
        out += " " + String(i)
    }
    return out
}

// Test cases
assert(string_sequence(0) == "0")
assert(string_sequence(3) == "0 1 2 3")
assert(string_sequence(10) == "0 1 2 3 4 5 6 7 8 9 10")

print("All tests passed.")
[/Swift]

[Rust]
fn string_sequence(n: i32) -> String {
    let mut out = "0".to_string();
    for i in 1..=n {
        out += " " + i.to_string().as_str();
    }
    out
}

// Test cases
fn main() {
    assert_eq!(string_sequence(0), "0");
    assert_eq!(string_sequence(3), "0 1 2 3");
    assert_eq!(string_sequence(10), "0 1 2 3 4 5 6 7 8 9 10");

    println!("All tests passed.");
}

#[test]
fn test_string_sequence() {
    assert_eq!(string_sequence(0), "0");
    assert_eq!(string_sequence(3), "0 1 2 3");
    assert_eq!(string_sequence(10), "0 1 2 3 4 5 6 7 8 9 10");
}
[/Rust]

[Kotlin]
fun stringSequence(n: Int): String {
    var out = "0"
    for (i in 1..n) {
        out += " " + i.toString()
    }
    return out
}

// Test cases
fun main() {
    assert(stringSequence(0) == "0")
    assert(stringSequence(3) == "0 1 2 3")
    assert(stringSequence(10) == "0 1 2 3 4 5 6 7 8 9 10")
