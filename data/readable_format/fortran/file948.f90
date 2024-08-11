module FIBONACCIRECURSIVO__genmod
  implicit none
contains
  function FIBONACCIRECURSIVO(A) result(res)
    integer, intent(in) :: A
    integer :: res

    if (A <= 1) then
      res = A
    else
      res = FIBONACCIRECURSIVO(A-1) + FIBONACCIRECURSIVO(A-2)
    endif
  end function FIBONACCIRECURSIVO
end module FIBONACCIRECURSIVO__genmod

program testFibonacci
  use FIBONACCIRECURSIVO__genmod
  implicit none

  integer :: i

  ! Test the Fibonacci function with a few values
  do i = 0, 10
     print *, 'FIBONACCIRECURSIVO(', i, ') = ', FIBONACCIRECURSIVO(i)
  end do
end program testFibonacci