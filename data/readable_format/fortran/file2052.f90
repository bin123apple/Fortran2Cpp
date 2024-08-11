program testCheck
  implicit none

  integer :: iresult, ians, error

  ! Test 1
  iresult = 5
  ians = 5
  error = 0
  call check(iresult, ians, error)
  if (error == 0) then
    print *, "Test 1 passed."
  else
    print *, "Test 1 failed."
  end if

  ! Test 2
  iresult = 3
  ians = 4
  error = 0
  call check(iresult, ians, error)
  if (error == 1) then
    print *, "Test 2 passed."
  else
    print *, "Test 2 failed."
  end if

contains
  subroutine check(iresult, ians, error)
    integer, intent(in) :: iresult, ians
    integer, intent(inout) :: error
    if (iresult /= ians) then
      error = error + 1
    end if
  end subroutine check
end program testCheck