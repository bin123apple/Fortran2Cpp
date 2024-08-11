module m
  type t
    ! Add members here
  end type t
end module m

program test
  use m
  implicit none

  type(t) :: example

  print *, "Fortran test passed."
end program test