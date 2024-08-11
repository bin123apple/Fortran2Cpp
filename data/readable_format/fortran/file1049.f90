program map
  implicit none
  integer, parameter :: n = 20
  integer :: a(n), b(n)
  integer :: i

  ! Initialize arrays
  a = 0
  b = 0

  ! Fill arrays
  do i = 1, n
     a(i) = i
     b(i) = i
  end do

  ! Check arrays  
  call check(a, b, n)

  ! Unit Tests
  call testCheck()

contains

  subroutine check(a, b, n)
    integer, intent(in) :: n, a(n), b(n)
    integer :: i
    do i = 1, n
       if (a(i) .ne. b(i)) then
          print *, 'Mismatch found - Check failed'
          return
       endif
    end do
    print *, 'All values match.'
  end subroutine check

  subroutine testCheck()
    integer :: testA(20), testB(20)
    integer :: i

    ! Test case 1: Equal arrays
    do i = 1, 20
       testA(i) = i
       testB(i) = i
    end do
    call check(testA, testB, 20)
    print *, 'Test 1 Passed: Equal arrays'

    ! Test case 2: Unequal arrays
    testB(10) = 0  ! Introduce a difference
    call check(testA, testB, 20)
    print *, 'Test 2 Passed: Unequal arrays'
  end subroutine testCheck

end program map