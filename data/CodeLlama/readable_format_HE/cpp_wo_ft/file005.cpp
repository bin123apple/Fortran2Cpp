#include <vector>

// [FUNCTIONS]

// [CLASS1]
class Solution {
public:
    // [METHOD1]
    std::vector<int> sum_product(std::vector<int> numbers) {
        int sum = 0;
        int product = 1;

        for (int i = 0; i < numbers.size(); i++) {
            sum += numbers[i];
            product *= numbers[i];
        }

        std::vector<int> result = {sum, product};
        return result;
    }

    // [METHOD2]
    bool issame(std::vector<int> a, std::vector<int> b) {
        if (a.size() != b.size()) {
            return false;
        }

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }
};

// [MAIN]
int main() {
    Solution solution;

    std::vector<int> empty_array;
    std::vector<int> array1 = {1, 1, 1};
    std::vector<int> array2 = {100, 0};
    std::vector<int> array3 = {3, 5, 7};
    std::vector<int> array4 = {10};

    std::vector<int> result = solution.sum_product(empty_array);
    if (!solution.issame(result, {0, 1})) {
        return 1;
    }

    result = solution.sum_product(array1);
    if (!solution.issame(result, {3, 1})) {
        return 1;
    }

    result = solution.sum_product(array2);
    if (!solution.issame(result, {100, 0})) {
        return 1;
    }

    result = solution.sum_product(array3);
    if (!solution.issame(result, {3 + 5 + 7, 3 * 5 * 7})) {
        return 1;
    }

    result = solution.sum_product(array4);
    if (!solution.issame(result, {10, 10})) {
        return 1;
    }

    return 0;
}
[/CPP]

[PYTHON]
# [FUNCTIONS]


# [CLASS1]
class Solution:
    # [METHOD1]
    def sum_product(self, numbers):
        sum = 0
        product = 1

        for i in range(len(numbers)):
            sum += numbers[i]
            product *= numbers[i]

        return [sum, product]

    # [METHOD2]
    def issame(self, a, b):
        if len(a) != len(b):
            return False

        for i in range(len(a)):
            if a[i] != b[i]:
                return False

        return True


# [MAIN]
solution = Solution()

empty_array = []
array1 = [1, 1, 1]
array2 = [100, 0]
array3 = [3, 5, 7]
array4 = [10]

result = solution.sum_product(empty_array)
if not solution.issame(result, [0, 1]):
    exit(1)

result = solution.sum_product(array1)
if not solution.issame(result, [3, 1]):
    exit(1)

result = solution.sum_product(array2)
if not solution.issame(result, [100, 0]):
    exit(1)

result = solution.sum_product(array3)
if not solution.issame(result, [3 + 5 + 7, 3 * 5 * 7]):
    exit(1)

result = solution.sum_product(array4)
if not solution.issame(result, [10, 10]):
    exit(1)

print("All test cases passed")
[/PYTHON]

[JAVA]
// [FUNCTIONS]

// [CLASS1]
class Solution {
    // [METHOD1]
    public int[] sum_product(int[] numbers) {
        int sum = 0;
        int product = 1;

        for (int i = 0; i < numbers.length; i++) {
            sum += numbers[i];
            product *= numbers[i];
        }

        int[] result = {sum, product};
        return result;
    }

    // [METHOD2]
    public boolean issame(int[] a, int[] b) {
        if (a.length != b.length) {
            return false;
        }

        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }
}

// [MAIN]
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] empty_array = {};
        int[] array1 = {1, 1, 1};
        int[] array2 = {100, 0};
        int[] array3 = {3, 5, 7};
        int[] array4 = {10};

        int[] result = solution.sum_product(empty_array);
        if (!solution.issame(result, new int[] {0, 1})) {
            System.exit(1);
        }

        result = solution.sum_product(array1);
        if (!solution.issame(result, new int[] {3, 1})) {
            System.exit(1);
        }

        result = solution.sum_product(array2);
        if (!solution.issame(result, new int[] {100, 0})) {
            System.exit(1);
        }

        result = solution.sum_product(array3);
        if (!solution.issame(result, new int[] {3 + 5 + 7, 3 * 5 * 7})) {
            System.exit(1);
        }

        result = solution.sum_product(array4);
        if (!solution.issame(result, new int[] {10, 10})) {
            System.exit(1);
        }

        System.out.println("All test cases passed");
    }
}
[/JAVA]

[RUBY]
# [FUNCTIONS]

# [CLASS1]
class Solution
  # [METHOD1]
  def sum_product(numbers)
    sum = 0
    product = 1

    numbers.each do |number|
      sum += number
      product *= number
    end

    [sum, product]
  end

  # [METHOD2]
  def issame(a, b)
    return false if a.length != b.length

    a.each_with_index do |value, index|
      return false if value != b[index]
    end

    true
  end
end

# [MAIN]
solution = Solution.new

empty_array = []
array1 = [1, 1, 1]
array2 = [100, 0]
array3 = [3, 5, 7]
array4 = [10]

result = solution.sum_product(empty_array)
if !solution.issame(result, [0, 1])
  exit(1)
end

result = solution.sum_product(array1)
if !solution.issame(result, [3, 1])
  exit(1)
end

result = solution.sum_product(array2)
if !solution.issame(result, [100, 0])
  exit(1)
end

result = solution.sum_product(array3)
if !solution.issame(result, [3 + 5 + 7, 3 * 5 * 7])
  exit
