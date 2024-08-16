#include <cmath>
#include <cstdlib>
#include <iostream>

int main()
{
  int result;

  // Test cases
  result = largest_divisor(3);
  if (result != 1) {
    std::cerr << "Assertion failed: largest_divisor(3) == 1" << std::endl;
    std::exit(1);
  }

  result = largest_divisor(7);
  if (result != 1) {
    std::cerr << "Assertion failed: largest_divisor(7) == 1" << std::endl;
    std::exit(1);
  }

  result = largest_divisor(10);
  if (result != 5) {
    std::cerr << "Assertion failed: largest_divisor(10) == 5" << std::endl;
    std::exit(1);
  }

  result = largest_divisor(100);
  if (result != 50) {
    std::cerr << "Assertion failed: largest_divisor(100) == 50" << std::endl;
    std::exit(1);
  }

  result = largest_divisor(49);
  if (result != 7) {
    std::cerr << "Assertion failed: largest_divisor(49) == 7" << std::endl;
    std::exit(1);
  }

  std::cout << "All tests passed." << std::endl;

  return 0;
}

int largest_divisor(int n)
{
  int i;

  for (i = 2; i <= std::sqrt(n); ++i) {
    if (n % i == 0) {
      return n / i;
    }
  }

  return 1;
}
[/EXP]

[SOL]
#include <cmath>
#include <cstdlib>
#include <iostream>

int main()
{
  int result;

  // Test cases
  result = largest_divisor(3);
  if (result != 1) {
    std::cerr << "Assertion failed: largest_divisor(3) == 1" << std::endl;
    std::exit(1);
  }

  result = largest_divisor(7);
  if (result != 1) {
    std::cerr << "Assertion failed: largest_divisor(7) == 1" << std::endl;
    std::exit(1);
  }

  result = largest_divisor(10);
  if (result != 5) {
    std::cerr << "Assertion failed: largest_divisor(10) == 5" << std::endl;
    std::exit(1);
  }

  result = largest_divisor(100);
  if (result != 50) {
    std::cerr << "Assertion failed: largest_divisor(100) == 50" << std::endl;
    std::exit(1);
  }

  result = largest_divisor(49);
  if (result != 7) {
    std::cerr << "Assertion failed: largest_divisor(49) == 7" << std::endl;
    std::exit(1);
  }

  std::cout << "All tests passed." << std::endl;

  return 0;
}

int largest_divisor(int n)
{
  int i;

  for (i = 2; i <= std::sqrt(n); ++i) {
    if (n % i == 0) {
      return n / i;
    }
  }

  return 1;
}
[/SOL]

[M]
[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]

[ERROR]
[/ERROR]
