#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

float max_element(vector<float> arr) {
  float max_val = -10000.0;
  for (int i = 0; i < arr.size(); i++) {
    if (max_val < arr[i]) max_val = arr[i];
  }
  return max_val;
}

int main() {
  vector<float> arr;

  // Test case 1
  arr.clear();
  arr.push_back(1.0);
  arr.push_back(2.0);
  arr.push_back(3.0);
  float result = max_element(arr);
  if (abs(result - 3.0) > 1e-4) {
    cout << "Test case 1: assertion failed" << endl;
    exit(1);
  }

  // Test case 2
  arr.clear();
  arr.push_back(5.0);
  arr.push_back(3.0);
  arr.push_back(-5.0);
  arr.push_back(2.0);
  arr.push_back(-3.0);
  arr.push_back(3.0);
  arr.push_back(9.0);
  arr.push_back(0.0);
  arr.push_back(124.0);
  arr.push_back(1.0);
  arr.push_back(-10.0);
  result = max_element(arr);
  if (abs(result - 124.0) > 1e-4) {
    cout << "Test case 2: assertion failed" << endl;
    exit(1);
  }

  cout << "All tests passed" << endl;
  return 0;
} [/CPP]

[C]
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float max_element(float *arr, int size) {
  float max_val = -10000.0;
  for (int i = 0; i < size; i++) {
    if (max_val < arr[i]) max_val = arr[i];
  }
  return max_val;
}

int main() {
  float arr[] = {1.0, 2.0, 3.0};
  float result = max_element(arr, 3);
  if (fabs(result - 3.0) > 1e-4) {
    printf("Test case 1: assertion failed
");
    exit(1);
  }

  float arr2[] = {5.0, 3.0, -5.0, 2.0, -3.0, 3.0, 9.0, 0.0, 124.0, 1.0, -10.0};
  result = max_element(arr2, 11);
  if (fabs(result - 124.0) > 1e-4) {
    printf("Test case 2: assertion failed
");
    exit(1);
  }

  printf("All tests passed
");
  return 0;
} [/C]

[C++]
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

float max_element(vector<float> arr) {
  float max_val = -10000.0;
  for (int i = 0; i < arr.size(); i++) {
    if (max_val < arr[i]) max_val = arr[i];
  }
  return max_val;
}

int main() {
  vector<float> arr;

  // Test case 1
  arr.clear();
  arr.push_back(1.0);
  arr.push_back(2.0);
  arr.push_back(3.0);
  float result = max_element(arr);
  if (abs(result - 3.0) > 1e-4) {
    cout << "Test case 1: assertion failed" << endl;
    exit(1);
  }

  // Test case 2
  arr.clear();
  arr.push_back(5.0);
  arr.push_back(3.0);
  arr.push_back(-5.0);
  arr.push_back(2.0);
  arr.push_back(-3.0);
  arr.push_back(3.0);
  arr.push_back(9.0);
  arr.push_back(0.0);
  arr.push_back(124.0);
  arr.push_back(1.0);
  arr.push_back(-10.0);
  result = max_element(arr);
  if (abs(result - 124.0) > 1e-4) {
    cout << "Test case 2: assertion failed" << endl;
    exit(1);
  }

  cout << "All tests passed" << endl;
  return 0;
} [/C++]

[Python]
def max_element(arr):
  max_val = -10000.0
  for i in range(len(arr)):
    if max_val < arr[i]:
      max_val = arr[i]
  return max_val

if __name__ == "__main__":
  arr = [1.0, 2.0, 3.0]
  result = max_element(arr)
  if abs(result - 3.0) > 1e-4:
    print("Test case 1: assertion failed")
    exit(1)

  arr = [5.0, 3.0, -5.0, 2.0, -3.0, 3.0, 9.0, 0.0, 124.0, 1.0, -10.0]
  result = max_element(arr)
  if abs(result - 124.0) > 1e-4:
    print("Test case 2: assertion failed")
    exit(1)

  print("All tests passed")
[/Python]

[Java]
import java.util.Scanner;

class MaxElement {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int size = sc.nextInt();
    float[] arr = new float[size];
    for (int i = 0; i < size; i++) {
      arr[i] = sc.nextFloat();
    }
    float result = maxElement(arr);
    if (Math.abs(result - 3.0) > 1e-4) {
      System.out.println("Test case 1: assertion failed");
      System.exit(1);
    }

    size = sc.nextInt();
    arr = new float[size];
    for (int i = 0; i < size; i++) {
      arr[i] = sc.nextFloat();
    }
    result = maxElement(arr);
    if (Math.abs(result - 124.0) > 1e-4) {
      System.out.println("Test case 2: assertion failed");
      System.exit(1);
    }

    System.out.println("All tests passed");
  }

  public static float maxElement(float[] arr) {
    float max_val = -10000.0;
    for (int i = 0; i < arr.length; i++) {
      if (max_val < arr[i]) max_val = arr[i];
    }
    return max_val;
  }
} [/Java]

[JavaScript]
function maxElement(arr) {
  var max_val = -10000.0;
  for (var i = 0; i < arr.length; i++) {
    if (max_val < arr[i]) max_val = arr[i];
  }
  return max_val;
}

if (typeof process === "undefined") {
  var arr = [1.0, 2.0, 3.0];
  var result = maxElement(arr);
  if (
