module vec3_module
  implicit none

  type :: vec3
    real, dimension(3) :: coords
  end type vec3
end module vec3_module

program test_vec3
  use vec3_module
  implicit none

  type(vec3) :: v1, v2
  integer :: i
  real :: x

  ! Test initialization
  v1 = vec3((/1.0, 2.0, 3.0/))
  v2 = vec3((/4.0, 5.0, 6.0/))

  ! Test accessing coords
  if (v1%coords(1) /= 1.0 .or. v1%coords(2) /= 2.0 .or. v1%coords(3) /= 3.0) then
    print *, "ERROR in v1 initialization"
  end if

  ! Test modifying and accessing coords
  v2%coords(1) = 7.0
  v2%coords(2) = 8.0
  v2%coords(3) = 9.0

  do i = 1, 3
    if (v2%coords(i) /= real(i + 6)) then
      print *, "ERROR in v2 modification"
    end if
  end do

  print *, "All tests passed for Fortran version."

end program test_vec3