module fibonacci_recursive_mod
  implicit none
contains
  recursive function fibonacci_recursive(n) result(fib)
    integer, intent(in) :: n
    integer :: fib
    if (n <= 1) then
      fib = n
    else
      fib = fibonacci_recursive(n-1) + fibonacci_recursive(n-2)
    endif
  end function fibonacci_recursive
end module fibonacci_recursive_mod

program test_fibonacci
  use fibonacci_recursive_mod
  implicit none
  integer :: n
  
  ! Print Fibonacci series up to the 10th term to test
  print *, "Fibonacci series up to the 10th term:"
  do n = 0, 9
     print *, fibonacci_recursive(n)
  end do
end program test_fibonacci