program test_main
  implicit none
  integer, parameter         :: n = 1024
  integer                    :: a(n), b(n), c(n)
  integer                    :: i
  logical                    :: error_occurred

  ! Initialize arrays a and b as per the original logic
  do i = 1, n
     a(i) = (i-1) * 2
     b(i) = (i-1) * 4
  end do

  ! Compute array c as the sum of a and b
  do i = 1, n
     c(i) = a(i) + b(i)
  end do

  ! Perform tests
  error_occurred = .false.
  do i = 1, n
     if (c(i) /= a(i) + b(i)) then
        print *, "Test failed at index: ", i
        error_occurred = .true.
        exit
     endif
  end do
  if (.not. error_occurred) then
     print *, "All tests passed successfully."
  endif

end program test_main