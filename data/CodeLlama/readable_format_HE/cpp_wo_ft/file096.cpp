#include <iostream>
#include <vector>

int solutions(std::vector<int> lst) {
    int sum = 0;
    for (int i = 0; i < lst.size(); i += 2) {
        if (lst[i] % 2 == 1) {
            sum += lst[i];
        }
    }
    return sum;
}

int main() {
    std::vector<int> test_cases[] = {
        {5, 8, 7, 1},
        {3, 3, 3, 3, 3},
        {30, 13, 24, 321},
        {5, 9},
        {2, 4, 8},
        {30, 13, 23, 32},
        {3, 13, 2, 9}
    };
    int results[] = {12, 9, 0, 5, 0, 23, 3};
    for (int i = 0; i < 7; i++) {
        if (solutions(test_cases[i]) != results[i]) {
            std::cout << "Assertion failed: solutions(";
            for (int j = 0; j < test_cases[i].size(); j++) {
                std::cout << test_cases[i][j];
                if (j < test_cases[i].size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << ") == " << results[i] << std::endl;
            return 1;
        }
    }
    std::cout << "All tests passed." << std::endl;
    return 0;
}


[C]
#include <stdio.h>
#include <stdlib.h>

int solutions(int *lst, int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        if (lst[i] % 2 == 1) {
            sum += lst[i];
        }
    }
    return sum;
}

int main() {
    int test_cases[][4] = {
        {5, 8, 7, 1},
        {3, 3, 3, 3, 3},
        {30, 13, 24, 321},
        {5, 9},
        {2, 4, 8},
        {30, 13, 23, 32},
        {3, 13, 2, 9}
    };
    int results[] = {12, 9, 0, 5, 0, 23, 3};
    for (int i = 0; i < 7; i++) {
        if (solutions(test_cases[i], 4) != results[i]) {
            printf("Assertion failed: solutions(");
            for (int j = 0; j < 4; j++) {
                printf("%d", test_cases[i][j]);
                if (j < 3) {
                    printf(", ");
                }
            }
            printf(") == %d
", results[i]);
            return 1;
        }
    }
    printf("All tests passed.
");
    return 0;
}


[Python]
def solutions(lst):
    sum = 0
    for i in range(0, len(lst), 2):
        if lst[i] % 2 == 1:
            sum += lst[i]
    return sum


if __name__ == '__main__':
    test_cases = [
        [5, 8, 7, 1],
        [3, 3, 3, 3, 3],
        [30, 13, 24, 321],
        [5, 9],
        [2, 4, 8],
        [30, 13, 23, 32],
        [3, 13, 2, 9]
    ]
    results = [12, 9, 0, 5, 0, 23, 3]
    for i in range(0, 7):
        if solutions(test_cases[i]) != results[i]:
            print("Assertion failed: solutions({}) == {}".format(
                test_cases[i], results[i]))
            exit(1)
    print("All tests passed.")


[JavaScript]
function solutions(lst) {
    let sum = 0;
    for (let i = 0; i < lst.length; i += 2) {
        if (lst[i] % 2 == 1) {
            sum += lst[i];
        }
    }
    return sum;
}

function main() {
    let test_cases = [
        [5, 8, 7, 1],
        [3, 3, 3, 3, 3],
        [30, 13, 24, 321],
        [5, 9],
        [2, 4, 8],
        [30, 13, 23, 32],
        [3, 13, 2, 9]
    ];
    let results = [12, 9, 0, 5, 0, 23, 3];
    for (let i = 0; i < 7; i++) {
        if (solutions(test_cases[i]) != results[i]) {
            console.log("Assertion failed: solutions({}) == {}".format(
                test_cases[i], results[i]));
            process.exit(1);
        }
    }
    console.log("All tests passed.");
}

main();


[Ruby]
def solutions(lst)
    sum = 0
    for i in 0...lst.length
        if lst[i] % 2 == 1
            sum += lst[i]
        end
    end
    return sum
end

if __FILE__ == $0
    test_cases = [
        [5, 8, 7, 1],
        [3, 3, 3, 3, 3],
        [30, 13, 24, 321],
        [5, 9],
        [2, 4, 8],
        [30, 13, 23, 32],
        [3, 13, 2, 9]
    ]
    results = [12, 9, 0, 5, 0, 23, 3]
    for i in 0...7
        if solutions(test_cases[i]) != results[i]
            puts "Assertion failed: solutions({}) == {}".format(
                test_cases[i], results[i])
            exit(1)
        end
    end
    puts "All tests passed."
end


[PHP]
function solutions($lst) {
    $sum = 0;
    for ($i = 0; $i < count($lst); $i += 2) {
        if ($lst[$i] % 2 == 1) {
            $sum += $lst[$i];
        }
    }
    return $sum;
}

if ($argc != 1) {
    echo "Usage: php solution.php
";
    exit(1);
}

$test_cases = [
    [5, 8, 7, 1],
    [3, 3, 3, 3, 3],
    [30, 13, 24, 321],
    [5, 9],
    [2, 4, 8],
    [30, 13, 23, 32],
    [3, 13, 2, 9]
];
$results = [12, 9, 0, 5, 0, 23, 3];
for ($i = 0; $i < 7; $i++) {
    if (solutions($test_cases[$i]) != $results[$i]) {
        echo "Assertion failed: solutions({$test_cases[$i]}) == {$results[$i]}
";
