module m
  use iso_c_binding
  implicit none
  ! Changed variable name to avoid clash
  integer(c_int), save, bind(C, name="a_m") :: a_m = 5
end module m

module n
  use iso_c_binding
  implicit none
  ! Changed variable name to avoid clash
  integer(c_int), save, bind(C, name="a_n") :: a_n = -5
end module n

program prog
  use iso_c_binding
  use m, only: a_m
  use n, only: a_n
  implicit none
  integer(c_int) :: a, b
  
  ! Assign values from modules to local variables
  a = a_m
  b = a_n
  
  print *, "a =", a, "b =", b
  if (a /= 5 .or. b /= -5) call abort()
end program prog