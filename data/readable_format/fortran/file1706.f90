program test_array_operation
  integer :: i, j, errors
  real, dimension(5,5) :: a, b, c

  ! Initialize arrays
  do i = 1, 5
     do j = 1, 5
        b(i,j) = i + j
        c(i,j) = i - j
     end do
  end do

  ! Perform the array operation
  a = b + c

  ! Check the results
  errors = 0
  do i = 1, 5
     do j = 1, 5
        if (a(i,j) /= 2*i) then
           errors = errors + 1
        end if
     end do
  end do

  if (errors == 0) then
     print *, "Array operation test PASSED."
  else
     print *, "Array operation test FAILED."
  end if
end program test_array_operation