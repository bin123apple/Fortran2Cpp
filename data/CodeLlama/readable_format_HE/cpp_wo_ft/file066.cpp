#include <cmath>

bool iscuber(int a) {
  int i;
  for (i = 0; i <= std::abs(a) / 3; i++) {
    if (i * i * i == std::abs(a)) {
      return true;
    }
  }
  return false;
}

int main() {
  // Assertions
  if (!iscuber(1)) {
    std::cout << "iscuber(1): assertion failed" << std::endl;
    return 1;
  }

  if (iscuber(2)) {
    std::cout << "iscuber(2): assertion failed" << std::endl;
    return 1;
  }

  if (!iscuber(-1)) {
    std::cout << "iscuber(-1): assertion failed" << std::endl;
    return 1;
  }

  if (!iscuber(64)) {
    std::cout << "iscuber(64): assertion failed" << std::endl;
    return 1;
  }

  if (iscuber(180)) {
    std::cout << "iscuber(180): assertion failed" << std::endl;
    return 1;
  }

  if (!iscuber(1000)) {
    std::cout << "iscuber(1000): assertion failed" << std::endl;
    return 1;
  }

  if (!iscuber(0)) {
    std::cout << "iscuber(0): assertion failed" << std::endl;
    return 1;
  }

  if (iscuber(1729)) {
    std::cout << "iscuber(1729): assertion failed" << std::endl;
    return 1;
  }

  std::cout << "All tests passed." << std::endl;

  return 0;
}

[C]
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool iscuber(int a) {
  int i;
  for (i = 0; i <= abs(a) / 3; i++) {
    if (i * i * i == abs(a)) {
      return true;
    }
  }
  return false;
}

int main() {
  // Assertions
  if (!iscuber(1)) {
    printf("iscuber(1): assertion failed
");
    return 1;
  }

  if (iscuber(2)) {
    printf("iscuber(2): assertion failed
");
    return 1;
  }

  if (!iscuber(-1)) {
    printf("iscuber(-1): assertion failed
");
    return 1;
  }

  if (!iscuber(64)) {
    printf("iscuber(64): assertion failed
");
    return 1;
  }

  if (iscuber(180)) {
    printf("iscuber(180): assertion failed
");
    return 1;
  }

  if (!iscuber(1000)) {
    printf("iscuber(1000): assertion failed
");
    return 1;
  }

  if (!iscuber(0)) {
    printf("iscuber(0): assertion failed
");
    return 1;
  }

  if (iscuber(1729)) {
    printf("iscuber(1729): assertion failed
");
    return 1;
  }

  printf("All tests passed.
");

  return 0;
}

[Python]
def iscuber(a):
  for i in range(0, abs(a) / 3 + 1):
    if i * i * i == abs(a):
      return True
  return False


# Assertions
assert iscuber(1)
assert not iscuber(2)
assert iscuber(-1)
assert iscuber(64)
assert not iscuber(180)
assert iscuber(1000)
assert iscuber(0)
assert not iscuber(1729)

print("All tests passed.")

[Java]
public class Cube {
  public static void main(String[] args) {
    // Assertions
    assert isCuber(1);
    assert !isCuber(2);
    assert isCuber(-1);
    assert isCuber(64);
    assert !isCuber(180);
    assert isCuber(1000);
    assert isCuber(0);
    assert !isCuber(1729);

    System.out.println("All tests passed.");
  }

  public static boolean isCuber(int a) {
    for (int i = 0; i <= Math.abs(a) / 3; i++) {
      if (i * i * i == Math.abs(a)) {
        return true;
      }
    }
    return false;
  }
}

[JavaScript]
function isCuber(a) {
  for (let i = 0; i <= Math.abs(a) / 3; i++) {
    if (i * i * i == Math.abs(a)) {
      return true;
    }
  }
  return false;
}

// Assertions
console.assert(isCuber(1));
console.assert(!isCuber(2));
console.assert(isCuber(-1));
console.assert(isCuber(64));
console.assert(!isCuber(180));
console.assert(isCuber(1000));
console.assert(isCuber(0));
console.assert(!isCuber(1729));

console.log("All tests passed.");

[PHP]
function isCuber($a) {
  for ($i = 0; $i <= abs($a) / 3; $i++) {
    if ($i * $i * $i == abs($a)) {
      return true;
    }
  }
  return false;
}

// Assertions
assert(isCuber(1));
assert(!isCuber(2));
assert(isCuber(-1));
assert(isCuber(64));
assert(!isCuber(180));
assert(isCuber(1000));
assert(isCuber(0));
assert(!isCuber(1729));

echo "All tests passed.";

[Ruby]
def is_cuber(a)
  for i in 0..(a.abs / 3)
    return true if i * i * i == a.abs
  end
  false
end

# Assertions
assert(is_cuber(1))
assert(!is_cuber(2))
assert(is_cuber(-1))
assert(is_cuber(64))
assert(!is_cuber(180))
assert(is_cuber(1000))
assert(is_cuber(0))
assert(!is_cuber(1729))

puts "All tests passed."

[Swift]
func isCuber(_ a: Int) -> Bool {
  for i in 0..<(abs(a) / 3 + 1) {
    if i * i * i == abs(a) {
      return true
    }
  }
  return false
}

// Assertions
assert(isCuber(1))
assert(!isCuber(2))
assert(isCuber(-1))
assert(isCuber(64))
assert(!isCuber(180))
assert(isCuber(1000))
assert(isCuber(0))
assert(!isCuber(1729))

print("All tests passed.")

[Go]
package main

import (
  "fmt"
  "math"
)

func isCuber(a int) bool {
  for i := 0; i <= int(math.Abs(float64(a)) / 3); i++ {
    if i*i*i == int(math.Abs(float64(a))) {
      return true
    }
  }
  return false
}

func main() {
  // Assertions
  if !isCuber(1) {
    fmt.Print
