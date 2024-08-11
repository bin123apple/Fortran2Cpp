program test_main
  implicit none
  integer, parameter :: n = 10
  integer :: a(n-1), b(n-1), c(n-1)
  integer :: i
  logical :: test_passed

  ! Populate arrays
  do i = 0, n - 1
     a(i) = i * 2
     b(i) = i * 4
     c(i) = a(i) + b(i)
  end do

  ! Test
  test_passed = .true.
  do i = 0, n - 1
     if (c(i) /= a(i) + b(i)) then
        test_passed = .false.
        exit
     end if
  end do

  if (test_passed) then
     print *, "Test passed."
  else
     print *, "Test failed."
  end if

end program test_main