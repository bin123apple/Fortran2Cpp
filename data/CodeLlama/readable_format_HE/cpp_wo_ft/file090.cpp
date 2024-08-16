#include <iostream>
#include <vector>

bool move_one_ball(std::vector<int> &arr) {
  int num = 0;
  if (arr.size() == 0) {
    return true;
  }

  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[i-1]) {
      num++;
    }
  }

  if (arr[0] > arr[arr.size()-1]) {
    num++;
  }

  return num < 2;
}

int main() {
  std::vector<int> arr;
  bool result;

  // Test cases
  arr = {3, 4, 5, 1, 2};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {3, 4, 5, 1, 2}" << std::endl;
    return 1;
  }

  arr = {3, 5, 10, 1, 2};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {3, 5, 10, 1, 2}" << std::endl;
    return 1;
  }

  arr = {4, 3, 1, 2};
  result = move_one_ball(arr);
  if (result) {
    std::cout << "Assertion failed for {4, 3, 1, 2}" << std::endl;
    return 1;
  }

  arr = {3, 5, 4, 1, 2};
  result = move_one_ball(arr);
  if (result) {
    std::cout << "Assertion failed for {3, 5, 4, 1, 2}" << std::endl;
    return 1;
  }

  arr = {};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {}" << std::endl;
    return 1;
  }

  std::cout << "All tests passed." << std::endl;
  return 0;
}
[/SOLUTION]

[SOLUTION]
#include <iostream>
#include <vector>

bool move_one_ball(std::vector<int> &arr) {
  int num = 0;
  if (arr.size() == 0) {
    return true;
  }

  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[i-1]) {
      num++;
    }
  }

  if (arr[0] > arr[arr.size()-1]) {
    num++;
  }

  return num < 2;
}

int main() {
  std::vector<int> arr;
  bool result;

  // Test cases
  arr = {3, 4, 5, 1, 2};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {3, 4, 5, 1, 2}" << std::endl;
    return 1;
  }

  arr = {3, 5, 10, 1, 2};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {3, 5, 10, 1, 2}" << std::endl;
    return 1;
  }

  arr = {4, 3, 1, 2};
  result = move_one_ball(arr);
  if (result) {
    std::cout << "Assertion failed for {4, 3, 1, 2}" << std::endl;
    return 1;
  }

  arr = {3, 5, 4, 1, 2};
  result = move_one_ball(arr);
  if (result) {
    std::cout << "Assertion failed for {3, 5, 4, 1, 2}" << std::endl;
    return 1;
  }

  arr = {};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {}" << std::endl;
    return 1;
  }

  std::cout << "All tests passed." << std::endl;
  return 0;
}
[/SOLUTION]

[SOLUTION]
#include <iostream>
#include <vector>

bool move_one_ball(std::vector<int> &arr) {
  int num = 0;
  if (arr.size() == 0) {
    return true;
  }

  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[i-1]) {
      num++;
    }
  }

  if (arr[0] > arr[arr.size()-1]) {
    num++;
  }

  return num < 2;
}

int main() {
  std::vector<int> arr;
  bool result;

  // Test cases
  arr = {3, 4, 5, 1, 2};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {3, 4, 5, 1, 2}" << std::endl;
    return 1;
  }

  arr = {3, 5, 10, 1, 2};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {3, 5, 10, 1, 2}" << std::endl;
    return 1;
  }

  arr = {4, 3, 1, 2};
  result = move_one_ball(arr);
  if (result) {
    std::cout << "Assertion failed for {4, 3, 1, 2}" << std::endl;
    return 1;
  }

  arr = {3, 5, 4, 1, 2};
  result = move_one_ball(arr);
  if (result) {
    std::cout << "Assertion failed for {3, 5, 4, 1, 2}" << std::endl;
    return 1;
  }

  arr = {};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {}" << std::endl;
    return 1;
  }

  std::cout << "All tests passed." << std::endl;
  return 0;
}
[/SOLUTION]

[SOLUTION]
#include <iostream>
#include <vector>

bool move_one_ball(std::vector<int> &arr) {
  int num = 0;
  if (arr.size() == 0) {
    return true;
  }

  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[i-1]) {
      num++;
    }
  }

  if (arr[0] > arr[arr.size()-1]) {
    num++;
  }

  return num < 2;
}

int main() {
  std::vector<int> arr;
  bool result;

  // Test cases
  arr = {3, 4, 5, 1, 2};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {3, 4, 5, 1, 2}" << std::endl;
    return 1;
  }

  arr = {3, 5, 10, 1, 2};
  result = move_one_ball(arr);
  if (!result) {
    std::cout << "Assertion failed for {3, 5, 10, 1, 2
