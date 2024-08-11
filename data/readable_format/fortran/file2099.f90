module fibonacci
  implicit none
  save

  integer, parameter :: pr = selected_int_kind(18)

contains

  recursive function fib_naive(n) result(res)
    implicit none
    integer, intent(in) :: n
    integer :: res

    if (n < 2) then
      res = n
    else
      res = fib_naive(n-1) + fib_naive(n-2)
    end if
  end function fib_naive

  function fib_iter(n) result(res)
    implicit none
    integer, intent(in) :: n
    integer(kind=pr) :: res
    integer :: i
    integer(kind=pr) :: a, b, tmp

    a = 0
    b = 1

    do i = 1, n
      tmp = b
      b = a + b
      a = tmp
    end do

    res = a
  end function fib_iter

end module fibonacci

program test_fibonacci
  use fibonacci
  implicit none
  integer :: n, expected, result
  integer(kind=pr) :: result_iter

  ! Test cases for fib_naive
  print *, "Testing fib_naive..."
  n = 10
  expected = 55
  result = fib_naive(n)
  if (result == expected) then
    print *, "PASS: fib_naive(", n, ") = ", result
  else
    print *, "FAIL: Expected ", expected, ", Got ", result
  end if

  ! Test cases for fib_iter
  print *, "Testing fib_iter..."
  n = 20
  expected = 6765
  result_iter = fib_iter(n)
  if (result_iter == expected) then
    print *, "PASS: fib_iter(", n, ") = ", result_iter
  else
    print *, "FAIL: Expected ", expected, ", Got ", result_iter
  end if

end program test_fibonacci