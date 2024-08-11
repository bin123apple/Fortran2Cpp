program test_transfer
  implicit none
  integer :: ix, iy, test_ix, test_iy
  real :: x, y
  logical :: test_passed

  x = 1.0
  y = x
  ix = transfer(x, ix)
  iy = transfer(y, iy)

  ! Assuming a known correct integer representation for the test
  test_ix = 1065353216
  test_iy = 1065353216

  test_passed = (ix == test_ix) .and. (iy == test_iy)

  if (test_passed) then
    print *, "Test passed: ix and iy have the expected integer representations."
  else
    print *, "Test failed: ix and/or iy do not match the expected values."
    print *, "ix = ", ix, " expected = ", test_ix
    print *, "iy = ", iy, " expected = ", test_iy
  end if
end program test_transfer