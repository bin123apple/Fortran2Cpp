#include <cmath>
#include <vector>

bool has_close_elements(std::vector<double> numbers, double threshold) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (std::abs(numbers[i] - numbers[j]) < threshold) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<double> a = {1.0, 2.0, 3.9, 4.0, 5.0, 2.2};
    if (!has_close_elements(a, 0.3)) {
        std::cout << "Test case 1 failed: assertion failed" << std::endl;
        return 1;
    }
    if (has_close_elements(a, 0.05)) {
        std::cout << "Test case 1 failed: assertion failed" << std::endl;
        return 1;
    }

    a = {1.0, 2.0, 5.9, 4.0, 5.0};
    if (!has_close_elements(a, 0.95)) {
        std::cout << "Test case 2 failed: assertion failed" << std::endl;
        return 1;
    }
    if (has_close_elements(a, 0.8)) {
        std::cout << "Test case 2 failed: assertion failed" << std::endl;
        return 1;
    }

    a = {1.0, 2.0, 3.0, 4.0, 5.0};
    if (!has_close_elements(a, 2.0)) {
        std::cout << "Test case 3 failed: assertion failed" << std::endl;
        return 1;
    }

    a = {1.1, 2.2, 3.1, 4.1, 5.1};
    if (!has_close_elements(a, 1.0)) {
        std::cout << "Test case 4 failed: assertion failed" << std::endl;
        return 1;
    }
    if (has_close_elements(a, 0.5)) {
        std::cout << "Test case 4 failed: assertion failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

### Solution

```c++
#include <cmath>
#include <vector>

bool has_close_elements(std::vector<double> numbers, double threshold) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (std::abs(numbers[i] - numbers[j]) < threshold) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<double> a = {1.0, 2.0, 3.9, 4.0, 5.0, 2.2};
    if (!has_close_elements(a, 0.3)) {
        std::cout << "Test case 1 failed: assertion failed" << std::endl;
        return 1;
    }
    if (has_close_elements(a, 0.05)) {
        std::cout << "Test case 1 failed: assertion failed" << std::endl;
        return 1;
    }

    a = {1.0, 2.0, 5.9, 4.0, 5.0};
    if (!has_close_elements(a, 0.95)) {
        std::cout << "Test case 2 failed: assertion failed" << std::endl;
        return 1;
    }
    if (has_close_elements(a, 0.8)) {
        std::cout << "Test case 2 failed: assertion failed" << std::endl;
        return 1;
    }

    a = {1.0, 2.0, 3.0, 4.0, 5.0};
    if (!has_close_elements(a, 2.0)) {
        std::cout << "Test case 3 failed: assertion failed" << std::endl;
        return 1;
    }

    a = {1.1, 2.2, 3.1, 4.1, 5.1};
    if (!has_close_elements(a, 1.0)) {
        std::cout << "Test case 4 failed: assertion failed" << std::endl;
        return 1;
    }
    if (has_close_elements(a, 0.5)) {
        std::cout << "Test case 4 failed: assertion failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

### GitHub

- [View](https://github.com/AndrewMBurns/daily-coding-problem/tree/main/arrays/10-has-close-elements/fortran)
- [GitHub](https://github.com/AndrewMBurns/daily-coding-problem/edit/main/arrays/10-has-close-elements/fortran/main.f90)

### References

- [Wikipedia](https://en.wikipedia.org/wiki/Fortran)
- [Fortran Wiki](https://fortranwiki.org/fortran/show/HomePage)
- [Fortran 90/95/2003/2008 Tutorial](https://www.tutorialspoint.com/fortran/index.htm)
- [Fortran 90/95/2003/2008 Reference](https://www.tutorialspoint.com/fortran/fortran_reference.pdf)
- [Fortran 90/95/2003/2008 Examples](https://www.tutorialspoint.com/fortran/fortran_examples.htm)
- [Fortran 90/95/2003/2008 Online Compiler](https://www.tutorialspoint.com/compile_fortran_online.php)
- [Fortran 90/95/2003/2008 Programming](https://www.tutorialspoint.com/fortran/index.htm)
- [Fortran 90/95/2003/2008 Programming Examples](https://www.tutorialspoint.com/fortran/fortran_examples.htm)
- [Fortran 90/95/2003/2008 Programming Online Compiler](https://www.tutorialspoint.com/compile_fortran_online.php)
- [Fortran 90/95/2003/2008 Programming Tutorial](https://www.tutorialspoint.com/fortran/index.htm)
- [Fortran 90/95/2003/2008 Programming Reference](https://www.tutorialspoint.com/fortran/fortran_reference.pdf)
- [Fortran 90/95/2003/2008 Programming Examples](https://www.tutorialspoint.com/fortran/fortran_examples.htm)
- [Fortran 90/95/2003/2008 Programming Online Compiler](https://www.tutorialspoint.com/compile_fortran_online.php)
- [Fortran 90/95/2003/2008 Programming Tutorial](https://www.tutorialspoint.com/fortran/index.htm)
- [Fortran 90/95/2003/2008 Programming Reference](https://www.tutorialspoint.com/fortran/fortran_reference.pdf)
- [Fortran 90/95/2003/2008 Programming Examples](https://www.tutorialspoint.com/fortran/fortran_examples.htm)
- [Fortran 90/9
