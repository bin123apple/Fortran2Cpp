#include <iostream>
#include <vector>

using namespace std;

vector<int> eat(int number, int need, int remaining) {
  vector<int> res;

  if (need > remaining) {
    res.push_back(number + remaining);
    res.push_back(0);
  } else {
    res.push_back(number + need);
    res.push_back(remaining - need);
  }

  return res;
}

int main() {
  vector<int> result;
  vector<int> expected;

  // Test cases
  result = eat(5, 6, 10);
  expected = {11, 4};
  if (result != expected) {
    cout << "Assertion failed: eat(5, 6, 10) == {11, 4}" << endl;
    return 1;
  }

  result = eat(4, 8, 9);
  expected = {12, 1};
  if (result != expected) {
    cout << "Assertion failed: eat(4, 8, 9) == {12, 1}" << endl;
    return 1;
  }

  result = eat(1, 10, 10);
  expected = {11, 0};
  if (result != expected) {
    cout << "Assertion failed: eat(1, 10, 10) == {11, 0}" << endl;
    return 1;
  }

  result = eat(2, 11, 5);
  expected = {7, 0};
  if (result != expected) {
    cout << "Assertion failed: eat(2, 11, 5) == {7, 0}" << endl;
    return 1;
  }

  result = eat(4, 5, 7);
  expected = {9, 2};
  if (result != expected) {
    cout << "Assertion failed: eat(4, 5, 7) == {9, 2}" << endl;
    return 1;
  }

  result = eat(4, 5, 1);
  expected = {5, 0};
  if (result != expected) {
    cout << "Assertion failed: eat(4, 5, 1) == {5, 0}" << endl;
    return 1;
  }

  cout << "All tests passed." << endl;

  return 0;
}

[Python]
def eat(number, need, remaining):
  if need > remaining:
    return [number + remaining, 0]
  else:
    return [number + need, remaining - need]

if __name__ == "__main__":
  result = eat(5, 6, 10)
  expected = [11, 4]
  assert result == expected, "Assertion failed: eat(5, 6, 10) == {11, 4}"

  result = eat(4, 8, 9)
  expected = [12, 1]
  assert result == expected, "Assertion failed: eat(4, 8, 9) == {12, 1}"

  result = eat(1, 10, 10)
  expected = [11, 0]
  assert result == expected, "Assertion failed: eat(1, 10, 10) == {11, 0}"

  result = eat(2, 11, 5)
  expected = [7, 0]
  assert result == expected, "Assertion failed: eat(2, 11, 5) == {7, 0}"

  result = eat(4, 5, 7)
  expected = [9, 2]
  assert result == expected, "Assertion failed: eat(4, 5, 7) == {9, 2}"

  result = eat(4, 5, 1)
  expected = [5, 0]
  assert result == expected, "Assertion failed: eat(4, 5, 1) == {5, 0}"

  print("All tests passed.")

[Java]
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
  public static void main(String[] args) {
    List<Integer> result;
    List<Integer> expected;

    // Test cases
    result = eat(5, 6, 10);
    expected = Arrays.asList(11, 4);
    if (!result.equals(expected)) {
      System.out.println("Assertion failed: eat(5, 6, 10) == {11, 4}");
      System.exit(1);
    }

    result = eat(4, 8, 9);
    expected = Arrays.asList(12, 1);
    if (!result.equals(expected)) {
      System.out.println("Assertion failed: eat(4, 8, 9) == {12, 1}");
      System.exit(1);
    }

    result = eat(1, 10, 10);
    expected = Arrays.asList(11, 0);
    if (!result.equals(expected)) {
      System.out.println("Assertion failed: eat(1, 10, 10) == {11, 0}");
      System.exit(1);
    }

    result = eat(2, 11, 5);
    expected = Arrays.asList(7, 0);
    if (!result.equals(expected)) {
      System.out.println("Assertion failed: eat(2, 11, 5) == {7, 0}");
      System.exit(1);
    }

    result = eat(4, 5, 7);
    expected = Arrays.asList(9, 2);
    if (!result.equals(expected)) {
      System.out.println("Assertion failed: eat(4, 5, 7) == {9, 2}");
      System.exit(1);
    }

    result = eat(4, 5, 1);
    expected = Arrays.asList(5, 0);
    if (!result.equals(expected)) {
      System.out.println("Assertion failed: eat(4, 5, 1) == {5, 0}");
      System.exit(1);
    }

    System.out.println("All tests passed.");
  }

  public static List<Integer> eat(int number, int need, int remaining) {
    List<Integer> res = new ArrayList<>();

    if (need > remaining) {
      res.add(number + remaining);
      res.add(0);
    } else {
      res.add(number + need);
      res.add(remaining - need);
    }

    return res;
  }
}

[JavaScript]
function eat(number, need, remaining) {
  if (need > remaining) {
    return [number + remaining, 0];
  } else {
    return [number + need, remaining - need];
  }
}

if (eat(5, 6, 10)[0] !== 11 || eat(5, 6, 10)[1] !== 4) {
  console.log("Assertion failed: eat(5, 6, 10) == {11, 4}");
  process.exit(1);
}

if (eat(4, 8, 9)[0] !== 12 || eat(4, 8, 9)[1] !== 1) {
  console.log("Assertion failed: eat(4, 8, 9) == {12, 1}");
  process.exit(1);
}

if (eat(1, 10, 10)[0] !== 11 || eat(1, 10, 10)[1] !== 0) {
  console.log("Assertion failed: eat(1, 10, 10) == {11, 0}");
  process.exit(1);
}

if (eat(2, 11, 5)[0] !== 7 || eat(2, 11,
