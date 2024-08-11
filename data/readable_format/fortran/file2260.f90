module circle
  implicit none
  real, parameter :: pi = 4.*atan(1.)
  real :: radius
end module circle

program test_circle
  use circle
  implicit none

  ! Test 1: Check the value of pi
  if (abs(pi - 3.1415927) < 1.0e-6) then
    print *, 'Test 1 passed: pi is correct.'
  else
    print *, 'Test 1 failed: pi is incorrect.'
  end if

  ! Test 2: Check the initial value of radius
  if (radius == 0.0) then
    print *, 'Test 2 passed: Initial radius is correct.'
  else
    print *, 'Test 2 failed: Initial radius is incorrect.'
  end if

  ! Test 3: Set and check the radius
  radius = 5.0
  if (radius == 5.0) then
    print *, 'Test 3 passed: Radius is correctly set and retrieved.'
  else
    print *, 'Test 3 failed: Radius is incorrectly set or retrieved.'
  end if

end program test_circle