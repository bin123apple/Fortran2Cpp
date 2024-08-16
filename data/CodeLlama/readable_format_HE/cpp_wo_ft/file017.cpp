#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector<double> rescale_to_unit(const vector<double> &numbers) {
    double min_val = *min_element(numbers.begin(), numbers.end());
    double max_val = *max_element(numbers.begin(), numbers.end());
    vector<double> rescaled(numbers.size());

    for (size_t i = 0; i < numbers.size(); i++) {
        rescaled[i] = (numbers[i] - min_val) / (max_val - min_val);
    }

    return rescaled;
}

bool issame(const vector<double> &a, const vector<double> &b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); i++) {
        if (abs(a[i] - b[i]) > 1.0e-4) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<double> numbers = {2.0, 49.9};
    vector<double> expected1 = {0.0, 1.0};
    vector<double> result = rescale_to_unit(numbers);
    if (!issame(result, expected1)) {
        cout << "Assertion failed for test case 1" << endl;
        exit(1);
    }

    numbers = {100.0, 49.9};
    vector<double> expected2 = {1.0, 0.0};
    result = rescale_to_unit(numbers);
    if (!issame(result, expected2)) {
        cout << "Assertion failed for test case 2" << endl;
        exit(1);
    }

    numbers = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> expected3 = {0.0, 0.25, 0.5, 0.75, 1.0};
    result = rescale_to_unit(numbers);
    if (!issame(result, expected3)) {
        cout << "Assertion failed for test case 3" << endl;
        exit(1);
    }

    numbers = {2.0, 1.0, 5.0, 3.0, 4.0};
    vector<double> expected4 = {0.25, 0.0, 1.0, 0.5, 0.75};
    result = rescale_to_unit(numbers);
    if (!issame(result, expected4)) {
        cout << "Assertion failed for test case 4" << endl;
        exit(1);
    }

    numbers = {12.0, 11.0, 15.0, 13.0, 14.0};
    vector<double> expected5 = {0.25, 0.0, 1.0, 0.5, 0.75};
    result = rescale_to_unit(numbers);
    if (!issame(result, expected5)) {
        cout << "Assertion failed for test case 5" << endl;
        exit(1);
    }

    cout << "All tests passed successfully" << endl;
    return 0;
}

```

### Python

```python
def rescale_to_unit(numbers):
    min_val = min(numbers)
    max_val = max(numbers)
    rescaled = []

    for number in numbers:
        rescaled.append((number - min_val) / (max_val - min_val))

    return rescaled


def issame(a, b):
    if len(a) != len(b):
        return False

    for i in range(len(a)):
        if abs(a[i] - b[i]) > 1.0e-4:
            return False

    return True


numbers = [2.0, 49.9]
expected1 = [0.0, 1.0]
result = rescale_to_unit(numbers)
if not issame(result, expected1):
    print("Assertion failed for test case 1")
    exit(1)

numbers = [100.0, 49.9]
expected2 = [1.0, 0.0]
result = rescale_to_unit(numbers)
if not issame(result, expected2):
    print("Assertion failed for test case 2")
    exit(1)

numbers = [1.0, 2.0, 3.0, 4.0, 5.0]
expected3 = [0.0, 0.25, 0.5, 0.75, 1.0]
result = rescale_to_unit(numbers)
if not issame(result, expected3):
    print("Assertion failed for test case 3")
    exit(1)

numbers = [2.0, 1.0, 5.0, 3.0, 4.0]
expected4 = [0.25, 0.0, 1.0, 0.5, 0.75]
result = rescale_to_unit(numbers)
if not issame(result, expected4):
    print("Assertion failed for test case 4")
    exit(1)

numbers = [12.0, 11.0, 15.0, 13.0, 14.0]
expected5 = [0.25, 0.0, 1.0, 0.5, 0.75]
result = rescale_to_unit(numbers)
if not issame(result, expected5):
    print("Assertion failed for test case 5")
    exit(1)

print("All tests passed successfully")

```

### Ruby

```ruby
def rescale_to_unit(numbers)
    min_val = numbers.min
    max_val = numbers.max
    rescaled = []

    numbers.each do |number|
        rescaled.push((number - min_val) / (max_val - min_val))
    end

    return rescaled
end

def issame(a, b)
    if a.length != b.length
        return false
    end

    for i in 0...a.length
        if (a[i] - b[i]).abs > 1.0e-4
            return false
        end
    end

    return true
end

numbers = [2.0, 49.9]
expected1 = [0.0, 1.0]
result = rescale_to_unit(numbers)
if !issame(result, expected1)
    puts "Assertion failed for test case 1"
    exit(1)
end

numbers = [100.0, 49.9]
expected2 = [1.0, 0.0]
result = rescale_to_unit(numbers)
if !issame(result, expected2)
    puts "Assertion failed for test case 2"
    exit(1)
end

numbers = [1.0, 2.0, 3.0, 4.0, 5.0]
expected3 = [0.0, 0.25, 0.5, 0.75, 1.0]
result = rescale_to_unit(numbers)
if !issame(result, expected3)
    puts "Assertion failed for test case 3"
    exit(1)
end

numbers = [2.0, 1.0, 5.0, 3.0, 4.0]
expected4 = [0.25, 0.0, 1.0, 0.5, 0.75]
result = rescale_to_unit(numbers)
if !issame(result, expected4)
    puts "Assertion failed for test case 4"
    exit(1)
end

numbers = [12.0,
