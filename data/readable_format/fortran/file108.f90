program main
  implicit none
  integer, parameter         :: n = 1024
  integer, dimension (0:n-1) :: a, b, c
  integer                    :: i, ii
  logical                    :: test_passed

  test_passed = .TRUE.

  ! Initialize arrays
  do i = 0, n - 1
     a(i) = i * 2
     b(i) = i * 4
  end do

  !$acc kernels copyin (a(0:n-1), b(0:n-1)) copyout (c(0:n-1))
  ! Perform computation
  do ii = 0, n - 1
     c(ii) = a(ii) + b(ii)
  end do
  !$acc end kernels

  ! Verification loop
  do i = 0, n - 1
     if (c(i) .ne. a(i) + b(i)) then
        test_passed = .FALSE.
        exit
     end if
  end do

  ! Check if all tests passed
  if (test_passed) then
     print *, "All tests passed."
  else
     print *, "Test failed."
  end if

end program main