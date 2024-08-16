Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the same functionality as the Fortran code, including the `count_distinct_characters` function and the `to_lower` function.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cctype> // For std::tolower

// Function to count distinct characters in a string
int count_distinct_characters(const std::string& str) {
    std::string lower_str = to_lower(str);
    std::vector<char> distinct;
    int count = 0;

    for (char c : lower_str) {
        if (std::find(distinct.begin(), distinct.end(), c) == distinct.end()) {
            distinct.push_back(c);
            ++count;
        }
    }

    return count;
}

// Function to convert a string to lowercase
std::string to_lower(const std::string& str) {
    std::string lower_str = str;
    for (char& c : lower_str) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return lower_str;
}

int main() {
    // Test cases
    std::string str;
    int result;

    str = "";
    result = count_distinct_characters(str);
    if (result != 0) {
        std::cerr << "Assertion failed: count_distinct_characters('') == 0" << std::endl;
        return 1;
    }

    str = "abcde";
    result = count_distinct_characters(str);
    if (result != 5) {
        std::cerr << "Assertion failed: count_distinct_characters('abcde') == 5" << std::endl;
        return 1;
    }

    str = "abcdecadeCADE";
    result = count_distinct_characters(str);
    if (result != 5) {
        std::cerr << "Assertion failed: count_distinct_characters('abcdecadeCADE') == 5" << std::endl;
        return 1;
    }

    str = "aaaaAAAAaaaa";
    result = count_distinct_characters(str);
    if (result != 1) {
        std::cerr << "Assertion failed: count_distinct_characters('aaaaAAAAaaaa') == 1" << std::endl;
        return 1;
    }

    str = "Jerry jERRY JeRRRY";
    result = count_distinct_characters(str);
    if (result != 5) {
        std::cerr << "Assertion failed: count_distinct_characters('Jerry jERRY JeRRRY') == 5" << std::endl;
        return 1;
    }

    return 0;
}
```

This C++ code includes the necessary headers and uses `std::vector<char>` for the distinct characters array, which is a more common and flexible approach in C++ for dynamic arrays compared to raw arrays. The `std::tolower` function from `<cctype>` is used to convert characters to lowercase, and `std::find` from `<algorithm>` is used to check if a character is already in the distinct characters vector. This code should compile and run in any standard C++ environment.
