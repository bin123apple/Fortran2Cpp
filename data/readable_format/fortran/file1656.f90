! File: mo_column.f90
module mo_column
  implicit none
contains

  function compute_column(t, q, nz, b, nproma, o) result(column_result)
    real, dimension(nz, nproma), intent(in) :: t, q
    integer, intent(in) :: nz, nproma
    real, intent(in) :: b, o
    real, dimension(nz) :: column_result
    integer :: i, j

    do i = 1, nz
      column_result(i) = 0.0
      do j = 1, nproma
        column_result(i) = column_result(i) + ((t(i, j) + q(i, j)) * b + o)
      end do
    end do
  end function compute_column

end module mo_column

program test_mo_column
  use mo_column
  implicit none

  real, dimension(2,2) :: t = reshape([1.0, 2.0, 3.0, 4.0], [2, 2])
  real, dimension(2,2) :: q = reshape([0.5, 1.5, 2.5, 3.5], [2, 2])
  real, dimension(2) :: result
  integer :: nz, nproma
  real :: b, o

  nz = 2
  nproma = 2
  b = 1.0
  o = 0.5

  result = compute_column(t, q, nz, b, nproma, o)
  print *, "Fortran Result:", result

end program test_mo_column