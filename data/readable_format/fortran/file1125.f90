! snafu_module.f90
module snafu_mod
  implicit none
contains
  subroutine snafu(i, c1, c2)
    integer, intent(in) :: i
    character(len=:), allocatable :: c1, c2
    allocate(character(len=i) :: c1, c2)
    c1 = ""
    c2 = ""
  end subroutine snafu
end module snafu_mod

! test_snafu.f90
program test_snafu
  use snafu_mod
  implicit none
  character(:), allocatable :: c1, c2
  integer :: i

  i = 10
  call snafu(i, c1, c2)
  if (len(trim(c1)) == 0 .and. len(trim(c2)) == 0) then
    print *, "Fortran Test passed: c1 and c2 are empty."
  else
    print *, "Fortran Test failed: c1 and c2 are not empty."
  endif
end program test_snafu