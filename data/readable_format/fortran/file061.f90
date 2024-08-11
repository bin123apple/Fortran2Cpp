! blicpy.f90
subroutine blicpy(ia, ib, n)
  implicit none
  integer, intent(in) :: ia(*), n
  integer, intent(out) :: ib(*)
  integer :: i
  do i = 1, n
     ib(i) = ia(i)
  end do
end subroutine blicpy

program test_blicpy
  implicit none
  integer :: ia(5) = [1, 2, 3, 4, 5]
  integer :: ib(5)
  integer :: ic(1) = [10]
  integer :: id(1)
  integer :: i

  ! Test with multiple-element array
  call blicpy(ia, ib, 5)
  print *, "Multiple-element array copy:"
  do i = 1, 5
     print *, "ib(", i, ") = ", ib(i)
  end do

  ! Test with single-element array
  call blicpy(ic, id, 1)
  print *, "Single-element array copy:"
  print *, "id(1) = ", id(1)

  ! Test with empty array
  print *, "Empty array copy (expected no output):"
  call blicpy(ia, ib, 0)  ! Note: Fortran arrays cannot actually be size 0, so we simulate this scenario
end program test_blicpy