program test_combined
  use, intrinsic :: iso_fortran_env, only: error_unit
  implicit none
  integer :: i, j
  integer, parameter :: n = 100
  integer, dimension(n) :: a

  j = 0
  !$acc parallel loop reduction(+:j) copy(j) copyout(j)
  do i = 1, n
    j = j + 1
  end do
  !$acc end parallel loop

  if (j /= n) then
    write(error_unit, *) "Test failed for Fortran code: expected", n, " but got", j
  else
    write(*, *) "Test passed for Fortran code"
  end if
end program test_combined