#include <cmath>
#include <cstdlib>
#include <iostream>

int main() {
  using namespace std;

  // Function declaration
  bool right_angle_triangle(double, double, double);

  // Assertions
  if (!right_angle_triangle(3.0, 4.0, 5.0)) {
    cout << "Assertion failed: right_angle_triangle(3, 4, 5) == true" << endl;
    exit(1);
  }

  if (right_angle_triangle(1.0, 2.0, 3.0)) {
    cout << "Assertion failed: right_angle_triangle(1, 2, 3) == false" << endl;
    exit(1);
  }

  if (!right_angle_triangle(10.0, 6.0, 8.0)) {
    cout << "Assertion failed: right_angle_triangle(10, 6, 8) == true" << endl;
    exit(1);
  }

  if (right_angle_triangle(2.0, 2.0, 2.0)) {
    cout << "Assertion failed: right_angle_triangle(2, 2, 2) == false" << endl;
    exit(1);
  }

  if (!right_angle_triangle(7.0, 24.0, 25.0)) {
    cout << "Assertion failed: right_angle_triangle(7, 24, 25) == true" << endl;
    exit(1);
  }

  if (right_angle_triangle(10.0, 5.0, 7.0)) {
    cout << "Assertion failed: right_angle_triangle(10, 5, 7) == false" << endl;
    exit(1);
  }

  if (!right_angle_triangle(5.0, 12.0, 13.0)) {
    cout << "Assertion failed: right_angle_triangle(5, 12, 13) == true" << endl;
    exit(1);
  }

  if (!right_angle_triangle(15.0, 8.0, 17.0)) {
    cout << "Assertion failed: right_angle_triangle(15, 8, 17) == true" << endl;
    exit(1);
  }

  if (!right_angle_triangle(48.0, 55.0, 73.0)) {
    cout << "Assertion failed: right_angle_triangle(48, 55, 73) == true" << endl;
    exit(1);
  }

  if (right_angle_triangle(1.0, 1.0, 1.0)) {
    cout << "Assertion failed: right_angle_triangle(1, 1, 1) == false" << endl;
    exit(1);
  }

  if (right_angle_triangle(2.0, 2.0, 10.0)) {
    cout << "Assertion failed: right_angle_triangle(2, 2, 10) == false" << endl;
    exit(1);
  }

  return 0;
}

bool right_angle_triangle(double a, double b, double c) {
  double epsilon = 1.0e-4;

  if (abs(a*a + b*b - c*c) < epsilon || abs(a*a + c*c - b*b) < epsilon || abs(b*b + c*c - a*a) < epsilon) {
    return true;
  } else {
    return false;
  }
}
[/SOLUTION]

[CHECK]

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  bool right_angle_triangle(double, double, double);

  if (!right_angle_triangle(3.0, 4.0, 5.0)) {
    cout << "Assertion failed: right_angle_triangle(3, 4, 5) == true" << endl;
    exit(1);
  }

  if (right_angle_triangle(1.0, 2.0, 3.0)) {
    cout << "Assertion failed: right_angle_triangle(1, 2, 3) == false" << endl;
    exit(1);
  }

  if (!right_angle_triangle(10.0, 6.0, 8.0)) {
    cout << "Assertion failed: right_angle_triangle(10, 6, 8) == true" << endl;
    exit(1);
  }

  if (right_angle_triangle(2.0, 2.0, 2.0)) {
    cout << "Assertion failed: right_angle_triangle(2, 2, 2) == false" << endl;
    exit(1);
  }

  if (!right_angle_triangle(7.0, 24.0, 25.0)) {
    cout << "Assertion failed: right_angle_triangle(7, 24, 25) == true" << endl;
    exit(1);
  }

  if (right_angle_triangle(10.0, 5.0, 7.0)) {
    cout << "Assertion failed: right_angle_triangle(10, 5, 7) == false" << endl;
    exit(1);
  }

  if (!right_angle_triangle(5.0, 12.0, 13.0)) {
    cout << "Assertion failed: right_angle_triangle(5, 12, 13) == true" << endl;
    exit(1);
  }

  if (!right_angle_triangle(15.0, 8.0, 17.0)) {
    cout << "Assertion failed: right_angle_triangle(15, 8, 17) == true" << endl;
    exit(1);
  }

  if (!right_angle_triangle(48.0, 55.0, 73.0)) {
    cout << "Assertion failed: right_angle_triangle(48, 55, 73) == true" << endl;
    exit(1);
  }

  if (right_angle_triangle(1.0, 1.0, 1.0)) {
    cout << "Assertion failed: right_angle_triangle(1, 1, 1) == false" << endl;
    exit(1);
  }

  if (right_angle_triangle(2.0, 2.0, 10.0)) {
    cout << "Assertion failed: right_angle_triangle(2, 2, 10) == false" << endl;
    exit(1);
  }

  return 0;
}

bool right_angle_triangle(double a, double b, double c) {
  double epsilon = 1.0e-4;

  if (abs(a*a + b*b - c*c) < epsilon || abs(a*a + c*c - b*b) < epsilon || abs(b*b + c*c - a*a) < epsilon) {
    return true;
  } else {
    return false;
  }
}

[/CHECK]

[META]
name = Right Angle Triangle
folder = Fortran
answer = RightAngleTriangle.cpp
[/META]

[/QUESTION]


[QUESTION]

[TXT]

Write a function that takes a string and returns a string with all the vowels removed.

[/TXT]

[C]

[C_PROMPT]
>>> def remove_vowels(s):
...     vowels = "aeiou"
...     return "".join(c for c in s if c.lower() not in vowels)
...
>>> remove_vowels("Hello, world!")
'Hll, wrld!'
>>> remove_vowels("This is a test.")
'Ths s  tst.'
>>> remove_vowels("This is a test.")
'Ths s
