module factorial_module
  implicit none
contains
  integer function factorial(n)
    implicit none
    integer, intent(in) :: n
    integer :: i

    factorial = 1
    do i = n, 2, -1
      factorial = factorial * i
    end do
  end function factorial
end module factorial_module

program test_factorial
  use factorial_module
  implicit none
  integer :: n, result

  ! Test 1: Factorial of 5 should be 120
  n = 5
  result = factorial(n)
  if (result == 120) then
    print *, 'Test 1 passed.'
  else
    print *, 'Test 1 failed. Expected 120, got', result
  end if

  ! Test 2: Factorial of 0 should be 1
  n = 0
  result = factorial(n)
  if (result == 1) then
    print *, 'Test 2 passed.'
  else
    print *, 'Test 2 failed. Expected 1, got', result
  end if

  ! Test 3: Factorial of 10 should be 3628800
  n = 10
  result = factorial(n)
  if (result == 3628800) then
    print *, 'Test 3 passed.'
  else
    print *, 'Test 3 failed. Expected 3628800, got', result
  end if
end program test_factorial