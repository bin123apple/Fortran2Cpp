#include <algorithm>
#include <vector>

using namespace std;

int next_smallest(vector<int> lst) {
    if (lst.size() == 0) {
        return -1;
    }

    sort(lst.begin(), lst.end());

    int res = -1;
    for (int i = 1; i < lst.size(); ++i) {
        if (lst[i] != lst[i-1]) {
            res = lst[i];
            break;
        }
    }

    return res;
}

int main() {
    vector<int> lst;
    int result;

    // Test case 1
    lst = {1, 2, 3, 4, 5};
    result = next_smallest(lst);
    if (result != 2) {
        cout << "Test case 1 failed" << endl;
        return 1;
    }

    // Test case 2
    lst = {5, 1, 4, 3, 2};
    result = next_smallest(lst);
    if (result != 2) {
        cout << "Test case 2 failed" << endl;
        return 1;
    }

    // Test case 3
    lst = {};
    result = next_smallest(lst);
    if (result != -1) {
        cout << "Test case 3 failed" << endl;
        return 1;
    }

    // Test case 4
    lst = {1, 1};
    result = next_smallest(lst);
    if (result != -1) {
        cout << "Test case 4 failed" << endl;
        return 1;
    }

    // Test case 5
    lst = {1, 1, 1, 1, 0};
    result = next_smallest(lst);
    if (result != 1) {
        cout << "Test case 5 failed" << endl;
        return 1;
    }

    // Test case 6
    lst = {-35, 34, 12, -45};
    result = next_smallest(lst);
    if (result != -35) {
        cout << "Test case 6 failed" << endl;
        return 1;
    }

    cout << "All test cases passed" << endl;
    return 0;
}

[PY]
def next_smallest(lst):
    if len(lst) == 0:
        return -1

    lst.sort()

    res = -1
    for i in range(1, len(lst)):
        if lst[i] != lst[i-1]:
            res = lst[i]
            break

    return res

def main():
    lst = [1, 2, 3, 4, 5]
    result = next_smallest(lst)
    if result != 2:
        print("Test case 1 failed")
        return 1

    lst = [5, 1, 4, 3, 2]
    result = next_smallest(lst)
    if result != 2:
        print("Test case 2 failed")
        return 1

    lst = []
    result = next_smallest(lst)
    if result != -1:
        print("Test case 3 failed")
        return 1

    lst = [1, 1]
    result = next_smallest(lst)
    if result != -1:
        print("Test case 4 failed")
        return 1

    lst = [1, 1, 1, 1, 0]
    result = next_smallest(lst)
    if result != 1:
        print("Test case 5 failed")
        return 1

    lst = [-35, 34, 12, -45]
    result = next_smallest(lst)
    if result != -35:
        print("Test case 6 failed")
        return 1

    print("All test cases passed")
    return 0

[JAVA]
import java.util.Arrays;

class Solution {
    public static int nextSmallest(int[] lst) {
        if (lst.length == 0) {
            return -1;
        }

        Arrays.sort(lst);

        int res = -1;
        for (int i = 1; i < lst.length; ++i) {
            if (lst[i] != lst[i-1]) {
                res = lst[i];
                break;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] lst = {1, 2, 3, 4, 5};
        int result = nextSmallest(lst);
        if (result != 2) {
            System.out.println("Test case 1 failed");
            System.exit(1);
        }

        lst = new int[] {5, 1, 4, 3, 2};
        result = nextSmallest(lst);
        if (result != 2) {
            System.out.println("Test case 2 failed");
            System.exit(1);
        }

        lst = new int[] {};
        result = nextSmallest(lst);
        if (result != -1) {
            System.out.println("Test case 3 failed");
            System.exit(1);
        }

        lst = new int[] {1, 1};
        result = nextSmallest(lst);
        if (result != -1) {
            System.out.println("Test case 4 failed");
            System.exit(1);
        }

        lst = new int[] {1, 1, 1, 1, 0};
        result = nextSmallest(lst);
        if (result != 1) {
            System.out.println("Test case 5 failed");
            System.exit(1);
        }

        lst = new int[] {-35, 34, 12, -45};
        result = nextSmallest(lst);
        if (result != -35) {
            System.out.println("Test case 6 failed");
            System.exit(1);
        }

        System.out.println("All test cases passed");
    }
}

[RUBY]
def next_smallest(lst)
    if lst.length == 0
        return -1
    end

    lst.sort!

    res = -1
    for i in 1...lst.length
        if lst[i] != lst[i-1]
            res = lst[i]
            break
        end
    end

    return res
end

def main
    lst = [1, 2, 3, 4, 5]
    result = next_smallest(lst)
    if result != 2
        puts "Test case 1 failed"
        exit 1
    end

    lst = [5, 1, 4, 3, 2]
    result = next_smallest(lst)
    if result != 2
        puts "Test case 2 failed"
        exit 1
    end

    lst = []
    result = next_smallest(lst)
    if result != -1
        puts "Test case 3 failed"
        exit 1
    end

    lst = [1, 1]
    result = next_smallest(lst)
    if result != -1
        puts "Test case 4 failed"
        exit 1
    end

    lst = [1, 1, 1, 1, 0]
    result = next_smallest(lst)
    if result != 1
        puts "Test case 5 failed"
        exit 1
    end

    lst = [-35, 34, 12, -45]
    result = next_smallest(lst)
    if result != -35
        puts "Test case 6 failed"
        exit 1
    end

    puts "All test cases passed"
end

[C#]
using System;
using System.Linq;

class Solution {
    public static int NextSmallest(int[] lst) {
        if (lst.Length == 0) {
            return -1;
        }
