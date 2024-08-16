#include <iostream>
#include <vector>

using namespace std;

int add_elements(vector<int> arr, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        if (arr[i] >= -99 && arr[i] <= 99) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    // Test cases
    int result = add_elements({1, -2, -3, 41, 57, 76, 87, 88, 99}, 3);
    if (result != -4) {
        cout << "Assertion failed: result != -4" << endl;
        return 1;
    }

    result = add_elements({111, 121, 3, 4000, 5, 6}, 2);
    if (result != 0) {
        cout << "Assertion failed: result != 0" << endl;
        return 1;
    }

    result = add_elements({11, 21, 3, 90, 5, 6, 7, 8, 9}, 4);
    if (result != 125) {
        cout << "Assertion failed: result != 125" << endl;
        return 1;
    }

    result = add_elements({111, 21, 3, 4000, 5, 6, 7, 8, 9}, 4);
    if (result != 24) {
        cout << "Assertion failed: result != 24" << endl;
        return 1;
    }

    result = add_elements({1}, 1);
    if (result != 1) {
        cout << "Assertion failed: result != 1" << endl;
        return 1;
    }

    cout << "All tests passed." << endl;
    return 0;
} [/CPP]

[PY]
def add_elements(arr, k):
    sum = 0
    for i in range(k):
        if arr[i] >= -99 and arr[i] <= 99:
            sum += arr[i]
    return sum


# Test cases
assert add_elements([1, -2, -3, 41, 57, 76, 87, 88, 99], 3) == -4
assert add_elements([111, 121, 3, 4000, 5, 6], 2) == 0
assert add_elements([11, 21, 3, 90, 5, 6, 7, 8, 9], 4) == 125
assert add_elements([111, 21, 3, 4000, 5, 6, 7, 8, 9], 4) == 24
assert add_elements([1], 1) == 1

print("All tests passed.")
[/PY]

[JAVA]
import java.util.Arrays;

class Solution {
    public int addElements(int[] arr, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            if (arr[i] >= -99 && arr[i] <= 99) {
                sum += arr[i];
            }
        }
        return sum;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test cases
        assert solution.addElements(new int[]{1, -2, -3, 41, 57, 76, 87, 88, 99}, 3) == -4;
        assert solution.addElements(new int[]{111, 121, 3, 4000, 5, 6}, 2) == 0;
        assert solution.addElements(new int[]{11, 21, 3, 90, 5, 6, 7, 8, 9}, 4) == 125;
        assert solution.addElements(new int[]{111, 21, 3, 4000, 5, 6, 7, 8, 9}, 4) == 24;
        assert solution.addElements(new int[]{1}, 1) == 1;

        System.out.println("All tests passed.");
    }
} [/JAVA]

[RUBY]
def add_elements(arr, k)
  sum = 0
  for i in 0...k
    sum += arr[i] if arr[i] >= -99 && arr[i] <= 99
  end
  sum
end

# Test cases
assert add_elements([1, -2, -3, 41, 57, 76, 87, 88, 99], 3) == -4
assert add_elements([111, 121, 3, 4000, 5, 6], 2) == 0
assert add_elements([11, 21, 3, 90, 5, 6, 7, 8, 9], 4) == 125
assert add_elements([111, 21, 3, 4000, 5, 6, 7, 8, 9], 4) == 24
assert add_elements([1], 1) == 1

puts "All tests passed."
[/RUBY]

[PHP]
function add_elements($arr, $k) {
    $sum = 0;
    for ($i = 0; $i < $k; $i++) {
        if ($arr[$i] >= -99 && $arr[$i] <= 99) {
            $sum += $arr[$i];
        }
    }
    return $sum;
}

# Test cases
assert(add_elements([1, -2, -3, 41, 57, 76, 87, 88, 99], 3) == -4);
assert(add_elements([111, 121, 3, 4000, 5, 6], 2) == 0);
assert(add_elements([11, 21, 3, 90, 5, 6, 7, 8, 9], 4) == 125);
assert(add_elements([111, 21, 3, 4000, 5, 6, 7, 8, 9], 4) == 24);
assert(add_elements([1], 1) == 1);

echo "All tests passed.";
[/PHP]

[GO]
func add_elements(arr []int, k int) int {
    sum := 0
    for i := 0; i < k; i++ {
        if arr[i] >= -99 && arr[i] <= 99 {
            sum += arr[i]
        }
    }
    return sum
}

// Test cases
assert(add_elements([]int{1, -2, -3, 41, 57, 76, 87, 88, 99}, 3) == -4)
assert(add_elements([]int{111, 121, 3, 4000, 5, 6}, 2) == 0)
assert(add_elements([]int{11, 21, 3, 90, 5, 6, 7, 8, 9}, 4) == 125)
assert(add_elements([]int{111, 21, 3, 4000, 5, 6, 7, 8, 9}, 4) == 24)
assert(add_elements([]int{1}, 1) == 1)

fmt.Println("All tests passed.")
[/GO]

[MATLAB]
function sum = add_elements(arr
