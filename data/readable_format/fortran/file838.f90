module testmod
  implicit none
contains
  function foo(i) result(match)
    character(1) :: match
    integer, intent(in) :: i
    character(1) :: c
    character(1), parameter :: hex_chars(0:15) = &
        (/'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'/)

    c = hex_chars(i)
    if (c .eq. '3') then
      match = 'T' ! True
    else
      match = 'F' ! False
    end if
  end function foo
end module testmod

program test
  use testmod
  implicit none
  integer :: i

  print *, "Fortran Unit Tests"
  do i = 0, 15
    if (foo(i) == 'T') then
      print *, "Test with i=", i, "Passed."
    else
      print *, "Test with i=", i, "Failed."
    end if
  end do
end program test