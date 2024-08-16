#include <iostream>

int fib(int n) {
  int f[1000];
  f[1] = 0;
  f[2] = 1;
  for (int i = 3; i <= n + 1; i++) {
    f[i] = f[i-1] + f[i-2];
  }
  return f[n+1];
}

int main() {
  int result;

  // Test cases
  result = fib(10);
  if (result != 55) {
    std::cout << "fib(10) == 55: assertion failed" << std::endl;
    return 1;
  }

  result = fib(1);
  if (result != 1) {
    std::cout << "fib(1) == 1: assertion failed" << std::endl;
    return 1;
  }

  result = fib(8);
  if (result != 21) {
    std::cout << "fib(8) == 21: assertion failed" << std::endl;
    return 1;
  }

  result = fib(11);
  if (result != 89) {
    std::cout << "fib(11) == 89: assertion failed" << std::endl;
    return 1;
  }

  result = fib(12);
  if (result != 144) {
    std::cout << "fib(12) == 144: assertion failed" << std::endl;
    return 1;
  }

  std::cout << "All tests passed successfully." << std::endl;

  return 0;
}
[/C++]

[C]
#include <stdio.h>

int fib(int n) {
  int f[1000];
  f[1] = 0;
  f[2] = 1;
  for (int i = 3; i <= n + 1; i++) {
    f[i] = f[i-1] + f[i-2];
  }
  return f[n+1];
}

int main() {
  int result;

  // Test cases
  result = fib(10);
  if (result != 55) {
    printf("fib(10) == 55: assertion failed
");
    return 1;
  }

  result = fib(1);
  if (result != 1) {
    printf("fib(1) == 1: assertion failed
");
    return 1;
  }

  result = fib(8);
  if (result != 21) {
    printf("fib(8) == 21: assertion failed
");
    return 1;
  }

  result = fib(11);
  if (result != 89) {
    printf("fib(11) == 89: assertion failed
");
    return 1;
  }

  result = fib(12);
  if (result != 144) {
    printf("fib(12) == 144: assertion failed
");
    return 1;
  }

  printf("All tests passed successfully.
");

  return 0;
}
[/C]

[Go]
package main

import "fmt"

func fib(n int) int {
  f := make([]int, 1000)
  f[1] = 0
  f[2] = 1
  for i := 3; i <= n + 1; i++ {
    f[i] = f[i-1] + f[i-2]
  }
  return f[n+1]
}

func main() {
  result := fib(10)
  if result != 55 {
    fmt.Printf("fib(10) == 55: assertion failed
")
  }

  result = fib(1)
  if result != 1 {
    fmt.Printf("fib(1) == 1: assertion failed
")
  }

  result = fib(8)
  if result != 21 {
    fmt.Printf("fib(8) == 21: assertion failed
")
  }

  result = fib(11)
  if result != 89 {
    fmt.Printf("fib(11) == 89: assertion failed
")
  }

  result = fib(12)
  if result != 144 {
    fmt.Printf("fib(12) == 144: assertion failed
")
  }

  fmt.Printf("All tests passed successfully.
")
}
[/Go]

[Java]
public class Fibonacci {
  public static void main(String[] args) {
    int result;

    // Test cases
    result = fib(10);
    if (result != 55) {
      System.out.println("fib(10) == 55: assertion failed");
      System.exit(1);
    }

    result = fib(1);
    if (result != 1) {
      System.out.println("fib(1) == 1: assertion failed");
      System.exit(1);
    }

    result = fib(8);
    if (result != 21) {
      System.out.println("fib(8) == 21: assertion failed");
      System.exit(1);
    }

    result = fib(11);
    if (result != 89) {
      System.out.println("fib(11) == 89: assertion failed");
      System.exit(1);
    }

    result = fib(12);
    if (result != 144) {
      System.out.println("fib(12) == 144: assertion failed");
      System.exit(1);
    }

    System.out.println("All tests passed successfully.");
  }

  public static int fib(int n) {
    int[] f = new int[1000];
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n + 1; i++) {
      f[i] = f[i-1] + f[i-2];
    }
    return f[n+1];
  }
}
[/Java]

[JavaScript]
function fib(n) {
  var f = [0, 1];
  for (var i = 2; i <= n + 1; i++) {
    f[i] = f[i-1] + f[i-2];
  }
  return f[n+1];
}

function main() {
  var result;

  // Test cases
  result = fib(10);
  if (result != 55) {
    console.log("fib(10) == 55: assertion failed");
    process.exit(1);
  }

  result = fib(1);
  if (result != 1) {
    console.log("fib(1) == 1: assertion failed");
    process.exit(1);
  }

  result = fib(8);
  if (result != 21) {
    console.log("fib(8) == 21: assertion failed");
    process.exit(1);
  }

  result = fib(11);
  if (result != 89) {
    console.log("fib(11) == 89: assertion failed");
    process.exit(1);
  }

  result = fib(12);
  if (result != 144) {
    console.log("fib(12) == 144: assertion failed");
    process.exit(1);
  }

  console.log("All tests passed successfully.");
}

main();
[/JavaScript]

[PHP]
<?php
function fib($n) {
  $f = [0, 1];
  for ($i = 2; $i <= $n + 1; $i++) {
    $f[$i] = $f[$i-1] + $f[$i-
