Translating the provided Fortran code to C++ involves several steps, including handling arrays, strings, and the logic of finding the maximum string based on its unique characters. Here's a C++ version of the code, including unit tests similar to the Fortran program:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

std::string find_max(const std::vector<std::string>& words) {
    std::string max_word = "";
    int maxu = 0;

    for (const auto& word : words) {
        std::string unique;
        for (char c : word) {
            if (unique.find(c) == std::string::npos) {
                unique += c;
            }
        }
        if (unique.length() > maxu || (unique.length() == maxu && word < max_word)) {
            max_word = word;
            maxu = unique.length();
        }
    }
    return max_word;
}

void run_tests() {
    std::vector<std::string> words;
    std::string result;

    // Test 1
    words = {"name   ", "of     ", "string "};
    result = find_max(words);
    if (result != "string") {
        std::cerr << "Test 1 failed: expected 'string', got " << result << std::endl;
        std::exit(1);
    }

    // Test 2
    words = {"name   ", "enam   ", "game   "};
    result = find_max(words);
    if (result != "enam") {
        std::cerr << "Test 2 failed: expected 'enam', got " << result << std::endl;
        std::exit(1);
    }

    // Test 3
    words = {"aaaaaaa", "bb     ", "cc     "};
    result = find_max(words);
    if (result != "aaaaaaa") {
        std::cerr << "Test 3 failed: expected 'aaaaaaa', got " << result << std::endl;
        std::exit(1);
    }

    // Test 4
    words = {"abc    ", "cba    "};
    result = find_max(words);
    if (result != "abc") {
        std::cerr << "Test 4 failed: expected 'abc', got " << result << std::endl;
        std::exit(1);
    }

    // Test 5
    words = {"play    ", "this    ", "game    ", "of      ", "footbott"};
    result = find_max(words);
    if (result != "footbott") {
        std::cerr << "Test 5 failed: expected 'footbott', got " << result << std::endl;
        std::exit(1);
    }

    // Test 6
    words = {"we      ", "are     ", "gonna   ", "rock    "};
    result = find_max(words);
    if (result != "gonna") {
        std::cerr << "Test 6 failed: expected 'gonna', got " << result << std::endl;
        std::exit(1);
    }

    // Test 7
    words = {"we      ", "are     ", "a       ", "mad     ", "nation  "};
    result = find_max(words);
    if (result != "nation") {
        std::cerr << "Test 7 failed: expected 'nation', got " << result << std::endl;
        std::exit(1);
    }

    // Test 8
    words = {"this    ", "is      ", "a       ", "prrk    "};
    result = find_max(words);
    if (result != "this") {
        std::cerr << "Test 8 failed: expected 'this', got " << result << std::endl;
        std::exit(1);
    }

    // Test 9
    words = {"b       "};
    result = find_max(words);
    if (result != "b") {
        std::cerr << "Test 9 failed: expected 'b', got " << result << std::endl;
        std::exit(1);
    }

    // Test 10
    words = {"play    ", "play    ", "play    "};
    result = find_max(words);
    if (result != "play") {
        std::cerr << "Test 10 failed: expected 'play', got " << result << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    run_tests();
    return 0;
}
```

This C++ code includes the `find_max` function, which takes a vector of strings and returns the string with the maximum number of unique characters, based on the original Fortran logic. The `run_tests` function contains several test cases to verify the correctness of the `find_max` function. If any test fails, it prints an error message and exits with a non-zero status. If all tests pass, it prints "All tests passed."
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create unit tests that cover various scenarios. Below are the complete and corrected versions of both the Fortran and C++ code with their respective unit tests.

### Fortran Code with Unit Tests

```fortran
module find_max_module
    implicit none
contains

    function find_max(words) result(max_word)
        implicit none
        character(len=100), dimension(:), intent(in) :: words
        character(len=100) :: max_word
        character(len=100) :: unique, word
        integer :: i, j, maxu, len_words

        max_word = ""
        maxu = 0
        len_words = size(words)

        do i = 1, len_words
            word = words(i)
            unique = ""
            do j = 1, len_trim(word)
                if (index(unique, word(j:j)) == 0) then
                    unique = trim(unique) // word(j:j)
                end if
            end do
            if (len_trim(unique) > maxu .or. (len_trim(unique) == maxu .and. word < max_word)) then
                max_word = word
                maxu = len_trim(unique)
            end if
        end do
    end function find_max

end module find_max_module

program main
    use find_max_module
    implicit none
    character(len=100), dimension(:), allocatable :: words
    character(len=100) :: result

    ! Test 1
    allocate(words(3))
    words = ['name   ', 'of     ', 'string ']
    result = find_max(words)
    if (trim(result) /= 'string') then
        write(*,*) "Test 1 failed: expected 'string', got ", trim(result)
        call exit(1)
    end if
    deallocate(words)

    ! Test 2
    allocate(words(3))
    words = ['name   ', 'enam   ', 'game   ']
    result = find_max(words)
    if (trim(result) /= 'enam') then
        write(*,*) "Test 2 failed: expected 'enam', got ", trim(result)
        call exit(1)
    end if
    deallocate(words)

    ! Test 3
    allocate(words(3))
    words = ['aaaaaaa', 'bb     ', 'cc     ']
    result = find_max(words)
    if (trim(result) /= 'aaaaaaa') then
        write(*,*) "Test 3 failed: expected 'aaaaaaa', got ", trim(result)
        call exit(1)
    end if
    deallocate(words)

    ! Test 4
    allocate(words(2))
    words = ['abc    ', 'cba    ']
    result = find_max(words)
    if (trim(result) /= 'abc') then
        write(*,*) "Test 4 failed: expected 'abc', got ", trim(result)
        call
