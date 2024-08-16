#include <string>
#include <vector>
#include <iostream>

using namespace std;

string int_to_mini_romank(int number) {
    vector<string> rep = {"m ", "cm", "d ", "cd", "c ", "xc", "l ", "xl", "x ", "ix", "v ", "iv", "i "};
    vector<int> num = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string current = "";
    int pos = 1;
    int temp_number = number;

    while (temp_number > 0) {
        while (temp_number >= num[pos]) {
            current += rep[pos];
            temp_number -= num[pos];
        }
        if (temp_number > 0) pos++;
    }

    return current;
}

int main() {
    cout << int_to_mini_romank(19) << endl;
    cout << int_to_mini_romank(152) << endl;
    cout << int_to_mini_romank(251) << endl;
    cout << int_to_mini_romank(426) << endl;
    cout << int_to_mini_romank(500) << endl;
    cout << int_to_mini_romank(1) << endl;
    cout << int_to_mini_romank(4) << endl;
    cout << int_to_mini_romank(43) << endl;
    cout << int_to_mini_romank(90) << endl;
    cout << int_to_mini_romank(94) << endl;
    cout << int_to_mini_romank(532) << endl;
    cout << int_to_mini_romank(900) << endl;
    cout << int_to_mini_romank(994) << endl;
    cout << int_to_mini_romank(1000) << endl;
}

[C#]
using System;

public static class Program {
    public static string IntToMiniRoman(int number) {
        string[] rep = {"m ", "cm", "d ", "cd", "c ", "xc", "l ", "xl", "x ", "ix", "v ", "iv", "i "};
        int[] num = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string current = "";
        int pos = 1;
        int temp_number = number;

        while (temp_number > 0) {
            while (temp_number >= num[pos]) {
                current += rep[pos];
                temp_number -= num[pos];
            }
            if (temp_number > 0) pos++;
        }

        return current;
    }

    public static void Main() {
        Console.WriteLine(IntToMiniRoman(19));
        Console.WriteLine(IntToMiniRoman(152));
        Console.WriteLine(IntToMiniRoman(251));
        Console.WriteLine(IntToMiniRoman(426));
        Console.WriteLine(IntToMiniRoman(500));
        Console.WriteLine(IntToMiniRoman(1));
        Console.WriteLine(IntToMiniRoman(4));
        Console.WriteLine(IntToMiniRoman(43));
        Console.WriteLine(IntToMiniRoman(90));
        Console.WriteLine(IntToMiniRoman(94));
        Console.WriteLine(IntToMiniRoman(532));
        Console.WriteLine(IntToMiniRoman(900));
        Console.WriteLine(IntToMiniRoman(994));
        Console.WriteLine(IntToMiniRoman(1000));
    }
}

[Python]
def int_to_mini_romank(number):
    rep = ["m ", "cm", "d ", "cd", "c ", "xc", "l ", "xl", "x ", "ix", "v ", "iv", "i "]
    num = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    current = ""
    pos = 1
    temp_number = number

    while temp_number > 0:
        while temp_number >= num[pos]:
            current += rep[pos]
            temp_number -= num[pos]
        if temp_number > 0: pos += 1

    return current

print(int_to_mini_romank(19))
print(int_to_mini_romank(152))
print(int_to_mini_romank(251))
print(int_to_mini_romank(426))
print(int_to_mini_romank(500))
print(int_to_mini_romank(1))
print(int_to_mini_romank(4))
print(int_to_mini_romank(43))
print(int_to_mini_romank(90))
print(int_to_mini_romank(94))
print(int_to_mini_romank(532))
print(int_to_mini_romank(900))
print(int_to_mini_romank(994))
print(int_to_mini_romank(1000))

[JavaScript]
function int_to_mini_romank(number) {
    var rep = ["m ", "cm", "d ", "cd", "c ", "xc", "l ", "xl", "x ", "ix", "v ", "iv", "i "];
    var num = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    var current = "";
    var pos = 1;
    var temp_number = number;

    while (temp_number > 0) {
        while (temp_number >= num[pos]) {
            current += rep[pos];
            temp_number -= num[pos];
        }
        if (temp_number > 0) pos++;
    }

    return current;
}

console.log(int_to_mini_romank(19));
console.log(int_to_mini_romank(152));
console.log(int_to_mini_romank(251));
console.log(int_to_mini_romank(426));
console.log(int_to_mini_romank(500));
console.log(int_to_mini_romank(1));
console.log(int_to_mini_romank(4));
console.log(int_to_mini_romank(43));
console.log(int_to_mini_romank(90));
console.log(int_to_mini_romank(94));
console.log(int_to_mini_romank(532));
console.log(int_to_mini_romank(900));
console.log(int_to_mini_romank(994));
console.log(int_to_mini_romank(1000));

[PHP]
function int_to_mini_romank($number) {
    $rep = ["m ", "cm", "d ", "cd", "c ", "xc", "l ", "xl", "x ", "ix", "v ", "iv", "i "];
    $num = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9,
