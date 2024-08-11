module m
  integer :: i = 3
  integer :: j = 4
end module m

! A subroutine for testing
subroutine test_i_j()
  use m, only: i
  integer :: j
  j = 77

  if (i == 3 .and. j == 77) then
    print *, "Test passed: i and j have expected values."
  else
    print *, "Test failed: Unexpected values for i or j."
  end if
end subroutine test_i_j

program t
  use m, only: i
  integer :: j
  j = 77
  print '(i0,1x,i0)', i, j

  ! Call the test subroutine
  call test_i_j()
end program t