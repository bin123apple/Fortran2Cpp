#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int digits(int n) {
    string s = to_string(n);
    int prod = 1;
    int has = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] % 2 == 1) {
            has = 1;
            prod *= s[i] - '0';
        }
    }

    if (has == 0) {
        return 0;
    } else {
        return prod;
    }
}

int main() {
    assert(digits(5) == 5);
    assert(digits(54) == 5);
    assert(digits(120) == 1);
    assert(digits(5014) == 5);
    assert(digits(98765) == 315);
    assert(digits(5576543) == 2625);
    assert(digits(2468) == 0);
}

int assert(int condition) {
    if (!condition) {
        cout << "Assertion failed" << endl;
        exit(1);
    }
}

[C]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digits(int n) {
    char s[20];
    int prod = 1;
    int has = 0;

    sprintf(s, "%d", n);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] % 2 == 1) {
            has = 1;
            prod *= s[i] - '0';
        }
    }

    if (has == 0) {
        return 0;
    } else {
        return prod;
    }
}

int main() {
    assert(digits(5) == 5);
    assert(digits(54) == 5);
    assert(digits(120) == 1);
    assert(digits(5014) == 5);
    assert(digits(98765) == 315);
    assert(digits(5576543) == 2625);
    assert(digits(2468) == 0);
}

int assert(int condition) {
    if (!condition) {
        printf("Assertion failed
");
        exit(1);
    }
}

[Python]
def digits(n):
    s = str(n)
    prod = 1
    has = 0

    for i in range(len(s)):
        if int(s[i]) % 2 == 1:
            has = 1
            prod *= int(s[i])

    if has == 0:
        return 0
    else:
        return prod

def main():
    assert(digits(5) == 5)
    assert(digits(54) == 5)
    assert(digits(120) == 1)
    assert(digits(5014) == 5)
    assert(digits(98765) == 315)
    assert(digits(5576543) == 2625)
    assert(digits(2468) == 0)

def assert(condition):
    if not condition:
        print("Assertion failed")
        exit(1)

if __name__ == "__main__":
    main()

[Java]
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        assert(digits(5) == 5);
        assert(digits(54) == 5);
        assert(digits(120) == 1);
        assert(digits(5014) == 5);
        assert(digits(98765) == 315);
        assert(digits(5576543) == 2625);
        assert(digits(2468) == 0);
    }

    public static int digits(int n) {
        String s = Integer.toString(n);
        int prod = 1;
        int has = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) % 2 == 1) {
                has = 1;
                prod *= s.charAt(i) - '0';
            }
        }

        if (has == 0) {
            return 0;
        } else {
            return prod;
        }
    }

    public static void assert(boolean condition) {
        if (!condition) {
            System.out.println("Assertion failed");
            System.exit(1);
        }
    }
}

[JavaScript]
function digits(n) {
    let s = n.toString();
    let prod = 1;
    let has = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] % 2 == 1) {
            has = 1;
            prod *= s[i] - '0';
        }
    }

    if (has == 0) {
        return 0;
    } else {
        return prod;
    }
}

function main() {
    assert(digits(5) == 5);
    assert(digits(54) == 5);
    assert(digits(120) == 1);
    assert(digits(5014) == 5);
    assert(digits(98765) == 315);
    assert(digits(5576543) == 2625);
    assert(digits(2468) == 0);
}

function assert(condition) {
    if (!condition) {
        console.log("Assertion failed");
        process.exit(1);
    }
}

[PHP]
function digits($n) {
    $s = (string) $n;
    $prod = 1;
    $has = 0;

    for ($i = 0; $i < strlen($s); $i++) {
        if ($s[$i] % 2 == 1) {
            $has = 1;
            $prod *= $s[$i] - '0';
        }
    }

    if ($has == 0) {
        return 0;
    } else {
        return $prod;
    }
}

function main() {
    assert(digits(5) == 5);
    assert(digits(54) == 5);
    assert(digits(120) == 1);
    assert(digits(5014) == 5);
    assert(digits(98765) == 315);
    assert(digits(5576543) == 2625);
    assert(digits(2468) == 0);
}

function assert($condition) {
    if (!$condition) {
        echo "Assertion failed
";
        exit(1);
    }
}

[Ruby]
def digits(n)
    s = n.to_s
    prod = 1
    has = 0

    for i in 0...s.length
        if s[i].ord % 2 == 1
            has = 1
            prod *= s[i].ord - '0'.ord
        end
    end

    if has == 0
        return 0
    else
        return prod
    end
end

def main()
    assert(digits(5) == 5)
    assert(digits(54) == 5)
    assert(digits(120) == 1)
    assert(digits(5014) == 5)
    assert(digits(98765) == 315)
    assert(digits(55765
