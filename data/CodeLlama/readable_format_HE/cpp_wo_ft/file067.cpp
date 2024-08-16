#include <iostream>
#include <string>

int main()
{
    std::string key = "2357BD";
    std::string num;
    int result;

    // Main program body
    num = "AB";
    result = hex_key(num);
    if (result != 1) {
        std::cout << "Assertion failed" << std::endl;
        return 1;
    }

    num = "1077E";
    result = hex_key(num);
    if (result != 2) {
        std::cout << "Assertion failed" << std::endl;
        return 1;
    }

    num = "ABED1A33";
    result = hex_key(num);
    if (result != 4) {
        std::cout << "Assertion failed" << std::endl;
        return 1;
    }

    num = "2020";
    result = hex_key(num);
    if (result != 2) {
        std::cout << "Assertion failed" << std::endl;
        return 1;
    }

    num = "123456789ABCDEF0";
    result = hex_key(num);
    if (result != 6) {
        std::cout << "Assertion failed" << std::endl;
        return 1;
    }

    num = "112233445566778899AABBCCDDEEFF00";
    result = hex_key(num);
    if (result != 12) {
        std::cout << "Assertion failed" << std::endl;
        return 1;
    }

    num = "";
    result = hex_key(num);
    if (result != 0) {
        std::cout << "Assertion failed" << std::endl;
        return 1;
    }

    return 0;
}

int hex_key(std::string num)
{
    std::string key = "2357BD";
    int out = 0;
    for (int i = 0; i < num.length(); i++) {
        if (key.find(num[i]) != std::string::npos) {
            out++;
        }
    }
    return out;
}
[/C++]

[C]
#include <stdio.h>
#include <string.h>

int main()
{
    char key[] = "2357BD";
    char num[100];
    int result;

    // Main program body
    strcpy(num, "AB");
    result = hex_key(num);
    if (result != 1) {
        printf("Assertion failed
");
        return 1;
    }

    strcpy(num, "1077E");
    result = hex_key(num);
    if (result != 2) {
        printf("Assertion failed
");
        return 1;
    }

    strcpy(num, "ABED1A33");
    result = hex_key(num);
    if (result != 4) {
        printf("Assertion failed
");
        return 1;
    }

    strcpy(num, "2020");
    result = hex_key(num);
    if (result != 2) {
        printf("Assertion failed
");
        return 1;
    }

    strcpy(num, "123456789ABCDEF0");
    result = hex_key(num);
    if (result != 6) {
        printf("Assertion failed
");
        return 1;
    }

    strcpy(num, "112233445566778899AABBCCDDEEFF00");
    result = hex_key(num);
    if (result != 12) {
        printf("Assertion failed
");
        return 1;
    }

    strcpy(num, "");
    result = hex_key(num);
    if (result != 0) {
        printf("Assertion failed
");
        return 1;
    }

    return 0;
}

int hex_key(char *num)
{
    char key[] = "2357BD";
    int out = 0;
    for (int i = 0; i < strlen(num); i++) {
        if (strchr(key, num[i]) != NULL) {
            out++;
        }
    }
    return out;
}
[/C]

[Python]
def hex_key(num):
    key = "2357BD"
    out = 0
    for i in range(len(num)):
        if num[i] in key:
            out += 1
    return out


def main():
    assert(hex_key("AB") == 1)
    assert(hex_key("1077E") == 2)
    assert(hex_key("ABED1A33") == 4)
    assert(hex_key("2020") == 2)
    assert(hex_key("123456789ABCDEF0") == 6)
    assert(hex_key("112233445566778899AABBCCDDEEFF00") == 12)
    assert(hex_key("") == 0)


if __name__ == "__main__":
    main()
[/Python]

[JavaScript]
function hex_key(num) {
    var key = "2357BD";
    var out = 0;
    for (var i = 0; i < num.length; i++) {
        if (key.indexOf(num[i]) != -1) {
            out++;
        }
    }
    return out;
}

function main() {
    assert(hex_key("AB") == 1);
    assert(hex_key("1077E") == 2);
    assert(hex_key("ABED1A33") == 4);
    assert(hex_key("2020") == 2);
    assert(hex_key("123456789ABCDEF0") == 6);
    assert(hex_key("112233445566778899AABBCCDDEEFF00") == 12);
    assert(hex_key("") == 0);
}

main();
[/JavaScript]

[PHP]
function hex_key($num) {
    $key = "2357BD";
    $out = 0;
    for ($i = 0; $i < strlen($num); $i++) {
        if (strpos($key, $num[$i]) !== false) {
            $out++;
        }
    }
    return $out;
}

function main() {
    assert(hex_key("AB") == 1);
    assert(hex_key("1077E") == 2);
    assert(hex_key("ABED1A33") == 4);
    assert(hex_key("2020") == 2);
    assert(hex_key("123456789ABCDEF0") == 6);
    assert(hex_key("112233445566778899AABBCCDDEEFF00") == 12);
    assert(hex_key("") == 0);
}

main();
[/PHP]

[Ruby]
def hex_key(num)
    key = "2357BD"
    out = 0
    num.each_char do |char|
        if key.include?(char)
            out += 1
        end
    end
    return out
end

def main()
    assert(hex_key("AB") == 1)
    assert(hex_key("1077E") == 2)
    assert(hex_key("ABED1A33") == 4)
    assert(hex_key("2020") == 2)
    assert(hex_key("1234
