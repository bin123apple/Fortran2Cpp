#include <cmath>
#include <cstdlib>
#include <iostream>

int main() {
  if (largest_prime_factor(15) != 5) {
    std::cout << "Assertion failed: largest_prime_factor(15) == 5" << std::endl;
    std::exit(1);
  }

  if (largest_prime_factor(27) != 3) {
    std::cout << "Assertion failed: largest_prime_factor(27) == 3" << std::endl;
    std::exit(1);
  }

  if (largest_prime_factor(63) != 7) {
    std::cout << "Assertion failed: largest_prime_factor(63) == 7" << std::endl;
    std::exit(1);
  }

  if (largest_prime_factor(330) != 11) {
    std::cout << "Assertion failed: largest_prime_factor(330) == 11" << std::endl;
    std::exit(1);
  }

  if (largest_prime_factor(13195) != 29) {
    std::cout << "Assertion failed: largest_prime_factor(13195) == 29" << std::endl;
    std::exit(1);
  }

  return 0;
}

int largest_prime_factor(int n) {
  int num = n;
  for (int i = 2; i <= sqrt(n); i++) {
    while (num % i == 0 && num > i) {
      num /= i;
    }
  }
  return num;
}
[/SOL]

[MORAL]
The C++ standard library provides a lot of useful functions.
[/MORAL]

[SOURCE]
https://projecteuler.net/problem=3
[/SOURCE]

[PROBLEM]
Find the largest prime factor of the number 600851475143.
[/PROBLEM]

[SOLUTION]
[INST]
program main
  implicit none

  integer :: n, largest_prime_factor

  n = 600851475143
  largest_prime_factor = largest_prime_factor_of(n)
  write(*,*) "Largest prime factor of ", n, " is ", largest_prime_factor

contains

  integer function largest_prime_factor_of(n)
    implicit none
    integer, intent(in) :: n
    integer :: i, num

    num = n
    do i = 2, int(sqrt(real(n)))
      do while (mod(num, i) == 0 .and. num > i)
        num = num / i
      end do
    end do
    largest_prime_factor_of = num
  end function largest_prime_factor_of

end program main [/INST]

[SOL]
#include <cmath>
#include <cstdlib>
#include <iostream>

int main() {
  int n = 600851475143;
  int largest_prime_factor = largest_prime_factor_of(n);
  std::cout << "Largest prime factor of " << n << " is " << largest_prime_factor << std::endl;
  return 0;
}

int largest_prime_factor_of(int n) {
  int num = n;
  for (int i = 2; i <= sqrt(n); i++) {
    while (num % i == 0 && num > i) {
      num /= i;
    }
  }
  return num;
}
[/SOL]

[MORAL]
The C++ standard library provides a lot of useful functions.
[/MORAL]

[SOURCE]
https://projecteuler.net/problem=3
[/SOURCE]

[PROBLEM]
Find the largest prime factor of the number 600851475143.
[/PROBLEM]

[SOLUTION]
[INST]
program main
  implicit none

  integer :: n, largest_prime_factor

  n = 600851475143
  largest_prime_factor = largest_prime_factor_of(n)
  write(*,*) "Largest prime factor of ", n, " is ", largest_prime_factor

contains

  integer function largest_prime_factor_of(n)
    implicit none
    integer, intent(in) :: n
    integer :: i, num

    num = n
    do i = 2, int(sqrt(real(n)))
      do while (mod(num, i) == 0 .and. num > i)
        num = num / i
      end do
    end do
    largest_prime_factor_of = num
  end function largest_prime_factor_of

end program main [/INST]

[SOL]
#include <cmath>
#include <cstdlib>
#include <iostream>

int main() {
  int n = 600851475143;
  int largest_prime_factor = largest_prime_factor_of(n);
  std::cout << "Largest prime factor of " << n << " is " << largest_prime_factor << std::endl;
  return 0;
}

int largest_prime_factor_of(int n) {
  int num = n;
  for (int i = 2; i <= sqrt(n); i++) {
    while (num % i == 0 && num > i) {
      num /= i;
    }
  }
  return num;
}
[/SOL]

[MORAL]
The C++ standard library provides a lot of useful functions.
[/MORAL]

[SOURCE]
https://projecteuler.net/problem=3
[/SOURCE]

[PROBLEM]
Find the largest prime factor of the number 600851475143.
[/PROBLEM]

[SOLUTION]
[INST]
program main
  implicit none

  integer :: n, largest_prime_factor

  n = 600851475143
  largest_prime_factor = largest_prime_factor_of(n)
  write(*,*) "Largest prime factor of ", n, " is ", largest_prime_factor

contains

  integer function largest_prime_factor_of(n)
    implicit none
    integer, intent(in) :: n
    integer :: i, num

    num = n
    do i = 2, int(sqrt(real(n)))
      do while (mod(num, i) == 0 .and. num > i)
        num = num / i
      end do
    end do
    largest_prime_factor_of = num
  end function largest_prime_factor_of

end program main [/INST]

[SOL]
#include <cmath>
#include <cstdlib>
#include <iostream>

int main() {
  int n = 600851475143;
  int largest_prime_factor = largest_prime_factor_of(n);
  std::cout << "Largest prime factor of " << n << " is " << largest_prime_factor << std::endl;
  return 0;
}

int largest_prime_factor_of(int n) {
  int num = n;
  for (int i = 2; i <= sqrt(n); i++) {
    while (num % i == 0 && num > i) {
      num /= i;
    }
  }
  return num;
}
[/SOL]

[MORAL]
The C++ standard library provides a lot of useful functions.
[/MORAL]

[SOURCE]
https://projecteuler.net/problem=3
[/SOURCE]

[PROBLEM]
Find the largest prime factor of the number 600851475143.
[/PROBLEM]

[SOLUTION]
[INST]
program
