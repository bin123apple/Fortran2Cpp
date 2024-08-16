#include <iostream>
#include <vector>

using namespace std;

void intersperse(vector<int> &numbers, int delimeter, vector<int> &result) {
    int n = numbers.size();
    if (n == 0) {
        result.clear();
        return;
    }

    result.resize(2 * n - 1);
    result[0] = numbers[0];
    for (int i = 1; i < n; i++) {
        result[2 * i - 1] = delimeter;
        result[2 * i] = numbers[i];
    }
}

int main() {
    vector<int> numbers;
    vector<int> result;
    vector<int> expected;

    // Test case 1
    numbers.clear();
    numbers.push_back(0);
    expected.clear();
    intersperse(numbers, 7, result);
    assert(result == expected);

    // Test case 2
    numbers.clear();
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(3);
    numbers.push_back(2);
    expected.clear();
    expected.push_back(5);
    expected.push_back(8);
    expected.push_back(6);
    expected.push_back(8);
    expected.push_back(3);
    expected.push_back(8);
    expected.push_back(2);
    intersperse(numbers, 8, result);
    assert(result == expected);

    // Test case 3
    numbers.clear();
    numbers.push_back(2);
    numbers.push_back(2);
    numbers.push_back(2);
    expected.clear();
    expected.push_back(2);
    expected.push_back(2);
    expected.push_back(2);
    expected.push_back(2);
    expected.push_back(2);
    intersperse(numbers, 2, result);
    assert(result == expected);

    return 0;
}

[C]
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void intersperse(int *numbers, int n, int delimeter, int *result) {
    if (n == 0) {
        result[0] = 0;
        return;
    }

    int *p = result;
    *p++ = numbers[0];
    for (int i = 1; i < n; i++) {
        *p++ = delimeter;
        *p++ = numbers[i];
    }
}

void assert_array_equal(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        assert(a[i] == b[i]);
    }
}

int main() {
    int numbers[] = {5, 6, 3, 2};
    int expected[] = {5, 8, 6, 8, 3, 8, 2};
    int result[MAX(sizeof(numbers), sizeof(expected))];

    intersperse(numbers, sizeof(numbers) / sizeof(numbers[0]), 8, result);
    assert_array_equal(result, expected, sizeof(expected) / sizeof(expected[0]));

    numbers[0] = 2;
    numbers[1] = 2;
    numbers[2] = 2;
    expected[0] = 2;
    expected[1] = 2;
    expected[2] = 2;
    expected[3] = 2;
    expected[4] = 2;
    intersperse(numbers, sizeof(numbers) / sizeof(numbers[0]), 2, result);
    assert_array_equal(result, expected, sizeof(expected) / sizeof(expected[0]));

    return 0;
}

[Python]
def intersperse(numbers, delimeter):
    return [numbers[0]] + [delimeter] * (len(numbers) - 1) + numbers[1:]

def test_intersperse():
    assert intersperse([], 7) == []
    assert intersperse([5], 8) == [5]
    assert intersperse([5, 6, 3, 2], 8) == [5, 8, 6, 8, 3, 8, 2]
    assert intersperse([2, 2, 2], 2) == [2, 2, 2, 2, 2]

if __name__ == '__main__':
    test_intersperse()

[JavaScript]
function intersperse(numbers, delimeter) {
    return [numbers[0]]
        .concat(Array(numbers.length - 1).fill(delimeter))
        .concat(numbers.slice(1));
}

function test_intersperse() {
    assert.deepEqual(intersperse([], 7), []);
    assert.deepEqual(intersperse([5], 8), [5]);
    assert.deepEqual(intersperse([5, 6, 3, 2], 8), [5, 8, 6, 8, 3, 8, 2]);
    assert.deepEqual(intersperse([2, 2, 2], 2), [2, 2, 2, 2, 2]);
}

if (typeof module !== 'undefined' && module.exports) {
    assert = require('assert');
    test_intersperse();
}

[PHP]
function intersperse(array $numbers, $delimeter) {
    return array_merge(
        [$numbers[0]],
        array_fill(0, count($numbers) - 1, $delimeter),
        array_slice($numbers, 1)
    );
}

function test_intersperse() {
    assert(intersperse([], 7) == []);
    assert(intersperse([5], 8) == [5]);
    assert(intersperse([5, 6, 3, 2], 8) == [5, 8, 6, 8, 3, 8, 2]);
    assert(intersperse([2, 2, 2], 2) == [2, 2, 2, 2, 2]);
}

if (isset($argv)) {
    test_intersperse();
}

[Ruby]
def intersperse(numbers, delimeter)
    result = [numbers[0]]
    (numbers.length - 1).times do |i|
        result << delimeter
    end
    result.concat(numbers[1..-1])
end

def test_intersperse()
    assert_equal(intersperse([], 7), [])
    assert_equal(intersperse([5], 8), [5])
    assert_equal(intersperse([5, 6, 3, 2], 8), [5, 8, 6, 8, 3, 8, 2])
    assert_equal(intersperse([2, 2, 2], 2), [2, 2, 2, 2, 2])
end

if __FILE__ == $0
    test_intersperse()
end

[Swift]
func intersperse(numbers: [Int], delimeter: Int) -> [Int] {
    var result = [Int]()
    result.append(numbers[0])
    for i in 1..<numbers.count {
        result.append(delimeter)
        result.append(numbers[i])
    }
    return result
}

func test_intersperse() {
    assert(intersperse([], 7) == [])
    assert(intersperse([5], 8) == [5])
    assert(intersperse([5, 6, 3, 2], 8) == [5, 8, 6, 8,
