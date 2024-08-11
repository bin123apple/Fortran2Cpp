! calculation_module.f90
module calculation_module
  implicit none
contains
  subroutine compute_values(i, j)
    integer, intent(inout) :: i
    integer, intent(out) :: j
    i = i + 2 + 3
    j = 1 + 2 * 3
    i = (i + 1) * 2
  end subroutine compute_values
end module calculation_module

! test_program.f90
program test_program
  use calculation_module
  implicit none
  integer :: i, j
  
  i = 0  ! Initialize i with a value, matching the C++ version
  call compute_values(i, j)
  
  if (i == 10 .and. j == 7) then
    print *, "Test Passed."
  else
    print *, "Test Failed. i: ", i, " j: ", j
  endif
end program test_program