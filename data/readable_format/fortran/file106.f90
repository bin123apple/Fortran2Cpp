module c_funloc_tests_3
  implicit none
contains
  function ffunc(j) bind(c)
    use iso_c_binding, only: c_funptr, c_int
    integer(c_int)        :: ffunc
    integer(c_int), value :: j
    ffunc = -17_c_int * j
  end function ffunc
end module c_funloc_tests_3

program test
  use iso_c_binding, only: c_int
  use c_funloc_tests_3, only: ffunc
  implicit none

  integer(c_int) :: result

  ! Test 1
  result = ffunc(13_c_int)
  if (result == -17_c_int * 13_c_int) then
    print *, "Test 1 passed."
  else
    print *, "Test 1 failed."
  end if

  ! Test 2
  result = ffunc(21_c_int)
  if (result == -17_c_int * 21_c_int) then
    print *, "Test 2 passed."
  else
    print *, "Test 2 failed."
  end if
end program test