#include <iostream>
#include <vector>

using namespace std;

vector<int> generate_integers(int a, int b)
{
    vector<int> result;
    int temp_a = a;
    int temp_b = b;

    if (temp_b < temp_a) {
        int m = temp_a;
        temp_a = temp_b;
        temp_b = m;
    }

    for (int i = temp_a; i <= temp_b; i++) {
        if (i < 10 && i % 2 == 0) {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    vector<int> result = generate_integers(2, 10);
    vector<int> expected = {2, 4, 6, 8};
    if (result != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    result = generate_integers(10, 2);
    expected = {2, 4, 6, 8};
    if (result != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    result = generate_integers(132, 2);
    expected = {2, 4, 6, 8};
    if (result != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    result = generate_integers(17, 89);
    expected = {};
    if (result != expected) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    return 0;
}

[C]
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_same(int *a, int *b, int size)
{
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

void assert(bool condition)
{
    if (!condition) {
        printf("Assertion failed
");
        exit(1);
    }
}

int *generate_integers(int a, int b, int *size)
{
    int temp_a = a;
    int temp_b = b;

    if (temp_b < temp_a) {
        int m = temp_a;
        temp_a = temp_b;
        temp_b = m;
    }

    int count = 0;
    for (int i = temp_a; i <= temp_b; i++) {
        if (i < 10 && i % 2 == 0) {
            count++;
        }
    }

    int *result = malloc(count * sizeof(int));
    int j = 0;
    for (int i = temp_a; i <= temp_b; i++) {
        if (i < 10 && i % 2 == 0) {
            result[j] = i;
            j++;
        }
    }

    *size = count;
    return result;
}

int main()
{
    int size;
    int *result = generate_integers(2, 10, &size);
    int expected[] = {2, 4, 6, 8};
    assert(is_same(result, expected, 4));
    free(result);

    result = generate_integers(10, 2, &size);
    expected = (int[]){2, 4, 6, 8};
    assert(is_same(result, expected, 4));
    free(result);

    result = generate_integers(132, 2, &size);
    expected = (int[]){2, 4, 6, 8};
    assert(is_same(result, expected, 4));
    free(result);

    result = generate_integers(17, 89, &size);
    expected = (int[]){};
    assert(is_same(result, expected, 0));
    free(result);

    return 0;
}

[Python]
def generate_integers(a, b):
    result = []
    temp_a = a
    temp_b = b

    if temp_b < temp_a:
        m = temp_a
        temp_a = temp_b
        temp_b = m

    for i in range(temp_a, temp_b + 1):
        if i < 10 and i % 2 == 0:
            result.append(i)

    return result

def assert(condition):
    if not condition:
        print("Assertion failed")
        exit(1)

def main():
    result = generate_integers(2, 10)
    expected = [2, 4, 6, 8]
    assert(result == expected)

    result = generate_integers(10, 2)
    expected = [2, 4, 6, 8]
    assert(result == expected)

    result = generate_integers(132, 2)
    expected = [2, 4, 6, 8]
    assert(result == expected)

    result = generate_integers(17, 89)
    expected = []
    assert(result == expected)

if __name__ == "__main__":
    main()

[Rust]
fn generate_integers(a: i32, b: i32) -> Vec<i32> {
    let mut result = Vec::new();
    let mut temp_a = a;
    let mut temp_b = b;

    if temp_b < temp_a {
        let m = temp_a;
        temp_a = temp_b;
        temp_b = m;
    }

    for i in temp_a..=temp_b {
        if i < 10 && i % 2 == 0 {
            result.push(i);
        }
    }

    result
}

fn assert(condition: bool) {
    if !condition {
        println!("Assertion failed");
        std::process::exit(1);
    }
}

fn main() {
    let result = generate_integers(2, 10);
    let expected = vec![2, 4, 6, 8];
    assert(result == expected);

    let result = generate_integers(10, 2);
    let expected = vec![2, 4, 6, 8];
    assert(result == expected);

    let result = generate_integers(132, 2);
    let expected = vec![2, 4, 6, 8];
    assert(result == expected);

    let result = generate_integers(17, 89);
    let expected = vec![];
    assert(result == expected);
}

[Swift]
func generate_integers(_ a: Int, _ b: Int) -> [Int] {
    var result = [Int]()
    var temp_a = a
    var temp_b = b

    if temp_b < temp_a {
        let m = temp_a
        temp_a = temp_b
        temp_b = m
    }

    for i in temp_a...temp_b {
        if i < 10 && i % 2 == 0 {
            result.append(i)
        }
    }

    return result
}

func assert(_ condition: Bool) {
    if !condition {
        print("Assertion failed")
        exit(1)
    }
}

func main() {
    let result = generate_integers(2, 10)
    let expected = [2, 4, 6, 8]
    assert(result == expected)

    let result = generate_integers(10, 2)
    let expected = [2, 4, 6, 8]
    assert(result == expected)

    let result = generate_integers(132, 2)
    let expected = [2, 4, 6,
