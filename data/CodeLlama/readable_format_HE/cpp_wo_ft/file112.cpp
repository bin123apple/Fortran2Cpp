#include <cstdlib>
#include <iostream>
#include <string>

bool simplify(const std::string& x, const std::string& n) {
    int a, b, c, d;
    size_t pos = x.find('/');
    a = std::stoi(x.substr(0, pos));
    b = std::stoi(x.substr(pos + 1));

    pos = n.find('/');
    c = std::stoi(n.substr(0, pos));
    d = std::stoi(n.substr(pos + 1));

    return (a * c) % (b * d) == 0;
}

int main() {
    bool result;

    result = simplify("1/5", "5/1");
    if (!result) {
        std::cout << "Assertion failed: simplify('1/5', '5/1') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("1/6", "2/1");
    if (result) {
        std::cout << "Assertion failed: simplify('1/6', '2/1') == false" << std::endl;
        std::exit(1);
    }

    result = simplify("5/1", "3/1");
    if (!result) {
        std::cout << "Assertion failed: simplify('5/1', '3/1') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("7/10", "10/2");
    if (result) {
        std::cout << "Assertion failed: simplify('7/10', '10/2') == false" << std::endl;
        std::exit(1);
    }

    result = simplify("2/10", "50/10");
    if (!result) {
        std::cout << "Assertion failed: simplify('2/10', '50/10') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("7/2", "4/2");
    if (!result) {
        std::cout << "Assertion failed: simplify('7/2', '4/2') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("11/6", "6/1");
    if (!result) {
        std::cout << "Assertion failed: simplify('11/6', '6/1') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("2/3", "5/2");
    if (result) {
        std::cout << "Assertion failed: simplify('2/3', '5/2') == false" << std::endl;
        std::exit(1);
    }

    result = simplify("5/2", "3/5");
    if (result) {
        std::cout << "Assertion failed: simplify('5/2', '3/5') == false" << std::endl;
        std::exit(1);
    }

    result = simplify("2/4", "8/4");
    if (!result) {
        std::cout << "Assertion failed: simplify('2/4', '8/4') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("2/4", "4/2");
    if (!result) {
        std::cout << "Assertion failed: simplify('2/4', '4/2') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("1/5", "5/1");
    if (!result) {
        std::cout << "Assertion failed: simplify('1/5', '5/1') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("1/5", "1/5");
    if (result) {
        std::cout << "Assertion failed: simplify('1/5', '1/5') == false" << std::endl;
        std::exit(1);
    }

    std::cout << "All assertions passed." << std::endl;
}
```

### Solution 2

```cpp
#include <cstdlib>
#include <iostream>
#include <string>

bool simplify(const std::string& x, const std::string& n) {
    int a, b, c, d;
    size_t pos = x.find('/');
    a = std::stoi(x.substr(0, pos));
    b = std::stoi(x.substr(pos + 1));

    pos = n.find('/');
    c = std::stoi(n.substr(0, pos));
    d = std::stoi(n.substr(pos + 1));

    return (a * c) % (b * d) == 0;
}

int main() {
    bool result;

    result = simplify("1/5", "5/1");
    if (!result) {
        std::cout << "Assertion failed: simplify('1/5', '5/1') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("1/6", "2/1");
    if (result) {
        std::cout << "Assertion failed: simplify('1/6', '2/1') == false" << std::endl;
        std::exit(1);
    }

    result = simplify("5/1", "3/1");
    if (!result) {
        std::cout << "Assertion failed: simplify('5/1', '3/1') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("7/10", "10/2");
    if (result) {
        std::cout << "Assertion failed: simplify('7/10', '10/2') == false" << std::endl;
        std::exit(1);
    }

    result = simplify("2/10", "50/10");
    if (!result) {
        std::cout << "Assertion failed: simplify('2/10', '50/10') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("7/2", "4/2");
    if (!result) {
        std::cout << "Assertion failed: simplify('7/2', '4/2') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("11/6", "6/1");
    if (!result) {
        std::cout << "Assertion failed: simplify('11/6', '6/1') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("2/3", "5/2");
    if (result) {
        std::cout << "Assertion failed: simplify('2/3', '5/2') == false" << std::endl;
        std::exit(1);
    }

    result = simplify("5/2", "3/5");
    if (result) {
        std::cout << "Assertion failed: simplify('5/2', '3/5') == false" << std::endl;
        std::exit(1);
    }

    result = simplify("2/4", "8/4");
    if (!result) {
        std::cout << "Assertion failed: simplify('2/4', '8/4') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("2/4", "4/2");
    if (!result) {
        std::cout << "Assertion failed: simplify('2/4', '4/2') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("1/5", "5/1");
    if (!result) {
        std::cout << "Assertion failed: simplify('1/5', '5/1') == true" << std::endl;
        std::exit(1);
    }

    result = simplify("1/5", "1/5");
    if (result) {
        std::cout << "
