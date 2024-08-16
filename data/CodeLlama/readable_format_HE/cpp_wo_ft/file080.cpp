#include <iostream>

int multiply(int a, int b) {
    return (abs(a) % 10) * (abs(b) % 10);
}

int main() {
    int result;

    // Assertions
    result = multiply(148, 412);
    if (result != 16) {
        std::cout << "Assertion failed: multiply(148, 412) == 16" << std::endl;
        return 1;
    }

    result = multiply(19, 28);
    if (result != 72) {
        std::cout << "Assertion failed: multiply(19, 28) == 72" << std::endl;
        return 1;
    }

    result = multiply(2020, 1851);
    if (result != 0) {
        std::cout << "Assertion failed: multiply(2020, 1851) == 0" << std::endl;
        return 1;
    }

    result = multiply(14, -15);
    if (result != 20) {
        std::cout << "Assertion failed: multiply(14, -15) == 20" << std::endl;
        return 1;
    }

    result = multiply(76, 67);
    if (result != 42) {
        std::cout << "Assertion failed: multiply(76, 67) == 42" << std::endl;
        return 1;
    }

    result = multiply(17, 27);
    if (result != 49) {
        std::cout << "Assertion failed: multiply(17, 27) == 49" << std::endl;
        return 1;
    }

    result = multiply(0, 1);
    if (result != 0) {
        std::cout << "Assertion failed: multiply(0, 1) == 0" << std::endl;
        return 1;
    }

    result = multiply(0, 0);
    if (result != 0) {
        std::cout << "Assertion failed: multiply(0, 0) == 0" << std::endl;
        return 1;
    }

    return 0;
}

[C]
#include <stdio.h>
#include <stdlib.h>

int multiply(int a, int b) {
    return (abs(a) % 10) * (abs(b) % 10);
}

int main() {
    int result;

    // Assertions
    result = multiply(148, 412);
    if (result != 16) {
        printf("Assertion failed: multiply(148, 412) == 16
");
        exit(1);
    }

    result = multiply(19, 28);
    if (result != 72) {
        printf("Assertion failed: multiply(19, 28) == 72
");
        exit(1);
    }

    result = multiply(2020, 1851);
    if (result != 0) {
        printf("Assertion failed: multiply(2020, 1851) == 0
");
        exit(1);
    }

    result = multiply(14, -15);
    if (result != 20) {
        printf("Assertion failed: multiply(14, -15) == 20
");
        exit(1);
    }

    result = multiply(76, 67);
    if (result != 42) {
        printf("Assertion failed: multiply(76, 67) == 42
");
        exit(1);
    }

    result = multiply(17, 27);
    if (result != 49) {
        printf("Assertion failed: multiply(17, 27) == 49
");
        exit(1);
    }

    result = multiply(0, 1);
    if (result != 0) {
        printf("Assertion failed: multiply(0, 1) == 0
");
        exit(1);
    }

    result = multiply(0, 0);
    if (result != 0) {
        printf("Assertion failed: multiply(0, 0) == 0
");
        exit(1);
    }

    return 0;
}

[Python]
def multiply(a, b):
    return abs(a) % 10 * abs(b) % 10


def main():
    result = multiply(148, 412)
    if result != 16:
        print("Assertion failed: multiply(148, 412) == 16")
        exit(1)

    result = multiply(19, 28)
    if result != 72:
        print("Assertion failed: multiply(19, 28) == 72")
        exit(1)

    result = multiply(2020, 1851)
    if result != 0:
        print("Assertion failed: multiply(2020, 1851) == 0")
        exit(1)

    result = multiply(14, -15)
    if result != 20:
        print("Assertion failed: multiply(14, -15) == 20")
        exit(1)

    result = multiply(76, 67)
    if result != 42:
        print("Assertion failed: multiply(76, 67) == 42")
        exit(1)

    result = multiply(17, 27)
    if result != 49:
        print("Assertion failed: multiply(17, 27) == 49")
        exit(1)

    result = multiply(0, 1)
    if result != 0:
        print("Assertion failed: multiply(0, 1) == 0")
        exit(1)

    result = multiply(0, 0)
    if result != 0:
        print("Assertion failed: multiply(0, 0) == 0")
        exit(1)


if __name__ == "__main__":
    main()

[Java]
public class Main {
    public static void main(String[] args) {
        int result;

        // Assertions
        result = multiply(148, 412);
        if (result != 16) {
            System.out.println("Assertion failed: multiply(148, 412) == 16");
            System.exit(1);
        }

        result = multiply(19, 28);
        if (result != 72) {
            System.out.println("Assertion failed: multiply(19, 28) == 72");
            System.exit(1);
        }

        result = multiply(2020, 1851);
        if (result != 0) {
            System.out.println("Assertion failed: multiply(2020, 1851) == 0");
            System.exit(1);
        }

        result = multiply(14, -15);
        if (result != 20) {
            System.out.println("Assertion failed: multiply(14, -15) == 20");
            System.exit(1);
        }

        result = multiply(76, 67);
        if (result != 42) {
            System.out.println("Assertion failed: multiply(76, 67) == 42");
            System.exit(1);
        }

        result = multiply(17, 27);
        if (result != 49) {
            System.out.println("Assertion failed: multiply(17, 27) == 49");
            System.exit(1);
        }

        result = multiply(0, 1);
        if (result != 0) {
            System.out.println("Assertion failed: multiply(0, 1)
