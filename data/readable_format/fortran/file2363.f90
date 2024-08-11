program main
  type xyz
     integer :: x = 123
  end type xyz

  type(xyz) :: a
  type(xyz) b
  if (a%x.ne.123) stop 1
  if (b%x.ne.123) stop 2
end program main