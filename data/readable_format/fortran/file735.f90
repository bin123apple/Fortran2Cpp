! Define the kernel subroutine
subroutine kernel(lo, hi, a, b, c)
  implicit none
  integer :: lo, hi, i
  real, dimension(lo:hi) :: a, b, c

  do i = lo, hi
     b(i) = a(i)
  end do

  do i = lo, hi
     c(i) = b(i)
  end do
end subroutine kernel

! Main program starts here
program main
  implicit none
  integer :: n = 20
  real, dimension(1:20) :: a, b, c
  integer :: i
  logical :: test_passed

  ! Initialize arrays
  a(:) = 1
  b(:) = 2
  c(:) = 3

  ! Call the kernel subroutine
  call kernel(1, n, a, b, c)

  ! Perform the test to verify functionality
  test_passed = .true.
  do i = 1, n
     if (c(i) /= 1) then
        test_passed = .false.
        exit
     end if
  end do

  if (test_passed) then
     print *, "Test passed: All elements of c are equal to 1."
  else
     print *, "Test failed: Not all elements of c are equal to 1."
  end if
end program main