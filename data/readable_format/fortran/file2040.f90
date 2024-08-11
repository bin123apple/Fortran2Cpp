program testActive
  implicit none
  
  ! Test cases
  if (active(5)) then
    print *, "Test 1 passed: 5 is positive."
  else
    print *, "Test 1 failed: 5 is not positive."
  endif

  if (.not. active(-3)) then
    print *, "Test 2 passed: -3 is not positive."
  else
    print *, "Test 2 failed: -3 is positive."
  endif

  if (.not. active(0)) then
    print *, "Test 3 passed: 0 is not positive."
  else
    print *, "Test 3 failed: 0 is positive."
  endif

contains

  logical function active(e11)
    integer, intent(in) :: e11
    active = e11 > 0
  end function active

end program testActive