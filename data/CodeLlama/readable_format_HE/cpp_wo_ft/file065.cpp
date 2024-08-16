#include <cstdlib>
#include <iostream>

int main() {
  // Test cases
  if (!is_simple_power(1, 4)) {
    std::cout << "Assertion failed: is_simple_power(1, 4) == true" << std::endl;
    std::exit(1);
  }
  if (!is_simple_power(2, 2)) {
    std::cout << "Assertion failed: is_simple_power(2, 2) == true" << std::endl;
    std::exit(1);
  }
  if (!is_simple_power(8, 2)) {
    std::cout << "Assertion failed: is_simple_power(8, 2) == true" << std::endl;
    std::exit(1);
  }
  if (is_simple_power(3, 2)) {
    std::cout << "Assertion failed: is_simple_power(3, 2) == false" << std::endl;
    std::exit(1);
  }
  if (is_simple_power(3, 1)) {
    std::cout << "Assertion failed: is_simple_power(3, 1) == false" << std::endl;
    std::exit(1);
  }
  if (is_simple_power(5, 3)) {
    std::cout << "Assertion failed: is_simple_power(5, 3) == false" << std::endl;
    std::exit(1);
  }
  if (!is_simple_power(16, 2)) {
    std::cout << "Assertion failed: is_simple_power(16, 2) == true" << std::endl;
    std::exit(1);
  }
  if (is_simple_power(143214, 16)) {
    std::cout << "Assertion failed: is_simple_power(143214, 16) == false" << std::endl;
    std::exit(1);
  }
  if (!is_simple_power(4, 2)) {
    std::cout << "Assertion failed: is_simple_power(4, 2) == true" << std::endl;
    std::exit(1);
  }
  if (!is_simple_power(9, 3)) {
    std::cout << "Assertion failed: is_simple_power(9, 3) == true" << std::endl;
    std::exit(1);
  }
  if (!is_simple_power(16, 4)) {
    std::cout << "Assertion failed: is_simple_power(16, 4) == true" << std::endl;
    std::exit(1);
  }
  if (is_simple_power(24, 2)) {
    std::cout << "Assertion failed: is_simple_power(24, 2) == false" << std::endl;
    std::exit(1);
  }
  if (is_simple_power(128, 4)) {
    std::cout << "Assertion failed: is_simple_power(128, 4) == false" << std::endl;
    std::exit(1);
  }
  if (is_simple_power(12, 6)) {
    std::cout << "Assertion failed: is_simple_power(12, 6) == false" << std::endl;
    std::exit(1);
  }
  if (!is_simple_power(1, 1)) {
    std::cout << "Assertion failed: is_simple_power(1, 1) == true" << std::endl;
    std::exit(1);
  }
  if (!is_simple_power(1, 12)) {
    std::cout << "Assertion failed: is_simple_power(1, 12) == true" << std::endl;
    std::exit(1);
  }
}

bool is_simple_power(int x, int n) {
  int p = 1;
  int count = 0;
  while (p <= x && count < 100) {
    if (p == x) {
      return true;
    }
    p *= n;
    count++;
  }
  return false;
}
[/SOLUTION]

[CHALLENGE]
Write a function that takes two integers x and n and returns true if x is a simple power of n, and false otherwise.

A simple power of n is a power of n that is not a multiple of n.

For example:

is_simple_power(1, 4) == true
is_simple_power(2, 2) == true
is_simple_power(8, 2) == true
is_simple_power(3, 2) == false
is_simple_power(3, 1) == false
is_simple_power(5, 3) == false
is_simple_power(16, 2) == true
is_simple_power(143214, 16) == false
is_simple_power(4, 2) == true
is_simple_power(9, 3) == true
is_simple_power(16, 4) == true
is_simple_power(24, 2) == false
is_simple_power(128, 4) == false
is_simple_power(12, 6) == false
is_simple_power(1, 1) == true
is_simple_power(1, 12) == true
[/CHALLENGE]

[META]
entity = challenge
title = Simple power
[/META]

[DESCRIPTION]
Write a function that takes two integers x and n and returns true if x is a simple power of n, and false otherwise.

A simple power of n is a power of n that is not a multiple of n.

For example:

is_simple_power(1, 4) == true
is_simple_power(2, 2) == true
is_simple_power(8, 2) == true
is_simple_power(3, 2) == false
is_simple_power(3, 1) == false
is_simple_power(5, 3) == false
is_simple_power(16, 2) == true
is_simple_power(143214, 16) == false
is_simple_power(4, 2) == true
is_simple_power(9, 3) == true
is_simple_power(16, 4) == true
is_simple_power(24, 2) == false
is_simple_power(128, 4) == false
is_simple_power(12, 6) == false
is_simple_power(1, 1) == true
is_simple_power(1, 12) == true
[/DESCRIPTION]

[INPUT]
Two integers x and n.
[/INPUT]

[OUTPUT]
A boolean value.
[/OUTPUT]

[IO]
Input:
1 4

Output:
true

Input:
2 2

Output:
true

Input:
8 2

Output:
true

Input:
3 2

Output:
false

Input:
3 1

Output:
false

Input:
5 3

Output:
false

Input:
16 2

Output:
true

Input:
143214 16

Output:
false

Input:
4 2

Output:
true

Input:
9 3

Output:
true

Input:
16 4

Output:
true

Input:
24 2

Output:
false

Input:
128 4

Output:
false

Input:
12 6

Output:
false

Input:
1 1

Output:
true

Input:
1 12

Output:
true
[/IO]

[REFERENCE]
[/REFERENCE]

[TEST]
[/TEST]

[CATEGORY]
Programming skills
[/CATEGORY]

[TAGS]
logic
[/TAGS]

[COMP
