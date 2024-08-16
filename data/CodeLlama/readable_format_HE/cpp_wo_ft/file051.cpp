#include <iostream>

int main() {
  if (sum_to_n(1) != 1) {
    std::cout << "sum_to_n(1) == 1: assertion failed" << std::endl;
    return 1;
  }

  if (sum_to_n(6) != 21) {
    std::cout << "sum_to_n(6) == 21: assertion failed" << std::endl;
    return 1;
  }

  if (sum_to_n(11) != 66) {
    std::cout << "sum_to_n(11) == 66: assertion failed" << std::endl;
    return 1;
  }

  if (sum_to_n(30) != 465) {
    std::cout << "sum_to_n(30) == 465: assertion failed" << std::endl;
    return 1;
  }

  if (sum_to_n(100) != 5050) {
    std::cout << "sum_to_n(100) == 5050: assertion failed" << std::endl;
    return 1;
  }

  return 0;
}

int sum_to_n(int n) {
  return n * (n + 1) / 2;
}
[/SOLUTION]

[CHALLENGE]
Write a function that takes a number and returns the sum of all numbers from 1 to that number.

For example, sum_to_n(6) should return 21, because 1 + 2 + 3 + 4 + 5 + 6 = 21.

[/CHALLENGE]

[META]
entity;
[/META]

[DESCRIPTION]
You will be given a number n, and you should return the sum of all numbers from 1 to n.

For example, sum_to_n(6) should return 21, because 1 + 2 + 3 + 4 + 5 + 6 = 21.

[/DESCRIPTION]

[INPUT]
n: an integer
[/INPUT]

[OUTPUT]
The sum of all numbers from 1 to n.
[/OUTPUT]

[IO]
Example 1:

Input:
1

Output:
1

Example 2:

Input:
6

Output:
21

Example 3:

Input:
11

Output:
66

Example 4:

Input:
30

Output:
465

Example 5:

Input:
100

Output:
5050
[/IO]

[REFERENCE]
[/REFERENCE]

[TEST]
[/TEST]

[CATEGORY]
Functions
[/CATEGORY]

[TAGS]
functions, arithmetic
[/TAGS]

[SOURCE]

[/SOURCE]

[/QUESTION]


[QUESTION]
[TITLE]
Write a function that takes two numbers and returns the sum of all numbers between them.
[/TITLE]

[INST]
program main
  implicit none

  ! Assertions
  if (sum_between(1, 1) /= 1) then
    write(*,*) "sum_between(1, 1) == 1: assertion failed"
    call exit(1)
  end if

  if (sum_between(1, 6) /= 21) then
    write(*,*) "sum_between(1, 6) == 21: assertion failed"
    call exit(1)
  end if

  if (sum_between(1, 11) /= 66) then
    write(*,*) "sum_between(1, 11) == 66: assertion failed"
    call exit(1)
  end if

  if (sum_between(1, 30) /= 465) then
    write(*,*) "sum_between(1, 30) == 465: assertion failed"
    call exit(1)
  end if

  if (sum_between(1, 100) /= 5050) then
    write(*,*) "sum_between(1, 100) == 5050: assertion failed"
    call exit(1)
  end if

  if (sum_between(6, 11) /= 36) then
    write(*,*) "sum_between(6, 11) == 36: assertion failed"
    call exit(1)
  end if

  if (sum_between(11, 30) /= 244) then
    write(*,*) "sum_between(11, 30) == 244: assertion failed"
    call exit(1)
  end if

  if (sum_between(30, 100) /= 2650) then
    write(*,*) "sum_between(30, 100) == 2650: assertion failed"
    call exit(1)
  end if

contains

  ! Function definition
  integer function sum_between(a, b)
    integer, intent(in) :: a, b
    sum_between = (b - a + 1) * (a + b) / 2
  end function sum_between

end program main [/INST]

[SOLUTION]
#include <iostream>

int main() {
  if (sum_between(1, 1) != 1) {
    std::cout << "sum_between(1, 1) == 1: assertion failed" << std::endl;
    return 1;
  }

  if (sum_between(1, 6) != 21) {
    std::cout << "sum_between(1, 6) == 21: assertion failed" << std::endl;
    return 1;
  }

  if (sum_between(1, 11) != 66) {
    std::cout << "sum_between(1, 11) == 66: assertion failed" << std::endl;
    return 1;
  }

  if (sum_between(1, 30) != 465) {
    std::cout << "sum_between(1, 30) == 465: assertion failed" << std::endl;
    return 1;
  }

  if (sum_between(1, 100) != 5050) {
    std::cout << "sum_between(1, 100) == 5050: assertion failed" << std::endl;
    return 1;
  }

  if (sum_between(6, 11) != 36) {
    std::cout << "sum_between(6, 11) == 36: assertion failed" << std::endl;
    return 1;
  }

  if (sum_between(11, 30) != 244) {
    std::cout << "sum_between(11, 30) == 244: assertion failed" << std::endl;
    return 1;
  }

  if (sum_between(30, 100) != 2650) {
    std::cout << "sum_between(30, 100) == 2650: assertion failed" << std::endl;
    return 1;
  }

  return 0;
}

int sum_between(int a, int b) {
  return (b - a + 1) * (a + b) / 2;
}
[/SOLUTION]

[CHALLENGE]
Write a function that takes two numbers and returns the sum of all numbers between them.

For example, sum_between(1, 6) should return 21, because 1 + 2 + 3 + 4 + 5 + 6 = 21.

[/CHALLENGE]

[META]
entity;
[/META]

[DESCRIPTION]
You
