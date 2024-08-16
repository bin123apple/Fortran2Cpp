#include <iostream>
#include <vector>

using namespace std;

int can_arrange(vector<int> arr) {
	int n = arr.size();
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= i - 1) {
			max = i - 1;
		}
	}
	return max;
}

int can_arrange_empty() {
	return -1;
}

int main() {
	vector<int> arr1 = {1, 2, 4, 3, 5};
	int result1 = can_arrange(arr1);
	if (result1 != 3) {
		cout << "Assertion failed: can_arrange({1,2,4,3,5}) /= 3" << endl;
		return 1;
	}

	vector<int> arr2 = {1, 2, 4, 5};
	int result2 = can_arrange(arr2);
	if (result2 != -1) {
		cout << "Assertion failed: can_arrange({1,2,4,5}) /= -1" << endl;
		return 1;
	}

	vector<int> arr3 = {1, 4, 2, 5, 6, 7, 8, 9, 10};
	int result3 = can_arrange(arr3);
	if (result3 != 2) {
		cout << "Assertion failed: can_arrange({1,4,2,5,6,7,8,9,10}) /= 2" << endl;
		return 1;
	}

	vector<int> arr4 = {4, 8, 5, 7, 3};
	int result4 = can_arrange(arr4);
	if (result4 != 4) {
		cout << "Assertion failed: can_arrange({4,8,5,7,3}) /= 4" << endl;
		return 1;
	}

	vector<int> arr5;
	int result5 = can_arrange_empty();
	if (result5 != -1) {
		cout << "Assertion failed: can_arrange({}) /= -1" << endl;
		return 1;
	}

	cout << "All tests passed." << endl;
	return 0;
}
[/SOLUTION]

[CHALLENGE]
Write a function that takes a list of numbers and returns the maximum number that can be placed at the beginning of the list so that the remaining numbers can be arranged in a strictly increasing order.

For example, given the list [1, 2, 4, 3, 5], you should return 3, since 3 is the maximum number that can be placed at the beginning of the list so that the remaining numbers can be arranged in a strictly increasing order. Given the list [4, 8, 5, 7, 3], you should return 4, since 4 is the maximum number that can be placed at the beginning of the list so that the remaining numbers can be arranged in a strictly increasing order.

If the list is empty, return -1.

[/CHALLENGE]

[META]
entity;
[/META]

[DESCRIPTION]
[/DESCRIPTION]

[TAGS]
fortran, cpp, cpp14, cpp17, c, c89, c99, c11, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y, c++1z, c++14, c++17, c++11, c++1y
