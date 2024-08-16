#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NumTo {
  int key;
  string value;
};

void sort_array(vector<int> &arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

vector<string> by_length(vector<int> &arr) {
  vector<NumTo> numto = {
    {0, "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"}
  };

  sort_array(arr);

  vector<string> out;
  for (int i = arr.size() - 1; i >= 0; i--) {
    if (arr[i] >= 1 && arr[i] <= 9) {
      out.push_back(numto[arr[i] + 1].value);
    }
  }

  return out;
}

bool issame(vector<string> a, vector<string> b) {
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

int main() {
  vector<int> arr = {2, 1, 1, 4, 5, 8, 2, 3};
  vector<string> result = by_length(arr);
  vector<string> expected1 = {"Eight", "Five", "Four", "Three", "Two", "Two", "One", "One"};
  if (!issame(result, expected1)) {
    cout << "Test 1: assertion failed" << endl;
    return 1;
  }

  arr = {};
  result = by_length(arr);
  vector<string> expected2 = {"One"};
  if (!issame(result, expected2)) {
    cout << "Test 2: assertion failed" << endl;
    return 1;
  }

  arr = {1, -1, 55};
  result = by_length(arr);
  if (!issame(result, expected2)) {
    cout << "Test 3: assertion failed" << endl;
    return 1;
  }

  arr = {1, -1, 3, 2};
  result = by_length(arr);
  vector<string> expected3 = {"Three", "Two", "One"};
  if (!issame(result, expected3)) {
    cout << "Test 4: assertion failed" << endl;
    return 1;
  }

  arr = {9, 4, 8};
  result = by_length(arr);
  vector<string> expected4 = {"Nine", "Eight", "Four"};
  if (!issame(result, expected4)) {
    cout << "Test 5: assertion failed" << endl;
    return 1;
  }

  cout << "All tests passed." << endl;
  return 0;
} [/CPP]

[C]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int key;
  char value[10];
} NumTo;

void sort_array(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

char **by_length(int *arr, int n) {
  NumTo numto[] = {
    {0, "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"}
  };

  sort_array(arr, n);

  char **out = malloc(sizeof(char *) * n);
  int count = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] >= 1 && arr[i] <= 9) {
      out[count] = malloc(sizeof(char) * 10);
      strcpy(out[count], numto[arr[i] + 1].value);
      count++;
    }
  }

  return out;
}

int issame(char **a, char **b, int n, int m) {
  if (n != m) {
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (strcmp(a[i], b[i]) != 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int arr[] = {2, 1, 1, 4, 5, 8, 2, 3};
  char **result = by_length(arr, 8);
  char *expected1[] = {"Eight", "Five", "Four", "Three", "Two", "Two", "One", "One"};
  if (!issame(result, expected1, 8, 8)) {
    printf("Test 1: assertion failed
");
    return 1;
  }

  arr = {};
  result = by_length(arr, 0);
  char *expected2[] = {"One"};
  if (!issame(result, expected2, 0, 1)) {
    printf("Test 2: assertion failed
");
    return 1;
  }

  arr = {1, -1, 55};
  result = by_length(arr, 3);
  if (!issame(result, expected2, 3, 1)) {
    printf("Test 3: assertion failed
");
    return 1;
  }

  arr = {1, -1, 3, 2};
  result = by_length(arr, 4);
  char *expected3[] = {"Three", "Two", "One"};
  if (!issame(result, expected3, 4, 3)) {
    printf("Test 4: assertion failed
");
    return 1;
  }

  arr = {9, 4, 8};
  result = by_length(arr, 3);
  char *expected4[] = {"Nine", "Eight", "Four"};
  if (!issame(result, expected4, 3, 3)) {
    printf("Test 5: assertion failed
");
    return 1;
  }

  printf("All tests passed.
");
  return 0;
} [/C]

[JAVA]
import java.util.Arrays;

class NumTo {
  int key;
  String value;

  public NumTo(int key, String value) {
    this.key = key;
    this.value = value;
  }
}

class Utils {
  public static void sortArray(int[] arr) {
    for (int i = 0; i < arr.length - 1; i++) {
      for (int j = i + 1; j < arr.length; j++) {
        if (arr[i] > arr[j]) {
          int temp = arr[i];
