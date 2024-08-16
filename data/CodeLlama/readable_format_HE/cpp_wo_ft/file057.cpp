#include <iostream>
#include <string>

using namespace std;

int fruit_distribution(string s, int n) {
    int num1 = 0, num2 = 0, is12 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (is12 == 0) {
                num1 = num1 * 10 + (s[i] - '0');
            } else if (is12 == 1) {
                num2 = num2 * 10 + (s[i] - '0');
            }
        } else if (is12 == 0 && num1 > 0) {
            is12 = 1;
        }
    }

    return n - num1 - num2;
}

int main() {
    string s;
    int n;

    // Test cases
    s = "5 apples and 6 oranges";
    n = 19;
    if (fruit_distribution(s, n) != 8) {
        cout << "Test case 1 failed" << endl;
        return 1;
    }

    s = "5 apples and 6 oranges";
    n = 21;
    if (fruit_distribution(s, n) != 10) {
        cout << "Test case 2 failed" << endl;
        return 1;
    }

    s = "0 apples and 1 oranges";
    n = 3;
    if (fruit_distribution(s, n) != 2) {
        cout << "Test case 3 failed" << endl;
        return 1;
    }

    s = "1 apples and 0 oranges";
    n = 3;
    if (fruit_distribution(s, n) != 2) {
        cout << "Test case 4 failed" << endl;
        return 1;
    }

    s = "2 apples and 3 oranges";
    n = 100;
    if (fruit_distribution(s, n) != 95) {
        cout << "Test case 5 failed" << endl;
        return 1;
    }

    s = "2 apples and 3 oranges";
    n = 5;
    if (fruit_distribution(s, n) != 0) {
        cout << "Test case 6 failed" << endl;
        return 1;
    }

    s = "1 apples and 100 oranges";
    n = 120;
    if (fruit_distribution(s, n) != 19) {
        cout << "Test case 7 failed" << endl;
        return 1;
    }

    cout << "All test cases passed" << endl;
    return 0;
}
```

### 2.2.2. ìê³ ë¦¬ì¦ ë¶ì

#### 2.2.2.1. ìê° ë³µì¡ë

- ìë ¥ í¬ê¸°: `n`
- ìê° ë³µì¡ë: `O(n)`

#### 2.2.2.2. ê³µê° ë³µì¡ë

- ìë ¥ í¬ê¸°: `n`
- ê³µê° ë³µì¡ë: `O(n)`

### 2.2.3. íë¡ê·¸ëë° í

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `string::length()`, `string::substr()`, `string::find()`
- ë¬¸ìì´ ë³í í¨ì: `stringstream::strtoi()`

## 2.3. íì´ ë³ íë¡ê·¸ëë° í

### 2.3.1. C++

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `string::length()`, `string::substr()`, `string::find()`
- ë¬¸ìì´ ë³í í¨ì: `stringstream::strtoi()`

### 2.3.2. C

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `strlen()`, `strncpy()`, `strstr()`
- ë¬¸ìì´ ë³í í¨ì: `atoi()`

### 2.3.3. Java

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `String.length()`, `String.substring()`, `String.indexOf()`
- ë¬¸ìì´ ë³í í¨ì: `Integer.parseInt()`

### 2.3.4. Python

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `len()`, `str[:]`, `str.index()`
- ë¬¸ìì´ ë³í í¨ì: `int()`

### 2.3.5. Go

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `len()`, `string[:]`, `strings.Index()`
- ë¬¸ìì´ ë³í í¨ì: `strconv.Atoi()`

### 2.3.6. JavaScript

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `String.length`, `String.substr()`, `String.indexOf()`
- ë¬¸ìì´ ë³í í¨ì: `parseInt()`

### 2.3.7. Ruby

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `String#length`, `String#[]`, `String#index()`
- ë¬¸ìì´ ë³í í¨ì: `Integer()`

### 2.3.8. PHP

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `strlen()`, `substr()`, `strstr()`
- ë¬¸ìì´ ë³í í¨ì: `intval()`

### 2.3.9. Swift

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `String.count`, `String.prefix()`, `String.firstIndex()`
- ë¬¸ìì´ ë³í í¨ì: `Int()`

### 2.3.10. Rust

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `String.len()`, `String.get()`, `String.find()`
- ë¬¸ìì´ ë³í í¨ì: `str::parse()`

### 2.3.11. Kotlin

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `String.length`, `String.substring()`, `String.indexOf()`
- ë¬¸ìì´ ë³í í¨ì: `Integer.parseInt()`

### 2.3.12. C#

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `String.Length`, `String.Substring()`, `String.IndexOf()`
- ë¬¸ìì´ ë³í í¨ì: `int.Parse()`

### 2.3.13. Visual Basic

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `Len()`, `Mid()`, `InStr()`
- ë¬¸ìì´ ë³í í¨ì: `CInt()`

### 2.3.14. Perl

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `length()`, `substr()`, `index()`
- ë¬¸ìì´ ë³í í¨ì: `int()`

### 2.3.15. Lua

- ë¬¸ìì´ ì²ë¦¬ í¨ì: `string.len()`, `string
