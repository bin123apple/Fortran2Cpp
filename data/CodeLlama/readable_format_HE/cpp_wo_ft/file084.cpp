#include <iostream>

int choose_num(int x, int y) {
    if (y < x) {
        return -1;
    } else if (y == x && x % 2 == 1) {
        return -1;
    } else if (x % 2 == 1) {
        return y - 1;
    } else {
        return y;
    }
}

int main() {
    int result;

    result = choose_num(12, 15);
    if (result != 14) {
        std::cout << "Assertion failed: choose_num(12, 15) == 14" << std::endl;
        return 1;
    }

    result = choose_num(13, 12);
    if (result != -1) {
        std::cout << "Assertion failed: choose_num(13, 12) == -1" << std::endl;
        return 1;
    }

    result = choose_num(33, 12354);
    if (result != 12354) {
        std::cout << "Assertion failed: choose_num(33, 12354) == 12354" << std::endl;
        return 1;
    }

    result = choose_num(5234, 5233);
    if (result != -1) {
        std::cout << "Assertion failed: choose_num(5234, 5233) == -1" << std::endl;
        return 1;
    }

    result = choose_num(6, 29);
    if (result != 28) {
        std::cout << "Assertion failed: choose_num(6, 29) == 28" << std::endl;
        return 1;
    }

    result = choose_num(27, 10);
    if (result != -1) {
        std::cout << "Assertion failed: choose_num(27, 10) == -1" << std::endl;
        return 1;
    }

    result = choose_num(7, 7);
    if (result != -1) {
        std::cout << "Assertion failed: choose_num(7, 7) == -1" << std::endl;
        return 1;
    }

    result = choose_num(546, 546);
    if (result != 546) {
        std::cout << "Assertion failed: choose_num(546, 546) == 546" << std::endl;
        return 1;
    }

    return 0;
}

[C]
#include <stdio.h>

int choose_num(int x, int y) {
    if (y < x) {
        return -1;
    } else if (y == x && x % 2 == 1) {
        return -1;
    } else if (x % 2 == 1) {
        return y - 1;
    } else {
        return y;
    }
}

int main() {
    int result;

    result = choose_num(12, 15);
    if (result != 14) {
        printf("Assertion failed: choose_num(12, 15) == 14
");
        return 1;
    }

    result = choose_num(13, 12);
    if (result != -1) {
        printf("Assertion failed: choose_num(13, 12) == -1
");
        return 1;
    }

    result = choose_num(33, 12354);
    if (result != 12354) {
        printf("Assertion failed: choose_num(33, 12354) == 12354
");
        return 1;
    }

    result = choose_num(5234, 5233);
    if (result != -1) {
        printf("Assertion failed: choose_num(5234, 5233) == -1
");
        return 1;
    }

    result = choose_num(6, 29);
    if (result != 28) {
        printf("Assertion failed: choose_num(6, 29) == 28
");
        return 1;
    }

    result = choose_num(27, 10);
    if (result != -1) {
        printf("Assertion failed: choose_num(27, 10) == -1
");
        return 1;
    }

    result = choose_num(7, 7);
    if (result != -1) {
        printf("Assertion failed: choose_num(7, 7) == -1
");
        return 1;
    }

    result = choose_num(546, 546);
    if (result != 546) {
        printf("Assertion failed: choose_num(546, 546) == 546
");
        return 1;
    }

    return 0;
}

[Python]
def choose_num(x, y):
    if y < x:
        return -1
    elif y == x and x % 2 == 1:
        return -1
    elif x % 2 == 1:
        return y - 1
    else:
        return y


def main():
    result = choose_num(12, 15)
    assert result == 14, "Assertion failed: choose_num(12, 15) == 14"

    result = choose_num(13, 12)
    assert result == -1, "Assertion failed: choose_num(13, 12) == -1"

    result = choose_num(33, 12354)
    assert result == 12354, "Assertion failed: choose_num(33, 12354) == 12354"

    result = choose_num(5234, 5233)
    assert result == -1, "Assertion failed: choose_num(5234, 5233) == -1"

    result = choose_num(6, 29)
    assert result == 28, "Assertion failed: choose_num(6, 29) == 28"

    result = choose_num(27, 10)
    assert result == -1, "Assertion failed: choose_num(27, 10) == -1"

    result = choose_num(7, 7)
    assert result == -1, "Assertion failed: choose_num(7, 7) == -1"

    result = choose_num(546, 546)
    assert result == 546, "Assertion failed: choose_num(546, 546) == 546"


if __name__ == "__main__":
    main()

[JavaScript]
function choose_num(x, y) {
    if (y < x) {
        return -1;
    } else if (y == x && x % 2 == 1) {
        return -1;
    } else if (x % 2 == 1) {
        return y - 1;
    } else {
        return y;
    }
}

function main() {
    let result = choose_num(12, 15);
    if (result != 14) {
        console.log("Assertion failed: choose_num(12, 15) == 14");
        return 1;
    }

    result = choose_num(13, 12);
    if (result != -1) {
        console.log("Assertion failed: choose_num(13, 12) == -1");
        return 1;
    }

    result = choose_num(33, 12354);
    if (result != 12354) {
        console.log
