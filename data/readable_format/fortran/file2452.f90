module types_mod
  implicit none
  type xyz_type
    integer :: x
    character(11) :: y
    logical :: z
  end type xyz_type

  type abcdef_type
    integer :: a
    logical :: b
    type(xyz_type) :: c
    integer :: d
    real(4) :: e
    character(11) :: f
  end type abcdef_type
end module types_mod

program main
  use types_mod
  implicit none

  type(xyz_type), dimension(2) :: xyz
  type(abcdef_type) :: abcdef

  xyz(1)%x = 11111
  xyz(1)%y = "hello world"
  xyz(1)%z = .true.
  xyz(2)%x = 0
  xyz(2)%y = "go away"
  xyz(2)%z = .false.

  abcdef%a = 0
  abcdef%b = .true.
  abcdef%c = xyz(1)
  abcdef%d = 3
  abcdef%e = 4.0
  abcdef%f = "kawabanga"

  call test_routine(xyz, abcdef)
end program main

subroutine test_routine(xyz, abcdef)
  use types_mod
  implicit none
  type(xyz_type), dimension(2), intent(in) :: xyz
  type(abcdef_type), intent(in) :: abcdef

  print *, "Testing xyz(1)"
  print *, xyz(1)%x, xyz(1)%y, xyz(1)%z
  print *, "Testing abcdef"
  print *, abcdef%a, abcdef%b, abcdef%c%x, trim(abcdef%c%y), abcdef%c%z, abcdef%d, abcdef%e, trim(abcdef%f)
end subroutine test_routine