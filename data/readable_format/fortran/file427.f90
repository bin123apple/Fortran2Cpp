module m
  type :: t
  end type t
end module m

module global_type
  type :: t_global
  end type t_global
end module global_type

program test
  use m
  use global_type
  implicit none
  
  type(t) :: obj1
  type(t_global) :: obj2
  
  print *, "Fortran test passed."
end program test