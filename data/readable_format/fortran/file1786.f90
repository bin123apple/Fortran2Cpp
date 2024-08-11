program test_factorial
  implicit none
  integer :: test_result

  ! Test 1: Factorial of 5
  test_result = factorial(5)
  if (test_result == 120) then
    print *, "Test 1 Passed: Factorial of 5 is 120."
  else
    print *, "Test 1 Failed: Factorial of 5 is not 120, result was ", test_result
  end if

  ! Test 2: Factorial of 0 (Edge Case)
  test_result = factorial(0)
  if (test_result == 1) then
    print *, "Test 2 Passed: Factorial of 0 is 1."
  else
    print *, "Test 2 Failed: Factorial of 0 is not 1, result was ", test_result
  end if

contains

  function factorial(n) result(fact)
    integer, intent(in) :: n
    integer :: fact, i

    fact = 1
    do i = 1, n
       fact = fact * i
    end do
  end function factorial

end program test_factorial