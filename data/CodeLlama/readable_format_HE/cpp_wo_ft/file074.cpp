#include <iostream>
#include <vector>

int add(std::vector<int> lst) {
    int sum = 0;
    for (int i = 0; i < lst.size() / 2; i++) {
        if (lst[2 * i + 2] % 2 == 0) {
            sum += lst[2 * i + 2];
        }
    }
    return sum;
}

int main() {
    std::vector<int> lst;
    int result;

    // Test cases
    lst = {4, 88};
    result = add(lst);
    if (result != 88) {
        std::cout << "Assertion failed: add([4, 88]) == 88" << std::endl;
        return 1;
    }

    lst = {4, 5, 6, 7, 2, 122};
    result = add(lst);
    if (result != 122) {
        std::cout << "Assertion failed: add([4, 5, 6, 7, 2, 122]) == 122" << std::endl;
        return 1;
    }

    lst = {4, 0, 6, 7};
    result = add(lst);
    if (result != 0) {
        std::cout << "Assertion failed: add([4, 0, 6, 7]) == 0" << std::endl;
        return 1;
    }

    lst = {4, 4, 6, 8};
    result = add(lst);
    if (result != 12) {
        std::cout << "Assertion failed: add([4, 4, 6, 8]) == 12" << std::endl;
        return 1;
    }

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}

[C++]
#include <iostream>
#include <vector>

int add(std::vector<int> lst) {
    int sum = 0;
    for (int i = 0; i < lst.size() / 2; i++) {
        if (lst[2 * i + 2] % 2 == 0) {
            sum += lst[2 * i + 2];
        }
    }
    return sum;
}

int main() {
    std::vector<int> lst;
    int result;

    // Test cases
    lst = {4, 88};
    result = add(lst);
    if (result != 88) {
        std::cout << "Assertion failed: add([4, 88]) == 88" << std::endl;
        return 1;
    }

    lst = {4, 5, 6, 7, 2, 122};
    result = add(lst);
    if (result != 122) {
        std::cout << "Assertion failed: add([4, 5, 6, 7, 2, 122]) == 122" << std::endl;
        return 1;
    }

    lst = {4, 0, 6, 7};
    result = add(lst);
    if (result != 0) {
        std::cout << "Assertion failed: add([4, 0, 6, 7]) == 0" << std::endl;
        return 1;
    }

    lst = {4, 4, 6, 8};
    result = add(lst);
    if (result != 12) {
        std::cout << "Assertion failed: add([4, 4, 6, 8]) == 12" << std::endl;
        return 1;
    }

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}

[C++]
#include <iostream>
#include <vector>

int add(std::vector<int> lst) {
    int sum = 0;
    for (int i = 0; i < lst.size() / 2; i++) {
        if (lst[2 * i + 2] % 2 == 0) {
            sum += lst[2 * i + 2];
        }
    }
    return sum;
}

int main() {
    std::vector<int> lst;
    int result;

    // Test cases
    lst = {4, 88};
    result = add(lst);
    if (result != 88) {
        std::cout << "Assertion failed: add([4, 88]) == 88" << std::endl;
        return 1;
    }

    lst = {4, 5, 6, 7, 2, 122};
    result = add(lst);
    if (result != 122) {
        std::cout << "Assertion failed: add([4, 5, 6, 7, 2, 122]) == 122" << std::endl;
        return 1;
    }

    lst = {4, 0, 6, 7};
    result = add(lst);
    if (result != 0) {
        std::cout << "Assertion failed: add([4, 0, 6, 7]) == 0" << std::endl;
        return 1;
    }

    lst = {4, 4, 6, 8};
    result = add(lst);
    if (result != 12) {
        std::cout << "Assertion failed: add([4, 4, 6, 8]) == 12" << std::endl;
        return 1;
    }

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}

[C++]
#include <iostream>
#include <vector>

int add(std::vector<int> lst) {
    int sum = 0;
    for (int i = 0; i < lst.size() / 2; i++) {
        if (lst[2 * i + 2] % 2 == 0) {
            sum += lst[2 * i + 2];
        }
    }
    return sum;
}

int main() {
    std::vector<int> lst;
    int result;

    // Test cases
    lst = {4, 88};
    result = add(lst);
    if (result != 88) {
        std::cout << "Assertion failed: add([4, 88]) == 88" << std::endl;
        return 1;
    }

    lst = {4, 5, 6, 7, 2, 122};
    result = add(lst);
    if (result != 122) {
        std::cout << "Assertion failed: add([4, 5, 6, 7, 2, 122]) == 122" << std::endl;
        return 1;
    }

    lst = {4, 0, 6, 7};
    result = add(lst);
    if (result != 0) {
        std::cout << "Assertion failed: add([4, 0, 6, 7]) == 0" << std::endl;
        return 1;
    }

    lst = {4, 4, 6, 8};
    result = add(lst);
    if (result != 12) {
        std::cout << "Assertion failed: add([4, 4, 6, 8]) == 12" << std::endl;
        return 1;
    }

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}

[C++]
#include <iostream>
#include <vector>

int add(std::vector<int> lst) {
    int sum = 0;
    for (int i = 0; i < lst.size() / 2; i++) {
        if (lst[2 * i + 2] % 2 == 0) {
            sum += lst[2 * i + 2];
        }
    }
    return sum;
}
