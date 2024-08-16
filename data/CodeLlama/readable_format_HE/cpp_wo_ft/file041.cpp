#include <cstdlib>
#include <iostream>

int modp(int n, int p) {
    int modp = 1;
    for (int i = 1; i <= n; i++) {
        modp = (modp * 2) % p;
    }
    return modp;
}

int main() {
    int result;

    result = modp(3, 5);
    if (result != 3) {
        std::cout << "modp(3, 5) == 3: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(1101, 101);
    if (result != 2) {
        std::cout << "modp(1101, 101) == 2: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(0, 101);
    if (result != 1) {
        std::cout << "modp(0, 101) == 1: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(3, 11);
    if (result != 8) {
        std::cout << "modp(3, 11) == 8: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(100, 101);
    if (result != 1) {
        std::cout << "modp(100, 101) == 1: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(30, 5);
    if (result != 4) {
        std::cout << "modp(30, 5) == 4: assertion failed" << std::endl;
        std::exit(1);
    }

    result = modp(31, 5);
    if (result != 3) {
        std::cout << "modp(31, 5) == 3: assertion failed" << std::endl;
        std::exit(1);
    }

    std::cout << "All assertions passed." << std::endl;

    return 0;
}

[C]
#include <stdio.h>
#include <stdlib.h>

int modp(int n, int p) {
    int modp = 1;
    for (int i = 1; i <= n; i++) {
        modp = (modp * 2) % p;
    }
    return modp;
}

int main() {
    int result;

    result = modp(3, 5);
    if (result != 3) {
        printf("modp(3, 5) == 3: assertion failed
");
        exit(1);
    }

    result = modp(1101, 101);
    if (result != 2) {
        printf("modp(1101, 101) == 2: assertion failed
");
        exit(1);
    }

    result = modp(0, 101);
    if (result != 1) {
        printf("modp(0, 101) == 1: assertion failed
");
        exit(1);
    }

    result = modp(3, 11);
    if (result != 8) {
        printf("modp(3, 11) == 8: assertion failed
");
        exit(1);
    }

    result = modp(100, 101);
    if (result != 1) {
        printf("modp(100, 101) == 1: assertion failed
");
        exit(1);
    }

    result = modp(30, 5);
    if (result != 4) {
        printf("modp(30, 5) == 4: assertion failed
");
        exit(1);
    }

    result = modp(31, 5);
    if (result != 3) {
        printf("modp(31, 5) == 3: assertion failed
");
        exit(1);
    }

    printf("All assertions passed.
");

    return 0;
}

[Python]
def modp(n, p):
    modp = 1
    for i in range(1, n + 1):
        modp = (modp * 2) % p
    return modp


if __name__ == "__main__":
    result = modp(3, 5)
    if result != 3:
        print("modp(3, 5) == 3: assertion failed")
        exit(1)

    result = modp(1101, 101)
    if result != 2:
        print("modp(1101, 101) == 2: assertion failed")
        exit(1)

    result = modp(0, 101)
    if result != 1:
        print("modp(0, 101) == 1: assertion failed")
        exit(1)

    result = modp(3, 11)
    if result != 8:
        print("modp(3, 11) == 8: assertion failed")
        exit(1)

    result = modp(100, 101)
    if result != 1:
        print("modp(100, 101) == 1: assertion failed")
        exit(1)

    result = modp(30, 5)
    if result != 4:
        print("modp(30, 5) == 4: assertion failed")
        exit(1)

    result = modp(31, 5)
    if result != 3:
        print("modp(31, 5) == 3: assertion failed")
        exit(1)

    print("All assertions passed.")

[JavaScript]
function modp(n, p) {
    let modp = 1;
    for (let i = 1; i <= n; i++) {
        modp = (modp * 2) % p;
    }
    return modp;
}

if (modp(3, 5) != 3) {
    console.log("modp(3, 5) == 3: assertion failed");
    process.exit(1);
}

if (modp(1101, 101) != 2) {
    console.log("modp(1101, 101) == 2: assertion failed");
    process.exit(1);
}

if (modp(0, 101) != 1) {
    console.log("modp(0, 101) == 1: assertion failed");
    process.exit(1);
}

if (modp(3, 11) != 8) {
    console.log("modp(3, 11) == 8: assertion failed");
    process.exit(1);
}

if (modp(100, 101) != 1) {
    console.log("modp(100, 101) == 1: assertion failed");
    process.exit(1);
}

if (modp(30, 5) != 4) {
    console.log("modp(30, 5) == 4: assertion failed");
    process.exit(1);
}

if (modp(31, 5) != 3) {
    console.log("modp(31, 5) == 3: assertion failed");
    process.exit(1);
}

console.log("All assertions passed.");

[Ruby]
def modp(n, p)
    modp = 1
    for i in 1..n
        modp = (modp * 2) % p
    end
    return modp
end

if modp(3, 5) != 3
    puts "modp(3, 5) == 3
