program test_factorial
  implicit none
  integer :: result, i

  ! Test the calculate_factorial subroutine with various inputs
  do i = 0, 5
     call calculate_factorial(i, result)
     print *, "Factorial of", i, "is", result
  end do

contains

  subroutine calculate_factorial(n, result)
    integer, intent(in) :: n
    integer, intent(out) :: result
    integer :: i
    result = 1
    do i = 1, n
       result = result * i
    end do
  end subroutine calculate_factorial

end program test_factorial