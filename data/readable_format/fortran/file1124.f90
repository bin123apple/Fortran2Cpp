module m3
  type t
    integer :: value
  end type t
end module m3

program test
  use m3
  implicit none

  type(t) :: obj

  obj%value = 5
  if (obj%value == 5) then
    print *, "Test passed."
  else
    print *, "Test failed."
  endif
end program test