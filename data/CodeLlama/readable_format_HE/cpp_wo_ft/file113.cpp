#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int sum_digits(int n) {
    string s = to_string(abs(n));
    int sum = 0;
    for (int i = 1; i < s.length(); i++) {
        sum += s[i] - '0';
    }
    if (n > 0) {
        sum += s[0] - '0';
    } else {
        sum -= s[0] - '0';
    }
    return sum;
}

vector<int> order_by_points(vector<int> nums) {
    vector<int> sumdigit(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        sumdigit[i] = sum_digits(nums[i]);
    }
    sort(sumdigit.begin(), sumdigit.end());
    sort(nums.begin(), nums.end(), [&](int a, int b) {
        return sumdigit[a] < sumdigit[b];
    });
    return nums;
}

int main() {
    vector<int> nums = {1, 11, -1, -11, -12};
    vector<int> result = order_by_points(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    nums = {1234, 423, 463, 145, 2, 423, 423, 53, 6, 37, 3457, 3, 56, 0, 46};
    result = order_by_points(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    nums = {1, -11, -32, 43, 54, -98, 2, -3};
    result = order_by_points(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    result = order_by_points(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    nums = {0, 6, 6, -76, -21, 23, 4};
    result = order_by_points(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

[Python]
def sum_digits(n):
    s = str(abs(n))
    sum = 0
    for i in range(1, len(s)):
        sum += int(s[i])
    if n > 0:
        sum += int(s[0])
    else:
        sum -= int(s[0])
    return sum

def order_by_points(nums):
    sumdigit = [sum_digits(n) for n in nums]
    sumdigit.sort()
    nums.sort(key=lambda x: sumdigit[x])
    return nums

if __name__ == "__main__":
    nums = [1, 11, -1, -11, -12]
    result = order_by_points(nums)
    print(result)

    nums = [1234, 423, 463, 145, 2, 423, 423, 53, 6, 37, 3457, 3, 56, 0, 46]
    result = order_by_points(nums)
    print(result)

    nums = [1, -11, -32, 43, 54, -98, 2, -3]
    result = order_by_points(nums)
    print(result)

    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
    result = order_by_points(nums)
    print(result)

    nums = [0, 6, 6, -76, -21, 23, 4]
    result = order_by_points(nums)
    print(result)

[Java]
import java.util.Arrays;

class Solution {
    public int sumDigits(int n) {
        String s = Integer.toString(Math.abs(n));
        int sum = 0;
        for (int i = 1; i < s.length(); i++) {
            sum += s.charAt(i) - '0';
        }
        if (n > 0) {
            sum += s.charAt(0) - '0';
        } else {
            sum -= s.charAt(0) - '0';
        }
        return sum;
    }

    public int[] orderByPoints(int[] nums) {
        int[] sumdigit = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            sumdigit[i] = sumDigits(nums[i]);
        }
        Arrays.sort(sumdigit);
        Arrays.sort(nums, (a, b) -> sumdigit[a] - sumdigit[b]);
        return nums;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 11, -1, -11, -12};
        int[] result = new Solution().orderByPoints(nums);
        for (int i : result) {
            System.out.print(i + " ");
        }
        System.out.println();

        nums = new int[]{1234, 423, 463, 145, 2, 423, 423, 53, 6, 37, 3457, 3, 56, 0, 46};
        result = new Solution().orderByPoints(nums);
        for (int i : result) {
            System.out.print(i + " ");
        }
        System.out.println();

        nums = new int[]{1, -11, -32, 43, 54, -98, 2, -3};
        result = new Solution().orderByPoints(nums);
        for (int i : result) {
            System.out.print(i + " ");
        }
        System.out.println();

        nums = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        result = new Solution().orderByPoints(nums);
        for (int i : result) {
            System.out.print(i + " ");
        }
        System.out.println();

        nums = new int[]{0, 6, 6, -76, -21, 23, 4};
        result = new Solution().orderByPoints(nums);
        for (int i : result) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}

[JavaScript]
function sumDigits(n) {
    let s = Math.abs(n).toString();
    let sum = 0;
    for (let i = 1; i < s.length; i++) {
        sum += s[i] - '0';
    }
    if (n > 0) {
        sum +=
