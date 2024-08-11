module segment
  implicit none
contains
  elemental function whichSegment(x, xLower, xUpper, iLower, iUpper) result(i)
    double precision, intent(in) :: x, xLower, xUpper
    integer, intent(in) :: iLower, iUpper
    integer :: i
    if (x <= xLower) then
      i = iLower
    else if (x >= xUpper) then
      i = iUpper
    else
      i = iLower + floor(0.5D0 + (x - xLower) / (xUpper - xLower) * (iUpper - iLower))
    end if
  end function whichSegment
end module segment

program testSegment
  use segment
  implicit none
  integer :: result

  ! Define test scenarios
  result = whichSegment(5.5D0, 1.0D0, 10.0D0, 1, 10)
  print *, "Test 1: Expected 6, Got ", result

  result = whichSegment(1.0D0, 1.0D0, 10.0D0, 1, 10)
  print *, "Test 2: Expected 1, Got ", result

  result = whichSegment(10.0D0, 1.0D0, 10.0D0, 1, 10)
  print *, "Test 3: Expected 10, Got ", result

  result = whichSegment(0.0D0, 1.0D0, 10.0D0, 1, 10)
  print *, "Test 4: Expected 1, Got ", result

  result = whichSegment(11.0D0, 1.0D0, 10.0D0, 1, 10)
  print *, "Test 5: Expected 10, Got ", result
end program testSegment