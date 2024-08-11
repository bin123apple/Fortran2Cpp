program testMyFunction
  use iso_c_binding
  implicit none
  
  real :: f
  integer(c_size_t) :: d
  
  ! Test values
  f = 2.34
  d = 123
  
  call myFunction(f, d)
  
  if (f == 2.34 .and. d == 123) then
     write(*,*) "Test passed."
  else
     write(*,*) "Test failed."
  end if
  
end program testMyFunction

subroutine myFunction(f, d)
  use iso_c_binding
  implicit none
  real, intent(inout) :: f
  integer(c_size_t) :: d
  
  write(*,*) 'f=', f, 'd=', d
end subroutine myFunction