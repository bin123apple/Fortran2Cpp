program test_f
  implicit none
  integer :: result, test_val

  ! Test 1: i < 0
  test_val = -5
  result = f(test_val)
  if (result == 999 .and. test_val == 999) then
     print *, "Test 1 passed"
  else
     print *, "Test 1 failed"
  endif

  ! Test 2: i >= 0
  test_val = 5
  result = f(test_val)
  if (result == 6 .and. test_val == 6) then
     print *, "Test 2 passed"
  else
     print *, "Test 2 failed"
  endif

contains

  integer function f(i)
    integer,intent(inout)::i
    if (i.lt.0) then
       i=999
       f=i
       return
    endif
    f=i+1
  end function f

end program test_f