program test
  implicit none
  call s1
  call s2
  call s3
contains

subroutine s1
  type :: t
    character(1) :: c
  end type
  type(t) :: x
  data x%c /'1'/
  print *, "s1 - x%c: ", x%c
end subroutine s1

subroutine s2
  real :: x1, x2
  integer :: i1, i2
  data x1 /1.0/
  data x2 /-1.0/
  data i1 /1/
  data i2 /-1/
  print *, "s2 - x1: ", x1, " x2: ", x2, " i1: ", i1, " i2: ", i2
end subroutine s2

subroutine s3
  complex :: z1, z2
  data z1 / (1.0, 2.0) /
  data z2 / (-1.0, -2.0) /
  print *, "s3 - z1: ", z1, " z2: ", z2
end subroutine s3

end program test