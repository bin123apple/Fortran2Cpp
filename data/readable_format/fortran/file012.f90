module bidon
   implicit none
contains
   function my_size(t)
    integer :: my_size
    integer, intent(in) :: t(:)
    my_size = size(t, 1)
   end function

   function get_pi()
   real :: get_pi
     get_pi = 4.*atan(1.0)
   end function
end module bidon

program test_bidon
  use bidon
  use iso_fortran_env
  implicit none
  integer :: i, s, expected_size
  real :: pi, expected_pi
  integer , allocatable :: a(:)
    
  ! Test for my_size
  a = [1, 2, 3]
  expected_size = 3
  if (my_size(a) == expected_size) then
    print *, "my_size test passed."
  else
    print *, "my_size test failed."
  endif

  ! Test for get_pi
  expected_pi = 3.14159265358979323846
  pi = get_pi()
  if (abs(pi - expected_pi) < 0.00001) then
    print *, "get_pi test passed."
  else
    print *, "get_pi test failed."
  endif
end program test_bidon