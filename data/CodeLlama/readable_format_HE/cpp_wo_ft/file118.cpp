#include <iostream>
#include <string>

bool cycpattern_check(const std::string& a, const std::string& b)
{
    for (int i = 0; i < b.length(); i++) {
        std::string rotate = b.substr(i+1) + b.substr(0, i);
        // Debugging print statement
        // std::cout << "Checking rotation: " << rotate << std::endl;
        if (a.find(rotate) != std::string::npos) {
            return true;
        }
    }
    return false;
}

int main()
{
    if (!cycpattern_check("xyzw", "xyw")) {
        std::cout << "Assertion failed: cycpattern_check('xyzw', 'xyw') == false" << std::endl;
        return 1;
    }
    if (!cycpattern_check("yello", "ell")) {
        std::cout << "Assertion failed: cycpattern_check('yello', 'ell') == true" << std::endl;
        return 1;
    }
    if (!cycpattern_check("whattup", "ptut")) {
        std::cout << "Assertion failed: cycpattern_check('whattup', 'ptut') == false" << std::endl;
        return 1;
    }
    if (!cycpattern_check("efef", "fee")) {
        std::cout << "Assertion failed: cycpattern_check('efef', 'fee') == true" << std::endl;
        return 1;
    }
    if (!cycpattern_check("abab", "aabb")) {
        std::cout << "Assertion failed: cycpattern_check('abab', 'aabb') == false" << std::endl;
        return 1;
    }
    if (!cycpattern_check("winemtt", "tinem")) {
        std::cout << "Assertion failed: cycpattern_check('winemtt', 'tinem') == true" << std::endl;
        return 1;
    }
    return 0;
}

[C#]
using System;

class CycPatternCheck
{
    static void Main()
    {
        if (!cycpattern_check("xyzw", "xyw")) {
            Console.WriteLine("Assertion failed: cycpattern_check('xyzw', 'xyw') == false");
            Environment.Exit(1);
        }
        if (!cycpattern_check("yello", "ell")) {
            Console.WriteLine("Assertion failed: cycpattern_check('yello', 'ell') == true");
            Environment.Exit(1);
        }
        if (!cycpattern_check("whattup", "ptut")) {
            Console.WriteLine("Assertion failed: cycpattern_check('whattup', 'ptut') == false");
            Environment.Exit(1);
        }
        if (!cycpattern_check("efef", "fee")) {
            Console.WriteLine("Assertion failed: cycpattern_check('efef', 'fee') == true");
            Environment.Exit(1);
        }
        if (!cycpattern_check("abab", "aabb")) {
            Console.WriteLine("Assertion failed: cycpattern_check('abab', 'aabb') == false");
            Environment.Exit(1);
        }
        if (!cycpattern_check("winemtt", "tinem")) {
            Console.WriteLine("Assertion failed: cycpattern_check('winemtt', 'tinem') == true");
            Environment.Exit(1);
        }
    }

    static bool cycpattern_check(string a, string b)
    {
        for (int i = 0; i < b.Length; i++) {
            string rotate = b.Substring(i+1) + b.Substring(0, i);
            // Debugging print statement
            // Console.WriteLine("Checking rotation: " + rotate);
            if (a.IndexOf(rotate) != -1) {
                return true;
            }
        }
        return false;
    }
}

[Python]
def cycpattern_check(a, b):
    for i in range(len(b)):
        rotate = b[i+1:] + b[:i]
        # Debugging print statement
        # print("Checking rotation: " + rotate)
        if rotate in a:
            return True
    return False

def main():
    if not cycpattern_check("xyzw", "xyw"):
        print("Assertion failed: cycpattern_check('xyzw', 'xyw') == false")
        exit(1)
    if not cycpattern_check("yello", "ell"):
        print("Assertion failed: cycpattern_check('yello', 'ell') == true")
        exit(1)
    if not cycpattern_check("whattup", "ptut"):
        print("Assertion failed: cycpattern_check('whattup', 'ptut') == false")
        exit(1)
    if not cycpattern_check("efef", "fee"):
        print("Assertion failed: cycpattern_check('efef', 'fee') == true")
        exit(1)
    if not cycpattern_check("abab", "aabb"):
        print("Assertion failed: cycpattern_check('abab', 'aabb') == false")
        exit(1)
    if not cycpattern_check("winemtt", "tinem"):
        print("Assertion failed: cycpattern_check('winemtt', 'tinem') == true")
        exit(1)

if __name__ == "__main__":
    main()

[Ruby]
def cycpattern_check(a, b)
    b.length.times do |i|
        rotate = b[i+1..-1] + b[0..i]
        # Debugging print statement
        # puts "Checking rotation: #{rotate}"
        return true if a.include?(rotate)
    end
    false
end

def main
    if !cycpattern_check("xyzw", "xyw")
        puts "Assertion failed: cycpattern_check('xyzw', 'xyw') == false"
        exit(1)
    end
    if !cycpattern_check("yello", "ell")
        puts "Assertion failed: cycpattern_check('yello', 'ell') == true"
        exit(1)
    end
    if !cycpattern_check("whattup", "ptut")
        puts "Assertion failed: cycpattern_check('whattup', 'ptut') == false"
        exit(1)
    end
    if !cycpattern_check("efef", "fee")
        puts "Assertion failed: cycpattern_check('efef', 'fee') == true"
        exit(1)
    end
    if !cycpattern_check("abab", "aabb")
        puts "Assertion failed: cycpattern_check('abab', 'aabb') == false"
        exit(1)
    end
    if !cycpattern_check("winemtt", "tinem")
        puts "Assertion failed: cycpattern_check('winemtt', 'tinem') == true"
        exit(1)
    end
end

main

[JavaScript]
function cycpattern_check(a, b) {
    for (let i = 0; i < b.length; i++) {
        let rotate = b.slice(i+1) + b.slice(0, i);
        // Debugging print statement
        // console.log("Checking rotation: " + rotate);
        if (a.includes(rotate)) {
            return true;
        }
    }
    return false;
}

function main() {
    if (!cycpattern_check("xyzw", "xyw")) {
        console.log("Assertion failed: cycpattern_check('xyzw', 'xyw') == false");
        process.exit(1);
    }
    if (!cycpattern_check("yello", "ell")) {
        console.log("Assertion failed: cycpattern_check('yello', 'ell') == true");
        process.exit(1);
    }
    if (!cycpattern_check("whattup", "ptut")) {
        console.log("Assertion failed: cycpattern_check('whattup', 'ptut') ==
