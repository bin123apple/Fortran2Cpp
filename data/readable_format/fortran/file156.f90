module Utilities
  implicit none
contains
  subroutine swapInteger(a, b)
    integer, intent(inout) :: a, b
    integer :: tmp
    tmp = a
    a = b
    b = tmp
  end subroutine swapInteger
  
  subroutine swapReal(a, b)
    real, intent(inout) :: a, b
    real :: tmp
    tmp = a
    a = b
    b = tmp
  end subroutine swapReal
end module Utilities

program test_util_a
  use Utilities
  implicit none
  integer :: i1 = 1, i2 = 3
  real    :: r1 = 9.2, r2 = 5.6

  ! Original test demonstration
  write(*,'("Initial state:",1x,2(a,i0,1x), 2(a,f0.2,1x))') &
       "i1 = ", i1, ", i2 = ", i2, ", r1 = ", r1, ", r2 = ", r2
  call swapInteger(i1, i2)
  call swapReal(r1, r2)
  write(*,'("State after swaps:",1x,2(a,i0,1x), 2(a,f0.2,1x))') &
       "i1 = ", i1, ", i2 = ", i2, ", r1 = ", r1, ", r2 = ", r2

  ! Test procedures
  call testSwapInteger()
  call testSwapReal()
contains
  subroutine testSwapInteger()
    integer :: i1 = 5, i2 = 10
    call swapInteger(i1, i2)
    if (i1 == 10 .and. i2 == 5) then
      write(*,*) "testSwapInteger: Passed"
    else
      write(*,*) "testSwapInteger: Failed"
    endif
  end subroutine testSwapInteger
  
  subroutine testSwapReal()
    real :: r1 = 1.0, r2 = 2.0
    call swapReal(r1, r2)
    if (r1 == 2.0 .and. r2 == 1.0) then
      write(*,*) "testSwapReal: Passed"
    else
      write(*,*) "testSwapReal: Failed"
    endif
  end subroutine testSwapReal
end program test_util_a